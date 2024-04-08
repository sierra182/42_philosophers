/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:58:56 by seblin            #+#    #+#             */
/*   Updated: 2024/04/08 11:37:13 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "x_philo_struct.h"
# include <stdlib.h>
# include <unistd.h>

long	get_time_since_start(t_data *data);
static int	take_death_mic(t_data *data, t_philo *philo, char *str)
{
	long	time;
	sem_t	*sem_mic;
	
	sem_mic = data->sem_mic;	
	sem_wait(sem_mic);	
	time = get_time_since_start(data);
	if (time < 0)
		return (sem_post(sem_mic), 1);
	printf("%ld ", time);
	printf("%d ", philo->id);
	printf("%s", str);
	sem_post(sem_mic);
	return (0);
}
long	get_time_since_last_meal(t_philo *philo);

int	is_actually_dead(t_data *data, t_philo *philo)
{
	sem_t			*sem_last_meal;
	long			delta_last_meal;
	struct timeval	actual_time;

	sem_last_meal = philo->sem_last_meal;
	sem_wait(sem_last_meal);	
	delta_last_meal = get_time_since_last_meal(philo);
	if (delta_last_meal < 0)
		return (1);
	sem_post(sem_last_meal);
	if (delta_last_meal >= data->death_time)
		return (1);
	return (0);
}

void	*mortician_routine(void *ptr)
{	
	sem_t	*sem_death;
	t_data	*data;
	t_philo	*philo;
	
	data = (t_data *) ((void **) ptr)[0];
	philo = (t_philo *) ((void **) ptr)[1];
	sem_death = data->sem_death;
	while (1)
	{	
		if (is_actually_dead(data, philo))
		{
			take_death_mic(data, philo, "died\n");
			sem_post(sem_death);
			exit(0);	
		}
		usleep(500);
	}
}
void	*is_end_routine(void *ptr)
{
	t_data	*data;
	sem_t	*sem_death_notice;

	data = (t_data *) ptr;
	sem_death_notice = data->sem_death_notice;	
	sem_wait(sem_death_notice);
	exit(0);
}
void	*philo_routine(void *ptr);
int	create_threads(t_data *data, t_philo *philo)
{
	pthread_t	tid_philo;
	pthread_t	tid_mortician;
	pthread_t	tid_is_end;

	pthread_create
		(&tid_philo, NULL, philo_routine, (void *[]) {data, philo});	
	pthread_create
		(&tid_mortician, NULL, mortician_routine, (void *[]) {data, philo});
	pthread_create
		(&tid_is_end, NULL, is_end_routine, (void *) data);
	pthread_join(tid_philo, NULL);
	pthread_join(tid_mortician, NULL);
	pthread_join(tid_is_end, NULL);
}