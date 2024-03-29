/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mortuary.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:40:47 by seblin            #+#    #+#             */
/*   Updated: 2024/03/29 21:42:57 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mortuary.h"

int	is_actually_dead(t_philo *philo)
{
	struct timeval	actual_time;
	long			delta_last_meal;

	if (!gettimeofday(&actual_time, NULL))
	{
		delta_last_meal = get_delta_time(&philo->last_meal, &actual_time);
		if (delta_last_meal >= philo->data->death_time)			
			return (1);		
		return (0);
	}
	else
		return (-1);
}

void	mortician(t_data *data, t_philo *philos)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->n_philo)
		{
			if (is_actually_dead(&philos[i]))
			{
				data->end_needed = 1;			
				take_mic(&philos[i], "died\n");			
				return ;
			}
		}
	}
}
