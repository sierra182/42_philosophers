/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mortuary.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:40:47 by seblin            #+#    #+#             */
/*   Updated: 2024/04/03 11:57:56 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mortuary.h"

int	is_actually_dead(t_philo *philo)
{
	pthread_mutex_t	*mutex;
	struct timeval	actual_time;
	long			delta_last_meal;

	mutex = &philo->last_meal_mutex;
	pthread_mutex_lock(mutex);
	if (gettimeofday(&actual_time, NULL))
		return (pthread_mutex_unlock(mutex), 1);
	delta_last_meal = get_delta_time(&philo->last_meal, &actual_time);
	pthread_mutex_unlock(mutex);
	if (delta_last_meal >= philo->data->death_time)
		return (1);
	return (0);
}

static void	rise_end_needed(t_data *data, t_philo *philos)
{
	pthread_mutex_t	*mutex;	
	int				i;

	i = -1;
	while (++i < data->n_philo)
	{
		mutex = &philos[i].end_needed_mutex;
		pthread_mutex_lock(mutex);
		philos[i].end_needed = 1;
		pthread_mutex_unlock(mutex);
	}
}

static int	is_throwing_up(t_philo *philo)
{
	pthread_mutex_t	*mutex;
	int				is_throwing_up;

	mutex = &philo->is_satiated_mutex;
	pthread_mutex_lock(mutex);
	is_throwing_up = philo->is_satiated;
	pthread_mutex_unlock(mutex);
	return (is_throwing_up);
}

void	mortician(t_data *data, t_philo *philos)
{
	int	trowup_count;
	int	is_throwup;
	int	i;

	while (1)
	{
		i = 0;
		trowup_count = 0;
		while (i < data->n_philo)
		{
			is_throwup = is_throwing_up(&philos[i]);
			if (!is_throwup && is_actually_dead(&philos[i]))
			{
				rise_end_needed(data, philos);
				take_mic(&philos[i], "died\n");
				return ;
			}
			else if (is_throwup)
				trowup_count++;
			if (trowup_count >= data->n_philo)
				return ;
			i++;
		}
		usleep(500);
	}
}
