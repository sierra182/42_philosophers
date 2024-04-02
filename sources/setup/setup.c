/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:16:26 by seblin            #+#    #+#             */
/*   Updated: 2024/04/02 09:13:34 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

t_philo	*create_philos(t_data *data)
{
	t_philo	*philos;
	t_fork	*forks;

	forks = (t_fork *) ft_calloc(data->n_philo, sizeof(t_fork));
	if (!forks)
		return (NULL);
	if (init_forks(data, forks))
		return (free(forks), NULL);
	add_exit_struct((void *) forks, FRK);
	philos = (t_philo *) ft_calloc(data->n_philo, sizeof(t_philo));
	if (!philos)
		return (NULL);
	if (init_philos(data, philos, forks))
		return (free(philos), NULL);
	add_exit_struct((void *) philos, PHI);
	return (philos);
}

int	start_timer(t_data *data, t_philo *philos)
{
	pthread_mutex_t	*mutex;

	mutex = &data->is_ready_mutex;
	pthread_mutex_lock(mutex);
	if (gettimeofday(&data->start_time, NULL))
		return (pthread_mutex_unlock(mutex), 1);
	init_lastmeal_philos(data, philos);
	data->is_ready = 1;
	pthread_mutex_unlock(mutex);
	return (0);
}

pthread_t	*create_threads(t_data *data, t_philo *philos)
{
	pthread_t	*tids;
	int			i;

	tids = (pthread_t *) ft_calloc(data->n_philo, sizeof(pthread_t));
	if (!tids)
		return (NULL);
	add_exit_struct((void *) tids, TID);
	i = -1;
	if (start_timer(data, philos))
		return (NULL);
	while (++i < data->n_philo)
		if (pthread_create(&tids[i], NULL, philo_routine, (void *) &philos[i]))
			return (NULL);
	return (tids);
}

t_data	*create_data_struct(char *argv[])
{
	t_data	*data;

	data = (t_data *) ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->n_philo = ft_atoi(*++argv);
	data->death_time = ft_atoi(*++argv);
	data->eat_time = ft_atoi(*++argv);
	data->sleep_time = ft_atoi(*++argv);
	if (*++argv)
		data->max_meals = ft_atoi(*argv);
	if (pthread_mutex_init(&data->microphone_mutex, NULL))
		return (free(data), (NULL));
	if (pthread_mutex_init(&data->is_ready_mutex, NULL))
		return (pthread_mutex_destroy(&data->microphone_mutex),
			free(data), (NULL));
	add_exit_struct((void *) data, DAT);
	return (data);
}
