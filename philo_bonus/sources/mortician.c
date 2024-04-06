/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mortician.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:54:29 by seblin            #+#    #+#             */
/*   Updated: 2024/04/06 16:33:58 by seblin           ###   ########.fr       */
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

int	is_actually_dead(t_data *data, t_philo *philo)
{
	sem_t			*sem_last_meal;
	long			delta_last_meal;
	struct timeval	actual_time;

	sem_last_meal = philo->sem_last_meal;
	sem_wait(sem_last_meal);	
	delta_last_meal = get_time_since_last_meal(philo);
	if (delta_last_meal < 0)
		return (1);// sempost!!
	sem_post(sem_last_meal);
	if (delta_last_meal >= data->death_time)
		return (1);
	return (0);
}

static void	rise_end_needed(t_data *data, t_philo *philos)
{
	sem_t	*sem_end_needed;	
	int		i;

	i = -1;
	while (++i < data->n_philo)
	{
		sem_end_needed = philos[i].sem_end_needed;
		sem_wait(sem_end_needed);
		philos[i].end_needed = 1;
		sem_post(sem_end_needed);
	}
}

static int	is_throwing_up(t_philo *philo)
{
	sem_t	*sem_is_satiated;
	int		is_throwing_up;

	sem_is_satiated = philo->sem_is_satiated;
	sem_wait(sem_is_satiated);
	is_throwing_up = philo->is_satiated;
	sem_post(sem_is_satiated);
	return (is_throwing_up);
}

int	mortician(t_data *data, t_philo *philos)
{
	int	trowup_count;
	int	is_throwup;
	int	i;

	while (1)
	{
		i = -1;
		trowup_count = 0;
		while (++i < data->n_philo)
		{
			is_throwup = is_throwing_up(&philos[i]);
			if (!is_throwup && is_actually_dead(data, &philos[i]))
			{
				rise_end_needed(data, philos);
				take_death_mic(data, &philos[i], "died\n");
				return (1);
			}
			else if (is_throwup)
				trowup_count++;
			if (trowup_count >= data->n_philo)
				return (1);		
		}
		usleep(500);
	}
	return (0);
}
