/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:19:18 by seblin            #+#    #+#             */
/*   Updated: 2024/04/05 21:40:37 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "childs.h"

#include <fcntl.h>

int	take_mic(t_data *data, char *str)
{	
	long	time;

	mutex = &philo->data->microphone_mutex;
	sem_wait(sem_mic);
	if (is_end_needed(philo))
		return (sem_post(sem_mic), 1);
	time = get_time_since_start(philo);
	if (time < 0)
		return (sem_post(sem_mic), 1);
	printf("%ld ", time);
	printf("%d ", philo->id);
	printf("%s", str);
	sem_post(sem_mic);;
	if (is_end_needed(philo))
		return (1);
	return (0);
}

int	take_death_mic(t_philo *philo, char *str)
{
	long	time;

	mutex = &philo->data->microphone_mutex;
	sem_wait(sem_mic);	
	time = get_time_since_start(philo);
	if (time < 0)
		return (sem_post(sem_mic), 1);
	printf("%ld ", time);
	printf("%d ", philo->id);
	printf("%s", str);
	sem_post(sem_mic);;
	if (is_end_needed(philo))
		return (1);
	return (0);
}

int	make_childs(t_data *data)
{
	int		i;
	pid_t	pid;
	sem_t	*sem_forks;

	sem_forks = sem_open("/sem_forks", O_CREAT, 0644, data->n_philo);
	if (sem_forks == SEM_FAILED)
		return (1);
	i = -1;
	while (++i < data->n_philo)
	{
		pid = fork();
		if (pid < 0)
			return (1);
		if (!pid)
		{				
			philosopher_routine();		
			return (0);
		}
		else
		{
			
		}
	}
	if (waitpid())
	sem_close(sem_forks);
	sem_unlink("/sem_forks");
	return (0);
}
