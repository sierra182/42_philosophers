/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:42:12 by seblin            #+#    #+#             */
/*   Updated: 2024/03/29 13:08:42 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"

long	get_delta_time(struct timeval *time_a, struct timeval *time_b)
{
	long			delta_sec;
	long 			delta_microsec;

	delta_sec = time_b->tv_sec - time_a->tv_sec;
	delta_microsec = time_b->tv_usec - time_a->tv_usec;
	if (delta_microsec < 0)
	{
		delta_sec--;
		delta_microsec += 1000000;
	}
	return (delta_sec * 1000 + delta_microsec / 1000);
}

long	get_time_since_start(t_philo *philo)
{
	struct timeval	start_time;
	struct timeval	actual_time;

	start_time = philo->data->start_time;
	if (!gettimeofday(&actual_time, NULL))	
		return (get_delta_time(&start_time, &actual_time));	
	else
		return (-1);
}
