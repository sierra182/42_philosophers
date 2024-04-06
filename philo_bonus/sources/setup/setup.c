/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:41:21 by svidot            #+#    #+#             */
/*   Updated: 2024/04/06 14:38:45 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

static int	init_philos(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
	{
		philos[i].id = i + 1;
		philos[i].sem_last_meal
			= sem_open("/sem_last_meal", O_CREAT, 0644, 1);
		if (philos[i].sem_last_meal == SEM_FAILED)
			return (1);
		philos[i].sem_is_satiated
			= sem_open("/sem_is_satiated", O_CREAT, 0644, 1);
		if (philos[i].sem_is_satiated == SEM_FAILED)
			return (1);
		philos[i].sem_end_needed
			= sem_open("/sem_end_needed", O_CREAT, 0644, 1);
		if (philos[i].sem_end_needed == SEM_FAILED)
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
	sem_unlink("/sem_mic");
	(*data)->sem_mic 
		= sem_open("/sem_mic", O_CREAT, 0666, 1);
	if ((*data)->sem_mic == SEM_FAILED)	
		return (1);	
	sem_unlink("/sem_forks");
	(*data)->sem_forks
		= sem_open("/sem_forks", O_CREAT, 0666, (*data)->n_philo);
	if ((*data)->sem_forks == SEM_FAILED)
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
