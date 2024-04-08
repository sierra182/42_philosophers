/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:58:56 by seblin            #+#    #+#             */
/*   Updated: 2024/04/08 19:43:44 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads.h"

int	is_end_needed(t_philo *philo)
{
	sem_t	*sem_end_needed;
	int		is_end_needed;

	sem_end_needed = philo->sem_end_needed;
	sem_wait(sem_end_needed);
	is_end_needed = philo->end_needed;
	sem_post(sem_end_needed);
	return (is_end_needed);
}

static void	*is_end_routine(void *ptr)
{
	sem_t	*sem_death_notice;
	sem_t	*sem_end_needed;
	t_philo	*philo;
	t_data	*data;

	data = (t_data *)((void **) ptr)[0];
	philo = (t_philo *)((void **) ptr)[1];
	sem_death_notice = data->sem_death_notice;
	sem_end_needed = philo->sem_end_needed;
	sem_wait(sem_death_notice);
	sem_wait(sem_end_needed);	
	philo->end_needed = 1;
	sem_post(sem_end_needed);
	exit(0);
}

int	take_mic(t_data *data, t_philo *philo, char *str)
{
	long	time;
	sem_t	*sem_mic;

	sem_mic = data->sem_mic;
	sem_wait(sem_mic);
	if (is_end_needed(philo))
		return (sem_post(sem_mic), 1);
	time = get_time_since_start(data);
	if (time < 0)
		return (sem_post(sem_mic), 1);
	printf("%ld ", time);
	printf("%d ", philo->id);
	printf("%s", str);
	sem_post(sem_mic);
	if (is_end_needed(philo))
		return (1);
	return (0);
}

int	create_threads(t_data *data, t_philo *philo)
{
	pthread_t	tid_philo;
	pthread_t	tid_mortician;
	pthread_t	tid_is_end;

	pthread_create(&tid_philo, NULL,
		philo_routine, (void *[]){data, philo});
	pthread_create(&tid_mortician, NULL,
		mortician_routine, (void *[]){data, philo});
	pthread_create(&tid_is_end, NULL,
		is_end_routine, (void *[]){data, philo});
	pthread_join(tid_philo, NULL);
	pthread_join(tid_mortician, NULL);
	pthread_join(tid_is_end, NULL);
	return (0);
}
