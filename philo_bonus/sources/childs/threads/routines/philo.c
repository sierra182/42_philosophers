/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:37:50 by seblin            #+#    #+#             */
/*   Updated: 2024/04/09 14:50:48 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	update_last_meal(t_philo *philo)
{
	sem_t	*sem_last_meal;

	sem_last_meal = philo->sem_last_meal;
	sem_wait(sem_last_meal);
	gettimeofday(&philo->last_meal, NULL);
	sem_post(sem_last_meal);
	philo->n_meal++;	
}

static int	ph_eat(t_data *data, t_philo *philo)
{
	sem_t	*sem_forks;

	sem_forks = data->sem_forks;
	sem_wait(sem_forks);
	if (is_end_needed(philo) || take_mic(data, philo, "has taken a fork\n"))
		return (1);
	sem_wait(sem_forks);
	if (is_end_needed(philo) || take_mic(data, philo, "has taken a fork\n"))
		return (1);
	if (take_mic(data, philo, "is eating\n"))
		return (1);
	update_last_meal(philo);
	usleep(data->eat_time * 1000);
	sem_post(sem_forks);
	sem_post(sem_forks);
	if (data->max_meals && philo->n_meal >= data->max_meals)
	{
		flush_exit_struct();
		exit(0);	
	}
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

void	*philo_routine(void *ptr)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)((void **) ptr)[0];
	philo = (t_philo *)((void **) ptr)[1];
	while (1)
	{
		if (is_end_needed(philo) || ph_eat(data, philo))
			break ;			
		if (is_end_needed(philo) || ph_sleep(data, philo))
			break ;
		if (is_end_needed(philo) || ph_think(data, philo))
			break ;
	}
	//flush_exit_struct();
	return (NULL);
}
