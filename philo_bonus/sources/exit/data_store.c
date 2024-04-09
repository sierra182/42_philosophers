/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_store.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:35:28 by seblin            #+#    #+#             */
/*   Updated: 2024/04/09 09:37:15 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_store.h"

// void	store_and_free_tids(t_exit *exit, void *tids)
// {
// 	if (exit && tids)
// 		exit->tids = (pthread_t *) tids;
// 	else if (exit && exit->tids)
// 	{
// 		free(exit->tids);
// 		exit->tids = NULL;
// 	}
// }

// void	store_and_free_forks(t_exit *exit, void *forks)
// {
// 	int	i;

// 	if (exit && forks)
// 		exit->forks = (t_fork *) forks;
// 	else if (exit && exit->forks)
// 	{
// 		i = -1;
// 		while (++i < exit->data->n_philo)
// 			pthread_mutex_destroy(&exit->forks[i].mutex);
// 		free(exit->forks);
// 		exit->forks = NULL;
// 	}
// }

void	store_and_free_philos(t_exit *exit, void *philos)
{
	int	i;

	if (exit && philos)
		exit->philos = (t_philo *) philos;
	else if (exit && exit->philos)
	{
		i = -1;
		while (++i < exit->data->n_philo)
		{
			sem_close(&exit->philos[i].last_meal);
			sem_unlink(exit->data->sem_death);
			pthread_mutex_destroy(&exit->philos[i].last_meal_mutex);
			pthread_mutex_destroy(&exit->philos[i].is_satiated_mutex);
			pthread_mutex_destroy(&exit->philos[i].end_needed_mutex);
		}
		free(exit->philos);
		exit->philos = NULL;
	}
}

void	store_and_free_data(t_exit *exit, void *data)
{
	if (exit && data)
		exit->data = data;
	else if (exit && exit->data)
	{
		sem_close(exit->data->sem_death);
		sem_unlink(exit->data->sem_death);
		sem_close(exit->data->sem_death_notice);
		sem_unlink(exit->data->sem_death_notice);
		sem_close(exit->data->sem_mic);
		sem_unlink(exit->data->sem_mic);
		sem_close(exit->data->sem_forks);
		sem_unlink(exit->data->sem_forks);		
		free(exit->data);
		exit->data = NULL;
	}
}
