/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:17:45 by seblin            #+#    #+#             */
/*   Updated: 2024/03/29 15:03:10 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eat.h"

static int	even_philo_get_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->rght_fork->mutex);
	if (philo->data->end_needed)
	{
		pthread_mutex_unlock(&philo->rght_fork->mutex);
		return (1);
	}
	if (iam_actually_dead(philo))
	{
		pthread_mutex_unlock(&philo->rght_fork->mutex);
		return (say_on_shared_microphone(philo, "died\n"), 1);
	}
	if (say_on_shared_microphone(philo, "has taken a fork\n"))
	{
		pthread_mutex_unlock(&philo->rght_fork->mutex);
		return (1);
	}
	pthread_mutex_lock(&philo->lft_fork->mutex);
	if (philo->data->end_needed)
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);
		pthread_mutex_unlock(&philo->rght_fork->mutex);
		return (1);
	}
	if (iam_actually_dead(philo))
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);
		pthread_mutex_unlock(&philo->rght_fork->mutex);
		return (say_on_shared_microphone(philo, "died\n"), 1);
	}
	if (say_on_shared_microphone(philo, "has taken a fork\n"))
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);
		pthread_mutex_unlock(&philo->rght_fork->mutex);
		return (1);
	}
}

static int	odd_philo_get_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->lft_fork->mutex);
	if (philo->data->end_needed)
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);
		return (1);
	}
	if (iam_actually_dead(philo))
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);
		return (say_on_shared_microphone(philo, "died\n"), 1);
	}
	say_on_shared_microphone(philo, "has taken a fork\n");
	pthread_mutex_lock(&philo->rght_fork->mutex);
	if (philo->data->end_needed)
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);
		pthread_mutex_unlock(&philo->rght_fork->mutex);
		return (1);
	}
	if (iam_actually_dead(philo))
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);
		pthread_mutex_unlock(&philo->rght_fork->mutex);
		return (say_on_shared_microphone(philo, "died\n"), 1);
	}
	if (say_on_shared_microphone(philo, "has taken a fork\n"))
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);
		pthread_mutex_unlock(&philo->rght_fork->mutex);
		return (1);
	}
}

static void	update_last_meal(t_philo *philo)
{
	gettimeofday(&philo->last_meal, NULL);
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
		{
			return (1);
		}
	}
	else if (even_philo_get_forks(philo))
		return (1);
	update_last_meal(philo);
	if (iam_actually_dead(philo))
		return (say_on_shared_microphone(philo, "died\n"), 1);
	say_on_shared_microphone(philo, "is eating\n");
	usleep(philo->data->eat_time * 1000);
	pthread_mutex_unlock(&philo->lft_fork->mutex);
	pthread_mutex_unlock(&philo->rght_fork->mutex);
	return (0);
}
