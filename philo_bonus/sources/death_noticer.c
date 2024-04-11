/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_noticer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:54:29 by seblin            #+#    #+#             */
/*   Updated: 2024/04/11 14:33:43 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "death_noticer.h"

static void	wait_childs(void)
{
	while (waitpid(-1, NULL, 0) > 0)
		usleep(500);
}

static void	*wait_death(void *ptr)
{
	t_philo	*philos;
	t_data	*data;
	int		i;

	i = -1;
	data = (t_data *)((void **) ptr)[0];
	philos = (t_philo *)((void **) ptr)[1];
	sem_wait(data->sem_death);
	while (++i < data->n_philo)
		sem_post(philos[i].sem_death_notice);
	return (NULL);
}

int	death_noticer(t_data *data, t_philo *philos)
{
	pthread_t	tid_death_not;

	if (pthread_create(&tid_death_not, NULL, wait_death,
			(void *[]){data, philos}))
		return (1);
	wait_childs();
	sem_post(data->sem_death);
	pthread_join(tid_death_not, NULL);
	return (0);
}
