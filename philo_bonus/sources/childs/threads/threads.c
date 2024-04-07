/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:58:56 by seblin            #+#    #+#             */
/*   Updated: 2024/04/07 22:08:16 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "x_philo_struct.h"

void	*mortician_routine(void *ptr)
{
	
}
void	*is_end_routine(void *ptr)
{
	
}

int	create_threads(t_data *data, t_philo *philo)
{
	pthread_t	tid_philo;
	pthread_t	tid_mortician;
	pthread_t	tid_is_end;
	
	tid_philo = pthread_create
		(&tid_philo, NULL, philo_routine, (void *) {&data, &philo});	
	tid_mortician = pthread_create
		(&tid_mortician, NULL, mortician_routine, (void *) {&data, &philo});
	tid_is_end = pthread_create(&tid_is_end, NULL, );	
}