/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:41:21 by svidot            #+#    #+#             */
/*   Updated: 2024/04/08 18:32:52 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

static int	open_semaphore(char *name, sem_t **sem, int value)
{
	sem_unlink(name);
	*sem = sem_open(name, O_CREAT, 0666, value);
	if (*sem == SEM_FAILED)
		return (1);
	return (0);
}

static int	init_philos(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
	{
		philos[i].id = i + 1;
		if (open_semaphore("/sem_last_meal", &philos[i].sem_last_meal, 1))
			return (1);
		if (open_semaphore("/sem_is_satiated", &philos[i].sem_is_satiated, 1))
			return (1);
		if (open_semaphore("/sem_end_needed", &philos[i].sem_end_needed, 1))
			return (1);
	}
	return (0);
}

static int	create_philo_structs(t_data *data, t_philo **philos)
{
	*philos = (t_philo *) ft_calloc(data->n_philo, sizeof(t_philo));
	if (!*philos)
		return (1);
	if (init_philos(data, *philos))
		return (free(*philos), 1);
	return (0);
}

static int	create_data_struct(char *argv[], t_data **data)
{
	*data = (t_data *) ft_calloc(1, sizeof(t_data));
	if (!*data)
		return (1);
	(*data)->n_philo = ft_atoi(*++argv);
	(*data)->death_time = ft_atoi(*++argv);
	(*data)->eat_time = ft_atoi(*++argv);
	(*data)->sleep_time = ft_atoi(*++argv);
	if (*++argv)
		(*data)->max_meals = ft_atoi(*argv);
	if (open_semaphore("/sem_mic", &(*data)->sem_mic, 1))
		return (1);
	if (open_semaphore("/sem_forks", &(*data)->sem_forks, (*data)->n_philo))
		return (1);
	if (open_semaphore("/sem_death", &(*data)->sem_death, 0))
		return (1);
	if (open_semaphore("/sem_death_notice", &(*data)->sem_death_notice, 0))
		return (1);
	return (0);
}

int	setup(char *argv[], t_data **data, t_philo **philos)
{
	if (create_data_struct(argv, data))
		return (1);
	add_exit_struct((void *) *data, DAT);
	if (create_philo_structs(*data, philos))
		return (1);
	add_exit_struct((void *) *philos, PHI);
	return (0);
}
