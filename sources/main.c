/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:42:46 by seblin            #+#    #+#             */
/*   Updated: 2024/03/26 10:00:07 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include "x_philo_struct.h"
#include "x_philo_utils.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size);
int		check_argv(int argc, char *argv[]);

void	*shared_microphone(void *lock)
{	
	pthread_mutex_lock(lock);
	printf("je suis le nouveau tread! tid: %lu\n", pthread_self());
	pthread_mutex_unlock(lock);
}

void	join_threads(t_data *data, pthread_t *tids)
{
	int	i;

	i = 0;
	while (i < data->n_philo)	
		pthread_join(tids[i++], NULL);	
}

void	fill_tids_array(t_data *data, pthread_t *tids, pthread_mutex_t *lock)
{
	int i;
	
	i = 0;
	while (i < data->n_philo)		
		pthread_create(&tids[i++], NULL, shared_microphone, (void *) lock);	
}

void	fill_philos(t_data *data, t_philo *philos, t_fork *forks)
{
	int	i;
	
	i = 0;
	while (i < data->n_philo)
	{			
		philos[i].id = i + 1;
		philos[i].lft_fork = &forks[i];
		philos[i].rght_fork = &forks[(i + 1) % data->n_philo];
		i++;
	}
}

void	init_forks(t_data *data, t_fork *forks)
{
	int	i;

	i = 0;
	while (i < data->n_philo)	
		pthread_mutex_init(&forks[i++].mutex, NULL);	
}

void	create_philos(t_data *data)
{
	t_philo	*philos;
	t_fork	*forks;
	int	i;

	philos = (t_philo *) ft_calloc(data->n_philo, sizeof(t_philo));	
	if (!philos)
		return; // (NULL);
	forks = (t_fork *) ft_calloc(data->n_philo, sizeof(t_fork));
	if (!forks)
	{
		free (philos);
		return; // (NULL);
	}
	init_forks(data, forks);		
	fill_philos(data, philos, forks);	
}

pthread_t *create_threads(t_data *data, pthread_mutex_t	*lock)
{		
	pthread_t *tids;

	tids = (pthread_t *) ft_calloc(data->n_philo, sizeof(pthread_t));
	if (!tids)
		return (NULL);
	pthread_mutex_init(lock, NULL);
	fill_tids_array(data, tids, lock);
	return (tids);
}

t_data	*create_data_struct(char *argv[])
{
	t_data *data;
	
	data = NULL;
	data = (t_data *) ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->n_philo = ft_atoi(*++argv);
	data->eat_time = ft_atoi(*++argv);
	data->sleep_time = ft_atoi(*++argv);
	data->think_time = ft_atoi(*++argv);
	if (*++argv)
		data->n_cycle = ft_atoi(*argv);
	return (data);
}
void	update_exit_struct(void *ptr, t_exit_enum ex_en);
void	free_exit_struct(void);

int	main(int argc, char *argv[])
{
	t_data *data;
	pthread_t *tids;
	pthread_mutex_t	lock;

	printf("hello world!\n");
	if (check_argv(argc, argv))
		return (1);
	data = create_data_struct(argv);
	if (!data)
		return (1);    					//data
	update_exit_struct((void *) data, DAT);
	free_exit_struct();
	
	tids = create_threads(data, &lock);
	if (!tids)
		return (1);
	join_threads(data, tids);
	pthread_mutex_destroy(&lock);
	free(tids);
	free(data);
	return (0);
}
