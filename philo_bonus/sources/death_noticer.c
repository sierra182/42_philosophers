/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_noticer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:54:29 by seblin            #+#    #+#             */
/*   Updated: 2024/04/08 14:34:49 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "death_noticer.h"

void	*wait_death(void *ptr)
{
	t_philo	*philos;
	t_data	*data;
	int		i;

	i = -1;
	data = (t_data *) ptr;
	sem_wait(data->sem_death);	
	printf("die arrive\n");
	while (++i < data->n_philo)			
		sem_post(data->sem_death_notice);
	return (0);
}

#include <pthread.h>
int	mortician(t_data *data, t_philo *philos)
{	
	pthread_t tid;

	if (pthread_create(&tid, NULL, wait_death, (void *) data))
		return (1);	
	pthread_join(tid, NULL);
	return (0);
}
