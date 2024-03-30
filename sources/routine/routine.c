/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:37:50 by seblin            #+#    #+#             */
/*   Updated: 2024/03/30 11:40:56 by seblin           ###   ########.fr       */
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

is_ready_to_start_dinning()
{
	
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (!philo->data->is_ready)
		;
	while (1)
	{
		if (philo->data->end_needed)
			break ;
		if (philo_eat(philo))
			break ;
		if (philo->data->end_needed)
			break ;
		philo_sleep(philo);
		if (philo->data->end_needed)
			break ;
		philo_think(philo);
	}
	return (NULL);
}
