/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:19:18 by seblin            #+#    #+#             */
/*   Updated: 2024/04/06 16:39:03 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "childs.h"

int	is_end_needed(t_philo *philo)
{
	sem_t	*sem_end_needed;
	int		is_end_needed;

	sem_end_needed = philo->sem_end_needed;
	sem_wait(sem_end_needed);
	is_end_needed = philo->end_needed;
	sem_post(sem_end_needed);
	return (is_end_needed);
}

int	take_mic(t_data *data, t_philo *philo, char *str)
{	
	long	time;
	sem_t	*sem_mic;
	
	sem_mic = data->sem_mic;
	sem_wait(sem_mic);
	if (is_end_needed(philo))
		return (sem_post(sem_mic), 1);
	time = get_time_since_start(data);
	if (time < 0)
		return (sem_post(sem_mic), 1);
	printf("%ld ", time);
	printf("%d ", philo->id);
	printf("%s", str);
	sem_post(sem_mic);
	if (is_end_needed(philo))
		return (1);
	return (0);
}

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
			if (philo_routine(data, &philos[i]))
				return (1);		
			return (0);
		}	
	}
//	if (waitpid())
//	sem_close(sem_forks);
//	sem_unlink("/sem_forks");
	return (0);
}
