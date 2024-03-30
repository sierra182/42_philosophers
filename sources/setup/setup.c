/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:16:26 by seblin            #+#    #+#             */
/*   Updated: 2024/03/30 11:18:39 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

static void	init_forks(t_data *data, t_fork *forks)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
		pthread_mutex_init(&forks[i++].mutex, NULL);
}

static void	init_philos(t_data *data, t_philo *philos, t_fork *forks)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		philos[i].id = i + 1;
		philos[i].lft_fork = &forks[i];
		philos[i].rght_fork = &forks[(i + 1) % data->n_philo];
		philos[i].data = data;
		i++;
	}
}
static void	init_lastmeal_philos(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->n_philo)			
		philos[i++].last_meal = data->start_time;	
}
t_philo	*create_philos(t_data *data)
{
	t_philo	*philos;
	t_fork	*forks;

	forks = (t_fork *) ft_calloc(data->n_philo, sizeof(t_fork));
	if (!forks)		
		return (NULL);
	add_exit_struct((void *) forks, FRK);	
	philos = (t_philo *) ft_calloc(data->n_philo, sizeof(t_philo));
	if (!philos)
		return (NULL);
	add_exit_struct((void *) philos, PHI);
	init_forks(data, forks);
	init_philos(data, philos, forks);
	return (philos);
}
static int	init_start_time(t_data *data)
{
	return (gettimeofday(&data->start_time, NULL));
}

int	start_timer(t_data *data, t_philo *philos)
{
	if (init_start_time(data))
		return (1);
	init_lastmeal_philos(data, philos);
	data->is_ready = 1;
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
	while (++i < data->n_philo)	
		pthread_create(&tids[i], NULL, philo_routine, (void *) &philos[i]);	
	if (start_timer(data, philos))
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
		data->n_cycle = ft_atoi(*argv);	
	if (pthread_mutex_init(&data->microphone_mutex, NULL))
		return (free(data), (NULL));
	add_exit_struct((void *) data, DAT);
	return (data);
}
