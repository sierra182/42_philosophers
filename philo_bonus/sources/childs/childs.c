/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:19:18 by seblin            #+#    #+#             */
/*   Updated: 2024/04/06 11:22:59 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "childs.h"

int	take_mic(t_data *data, t_philo *philo, char *str)
{	
	long	time;
	sem_t	*sem_mic;
	
	sem_mic = data->sem_mic;
	sem_wait(sem_mic);
	// if (is_end_needed(philo))
	// 	return (sem_post(sem_mic), 1);
	time = get_time_since_start(data);
	if (time < 0)
		return (sem_post(sem_mic), 1);
	printf("%ld ", time);
	printf("%d ", philo->id);
	printf("%s", str);
	sem_post(sem_mic);
	// if (is_end_needed(philo))
	// 	return (1);
	return (0);
}

// int	take_death_mic(t_data *data, t_philo *philo, char *str)
// {
// 	long	time;
// 	sem_t	*sem_mic;
	
// 	sem_mic = data->sem_mic;	
// 	sem_wait(sem_mic);	
// 	time = get_time_since_start(data);
// 	if (time < 0)
// 		return (sem_post(sem_mic), 1);
// 	printf("%ld ", time);
// 	printf("%d ", philo->id);
// 	printf("%s", str);
// 	sem_post(sem_mic);
// 	// if (is_end_needed(philo))
// 	// 	return (1);
// 	return (0);
// }

int	make_childs(t_data *data, t_philo *philos)
{
	int		i;
	pid_t	pid;

	i = -1;
	while (++i < data->n_philo)
	{
		pid = fork();
		if (pid < 0)
			return (1);
		if (!pid)
		{				
			philo_routine(data, &philos[i]);		
			return (0);
		}
		else
		{
			
		}
	}
//	if (waitpid())
//	sem_close(sem_forks);
//	sem_unlink("/sem_forks");
	return (0);
}
