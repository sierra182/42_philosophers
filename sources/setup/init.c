/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:52:33 by seblin            #+#    #+#             */
/*   Updated: 2024/03/30 19:23:47 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int	init_forks(t_data *data, t_fork *forks)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
		if (pthread_mutex_init(&forks[i++].mutex, NULL))
			return (1);
	return (0);
}

int	init_philos(t_data *data, t_philo *philos, t_fork *forks)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		philos[i].id = i + 1;
		philos[i].lft_fork = &forks[i];
		philos[i].rght_fork = &forks[(i + 1) % data->n_philo];
		philos[i].data = data;
		if (pthread_mutex_init(&philos[i].is_satiated_mutex, NULL))
			return (1);
		i++;
	}
	return (0);
}

void	init_lastmeal_philos(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
		philos[i++].last_meal = data->start_time;
}
