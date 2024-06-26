/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:17:45 by seblin            #+#    #+#             */
/*   Updated: 2024/04/03 20:45:53 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eat.h"

static int	odd_philo_get_forks(t_philo *philo)
{
	usleep(2000);
	pthread_mutex_lock(&philo->rght_fork->mutex);
	if (is_end_needed(philo) || take_mic(philo, "has taken a fork\n"))
	{
		pthread_mutex_unlock(&philo->rght_fork->mutex);
		return (1);
	}
	pthread_mutex_lock(&philo->lft_fork->mutex);
	if (is_end_needed(philo) || take_mic(philo, "has taken a fork\n"))
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);
		pthread_mutex_unlock(&philo->rght_fork->mutex);
		return (1);
	}
	return (0);
}

static int	even_philo_get_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->lft_fork->mutex);
	if (is_end_needed(philo) || take_mic(philo, "has taken a fork\n"))
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);
		return (1);
	}
	pthread_mutex_lock(&philo->rght_fork->mutex);
	if (is_end_needed(philo) || take_mic(philo, "has taken a fork\n"))
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);
		pthread_mutex_unlock(&philo->rght_fork->mutex);
		return (1);
	}
	return (0);
}

static void	update_last_meal(t_philo *philo)
{
	pthread_mutex_t	*mutex;

	mutex = &philo->last_meal_mutex;
	pthread_mutex_lock(mutex);
	gettimeofday(&philo->last_meal, NULL);
	pthread_mutex_unlock(mutex);
	philo->n_meal++;
}

static int	is_odd(t_philo *philo)
{
	return (philo->id % 2);
}

int	philo_eat(t_philo *philo)
{
	if (is_odd(philo))
	{
		if (odd_philo_get_forks(philo))
			return (1);
	}
	else if (even_philo_get_forks(philo))
		return (1);
	if (take_mic(philo, "is eating\n"))
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);
		pthread_mutex_unlock(&philo->rght_fork->mutex);
		return (1);
	}
	update_last_meal(philo);
	usleep(philo->data->eat_time * 1000);
	pthread_mutex_unlock(&philo->lft_fork->mutex);
	pthread_mutex_unlock(&philo->rght_fork->mutex);
	return (0);
}
