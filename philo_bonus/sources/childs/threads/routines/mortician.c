/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mortician.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:29:06 by seblin            #+#    #+#             */
/*   Updated: 2024/04/09 17:05:06 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mortician.h"

static int	take_death_mic(t_data *data, t_philo *philo, char *str)
{
	long	time;
	sem_t	*sem_mic;

	sem_mic = data->sem_mic;
	sem_wait(sem_mic);
	time = get_time_since_start(data);
	if (time < 0)
		return (sem_post(sem_mic), 1);
	printf("%ld ", time);
	printf("%d ", philo->id);
	printf("%s", str);
	sem_post(sem_mic);
	return (0);
}

static int	is_actually_dead(t_data *data, t_philo *philo)
{
	sem_t			*sem_last_meal;
	long			delta_last_meal;

	sem_last_meal = philo->sem_last_meal;
	sem_wait(sem_last_meal);
	delta_last_meal = get_time_since_last_meal(philo);
	if (delta_last_meal < 0)
		return (1);
	sem_post(sem_last_meal);
	if (delta_last_meal >= data->death_time)
		return (1);
	return (0);
}

void	*mortician_routine(void *ptr)
{
	sem_t	*sem_death;
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)((void **) ptr)[0];
	philo = (t_philo *)((void **) ptr)[1];
	sem_death = data->sem_death;
	while (1)
	{
		if (is_end_needed(philo))
		{
			//flush_exit_struct();//!include
			//printf("sortie de mortician car end_needed\n");
			return (NULL);
		}
		else if (is_actually_dead(data, philo) && !is_end_needed(philo))
		{
			take_death_mic(data, philo, "died\n");
			sem_post(sem_death);
			return (NULL);
			//flush_exit_struct();
			//exit(0);
		}
		//usleep(500);
	}
}
