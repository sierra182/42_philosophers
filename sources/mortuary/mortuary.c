/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mortuary.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:40:47 by seblin            #+#    #+#             */
/*   Updated: 2024/03/30 19:13:25 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mortuary.h"

int	is_actually_dead(t_philo *philo)
{
	struct timeval	actual_time;
	long			delta_last_meal;

	if (!gettimeofday(&actual_time, NULL))
	{
		delta_last_meal = get_delta_time(&philo->last_meal, &actual_time);
		if (delta_last_meal >= philo->data->death_time)
			return (1);
		return (0);
	}
	else
		return (-1);
}

static void	rise_end_needed(t_data *data)
{
	pthread_mutex_t	*mutex;

	mutex = &data->end_needed_mutex;
	pthread_mutex_lock(mutex);
	data->end_needed = 1;
	pthread_mutex_unlock(mutex);
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
	int	i;
	int	trowing_up;

	while (1)
	{
		i = 0;
		trowing_up = 0;
		while (i < data->n_philo)
		{
			if (is_actually_dead(&philos[i])
				&& !is_throwing_up(&philos[i]))
			{
				rise_end_needed(data);
				take_mic(&philos[i], "died\n");
				return ;
			}
			else if (is_throwing_up(&philos[i]))
				trowing_up++;
			if (trowing_up >= data->n_philo)
				return ;
		}
	}
}
