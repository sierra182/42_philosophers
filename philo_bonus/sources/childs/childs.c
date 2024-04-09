/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:19:18 by seblin            #+#    #+#             */
/*   Updated: 2024/04/09 08:16:05 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "childs.h"

static void	init_lastmeal_philos(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
		philos[i++].last_meal = data->start_time;
}

static int	start_timer(t_data *data, t_philo *philos)
{
	if (gettimeofday(&data->start_time, NULL))
		return (1);
	init_lastmeal_philos(data, philos);
	return (0);
}

static int	is_odd(t_philo *philo)
{
	return (philo->id % 2);
}

int	make_childs(t_data *data, t_philo *philos)
{
	int		i;
	pid_t	pid;

	start_timer(data, philos);
	i = -1;
	while (++i < data->n_philo)
	{
		pid = fork();
		if (pid < 0)
			return (1);
		if (!pid)
		{
			if (is_odd(&philos[i]))
				usleep(2000);
			if (create_threads(data, &philos[i]))
				return (1);
			exit(0);
		}
	}
	return (0);
}
