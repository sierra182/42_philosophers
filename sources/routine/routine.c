/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:37:50 by seblin            #+#    #+#             */
/*   Updated: 2024/03/30 13:27:59 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

static void	philo_think(t_philo *philo)
{
	take_mic(philo, "is thinking\n");
}

static void	philo_sleep(t_philo *philo)
{
	if (take_mic(philo, "is sleeping\n"))
		return ;
	usleep(philo->data->sleep_time * 1000);
}

int	is_ready_to_start_dinning(t_philo *philo)
{	
	pthread_mutex_t	*mutex;
	int				is_ready;
	
	mutex = &philo->data->is_ready_mutex;
	pthread_mutex_lock(mutex);
	is_ready = philo->data->is_ready;
	pthread_mutex_unlock(mutex);
	return (is_ready);	
}

int	is_end_needed(t_philo *philo)
{
	pthread_mutex_t	*mutex;
	int				is_end_needed;
	
	mutex = &philo->data->end_needed_mutex;
	pthread_mutex_lock(mutex);
	is_end_needed = philo->data->end_needed;
	pthread_mutex_unlock(mutex);
	return (is_end_needed);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (!is_ready_to_start_dinning(philo))
		;
	while (1)
	{
		if (is_end_needed(philo))
			break ;
		if (philo_eat(philo))
			break ;
		if (is_end_needed(philo))
			break ;
		philo_sleep(philo);
		if (is_end_needed(philo))
			break ;
		philo_think(philo);
	}
	return (NULL);
}
