/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_noticer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:54:29 by seblin            #+#    #+#             */
/*   Updated: 2024/04/08 18:11:58 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "death_noticer.h"

void	*wait_death(void *ptr)
{
	t_data	*data;
	int		i;

	i = -1;
	data = (t_data *) ptr;
	sem_wait(data->sem_death);
	while (++i < data->n_philo)
		sem_post(data->sem_death_notice);
	return (NULL);
}

int	death_noticer(t_data *data)
{
	pthread_t tid;

	if (pthread_create(&tid, NULL, wait_death, (void *) data))
		return (1);
	pthread_detach(tid);
	return (0);
}
