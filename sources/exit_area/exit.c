/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:45:28 by seblin            #+#    #+#             */
/*   Updated: 2024/03/30 15:09:08 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

static t_exit	*get_exit_struct(void)
{
	static t_exit	exit;

	return (&exit);
}

static void	store_and_free_data(t_exit *exit, void *data)
{
	if (exit && data)
		exit->data = data;
	else if (exit && exit->data)
	{
		pthread_mutex_destroy(&exit->data->end_needed_mutex);
		pthread_mutex_destroy(&exit->data->is_ready_mutex);
		pthread_mutex_destroy(&exit->data->microphone_mutex);
		free(exit->data);
		exit->data = NULL;
	}
}

static void	store_and_free_tids(t_exit *exit, void *tids)
{
	if (exit && tids)
		exit->tids = (pthread_t *) tids;
	else if (exit && exit->tids)
	{		
		free(exit->tids);
		exit->tids = NULL;
	}
}

static void	store_and_free_forks(t_exit *exit, void *forks)
{
	int	i;
	
	if (exit && forks)
		exit->forks = (t_fork *) forks;
	else if (exit && exit->forks)
	{	
		i = -1;
		while (++i < exit->data->n_philo)		
			pthread_mutex_destroy(&exit->forks[i].mutex);		
		free(exit->forks);
		exit->forks = NULL;
	}
}

static void	store_and_free_philos(t_exit *exit, void *philos)
{
	int	i;
	if (exit && philos)
		exit->philos = (t_philo *) philos;
	else if (exit && exit->philos)
	{	
		i = -1;
		while (++i < exit->data->n_philo)		
			pthread_mutex_destroy(&exit->philos[i].n_meal_mutex);			
		free(exit->philos);
		exit->philos = NULL;
	}
}

static void	(**get_store_and_free(void))(t_exit *, void *)
{
	static void	(*store_and_free[END])(t_exit *, void *);

	if (!store_and_free[DAT])
	{
		store_and_free[FRK] = store_and_free_forks;
		store_and_free[PHI] = store_and_free_philos;
		store_and_free[TID] = store_and_free_tids;
		store_and_free[DAT] = store_and_free_data;
	}
	return (store_and_free);
}

void	add_exit_struct(void *ptr, t_exit_enum ex_en)
{
	void	(**store_and_free)(t_exit *, void *);
	t_exit	*exit;

	exit = get_exit_struct();
	store_and_free = get_store_and_free();
	if (store_and_free[ex_en])
		store_and_free[ex_en](exit, ptr);
}

void	flush_exit_struct(void)
{
	void		(**store_and_free)(t_exit *, void *);
	t_exit_enum	ex_en;
	t_exit		*exit;

	ex_en = STT;
	exit = get_exit_struct();
	store_and_free = get_store_and_free();
	while (++ex_en < END)
		if (store_and_free[ex_en])
			store_and_free[ex_en](exit, NULL);
}
