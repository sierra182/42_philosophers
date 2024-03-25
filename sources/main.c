/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:42:46 by seblin            #+#    #+#             */
/*   Updated: 2024/03/25 16:02:37 by seblin           ###   ########.fr       */
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

void	fill_tids_array(t_data *data, pthread_t *tids, pthread_mutex_t *lock)
{
	int i;
	
	i = 0;
	while (i < data->n_philo)
	{	
		pthread_create(&tids[i], NULL, shared_microphone, (void *) lock);
		i++;
	}
}

pthread_t *create_tids_array(t_data *data)
{
	pthread_t	*tids;
	
	tids = NULL;
	tids = (pthread_t *) ft_calloc(data->n_philo, sizeof(pthread_t));
	return (tids);
}

pthread_t *create_threads(t_data *data, pthread_mutex_t	*lock)
{		
	pthread_t *tids;

	tids = create_tids_array(data);
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

void	join_threads(t_data *data, pthread_t *tids)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(tids[i], NULL);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_data *data;
	pthread_t *tids;
	pthread_mutex_t	lock;

	if (check_argv(argc, argv))
		return (1);
	data = create_data_struct(argv);
	if (!data)
		return (1);
	printf("hello world!\n");
	tids = create_threads(data, &lock);
	if (!tids)
		return (1);
	join_threads(data, tids);
	pthread_mutex_destroy(&lock);
	free(tids);
	free(data);
	return (0);
}