/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mortician.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:54:29 by seblin            #+#    #+#             */
/*   Updated: 2024/04/07 21:29:34 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mortician.h"

// static int	take_death_mic(t_data *data, t_philo *philo, char *str)
// {
// 	long	time;
// 	sem_t	*sem_mic;
	
// 	sem_mic = data->sem_mic;	
// 	sem_wait(sem_mic);	
// 	time = get_time_since_start(data);
// 	if (time < 0)
// 		return (sem_post(sem_mic), 1);
// 	printf("%ld ", time);
// 	printf("%d ", philo->id);
// 	printf("%s", str);
// 	sem_post(sem_mic);
// 	return (0);
// }

// int	is_actually_dead(t_data *data, t_philo *philo)
// {
// 	sem_t			*sem_last_meal;
// 	long			delta_last_meal;
// 	struct timeval	actual_time;

// 	sem_last_meal = philo->sem_last_meal;
// 	sem_wait(sem_last_meal);	
// 	delta_last_meal = get_time_since_last_meal(philo);
// 	if (delta_last_meal < 0)
// 		return (1);// sempost!!
// 	sem_post(sem_last_meal);
// 	if (delta_last_meal >= data->death_time)
// 		return (1);
// 	return (0);
// }

void	*wait_death(void *ptr)
{
	t_philo	*philos;
	t_data	*data;
	int		i;

	i = -1;
	data = (t_data *) ptr;
	sem_wait(data->sem_death);	
	while (++i < data->n_philo)			
		sem_post(data->sem_death_notice);
	return (0);
}

#include <pthread.h>
int	mortician(t_data *data, t_philo *philos)
{	
	pthread_t tid;
	
	if (pthread_create(&tid, NULL, wait_death, (void *) data))
		return (1);
	return (0);
}
