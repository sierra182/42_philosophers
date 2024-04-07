/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:37:50 by seblin            #+#    #+#             */
/*   Updated: 2024/04/06 15:53:27 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

// static void	philo_sleep(t_philo *philo)
// {
// 	if (take_mic(philo, "is sleeping\n"))
// 		return ;
// 	usleep(philo->data->sleep_time * 1000);
// }

// static int	is_ready_to_start_dinning(t_philo *philo)
// {
// 	pthread_mutex_t	*mutex;
// 	int				is_ready;

// 	mutex = &philo->data->is_ready_mutex;
// 	pthread_mutex_lock(mutex);
// 	is_ready = philo->data->is_ready;
// 	pthread_mutex_unlock(mutex);
// 	return (is_ready);
// }

// int	is_end_needed(t_philo *philo)
// {
// 	pthread_mutex_t	*mutex;
// 	int				is_end_needed;

// 	mutex = &philo->end_needed_mutex;
// 	pthread_mutex_lock(mutex);
// 	is_end_needed = philo->end_needed;
// 	pthread_mutex_unlock(mutex);
// 	return (is_end_needed);
// }

// static int	is_satiated(t_philo *philo)
// {
// 	pthread_mutex_t	*mutex;
// 	int				is_satiated;

// 	mutex = &philo->is_satiated_mutex;
// 	is_satiated = philo->data->max_meals
// 		&& philo->n_meal >= philo->data->max_meals;
// 	if (is_satiated)
// 	{
// 		pthread_mutex_lock(mutex);
// 		philo->is_satiated = 1;
// 		pthread_mutex_unlock(mutex);
// 	}
// 	return (is_satiated);
// }

// int	is_odd(t_philo *philo);

// void	*philo_routine(void *arg)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *) arg;
// 	while (!is_ready_to_start_dinning(philo))
// 		;
// 	while (1)
// 	{
// 		if (is_end_needed(philo))
// 			break ;
// 		if (philo_eat(philo))
// 			break ;
// 		if (is_end_needed(philo) || is_satiated(philo))
// 			break ;
// 		philo_sleep(philo);
// 		if (is_end_needed(philo))
// 			break ;
// 		take_mic(philo, "is thinking\n");
// 	}
// 	return (NULL);
// }

static int	ph_eat(t_data *data, t_philo *philo)
{
	sem_t	*sem_forks;
	
	sem_forks = data->sem_forks;
	sem_wait(sem_forks);
	sem_wait(sem_forks);
	if (take_mic(data, philo, "is eating\n"))
		return (1);// sem_post * 2
	usleep(data->eat_time * 1000);
	sem_post(sem_forks);
	sem_post(sem_forks);
	return (0);
}

static int	ph_sleep(t_data *data, t_philo *philo)
{
	if (take_mic(data, philo, "is sleeping\n"))
		return (1);
	usleep(data->sleep_time * 1000);
	return (0);
}

static int	ph_think(t_data *data, t_philo *philo)
{
	if (take_mic(data, philo, "is thinking\n"))
		return (1);
	return (0);
}

int	philo_routine(t_data *data, t_philo *philo)
{
	while (1)
	{ 
		if (ph_eat(data, philo))
			return (1);
		if (ph_sleep(data, philo))
			return (1);
		if (ph_think(data, philo))
			return (1);
	}
	return (0);
}