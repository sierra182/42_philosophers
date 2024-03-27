/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:42:46 by seblin            #+#    #+#             */
/*   Updated: 2024/03/27 14:36:49 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include "x_philo_struct.h"
#include "x_philo_utils.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size);
int		check_argv(int argc, char *argv[]);

#include <sys/time.h>
void	build_output(int id, char *str)
{
	struct timeval time_v;
	if (gettimeofday(&time_v, NULL))
		
	else
		return ; //err
}

void	*shared_microphone(pthread_mutex_t *mutex, char *str)
{	
	pthread_mutex_lock(mutex);
	printf("%s", str);
	pthread_mutex_unlock(mutex);
}



void	join_threads(t_data *data, pthread_t *tids)
{
	int	i;

	i = 0;
	while (i < data->n_philo)	
		pthread_join(tids[i++], NULL);	
}

void	eat(t_philo *philos)
{
	pthread_mutex_lock(philos->lft_fork);
	shared_microphone(&philos->data->microphone_mutex, "X has taken a fork");
	pthread_mutex_unlock(philos->lft_fork);
	philos->lft_fork
}

void	*philo_routine(void *arg)
{
	t_philo *philos;
	
	philos = (t_philo *) arg;
	eat(philos);
}

void	init_philos(t_data *data, t_philo *philos, t_fork *forks)
{
	int	i;
	
	i = 0;
	while (i < data->n_philo)
	{			
		philos[i].id = i + 1;
		philos[i].lft_fork = &forks[i];
		philos[i].rght_fork = &forks[(i + 1) % data->n_philo];
		philos[i].data = data;
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

t_philo	*create_philos(t_data *data)
{
	t_philo	*philos;
	t_fork	*forks;

	philos = (t_philo *) ft_calloc(data->n_philo, sizeof(t_philo));	
	if (!philos)
		return (NULL);
	forks = (t_fork *) ft_calloc(data->n_philo, sizeof(t_fork));
	if (!forks)
	{
		free(philos);
		return (NULL);
	}
	init_forks(data, forks); //err
	init_philos(data, philos, forks);
	return (philos);
}

void	fill_tids_array(t_data *data, pthread_t *tids, t_philo *philos)
{
	int i;
	
	i = 0;
	while (i < data->n_philo)		
		pthread_create(&tids[i++], NULL, philo_routine, (void *) philos);	
}

pthread_t *create_threads(t_data *data, t_philo *philos)
{		
	pthread_t *tids;

	tids = (pthread_t *) ft_calloc(data->n_philo, sizeof(pthread_t));
	if (!tids)
		return (NULL);	
	fill_tids_array(data, tids, philos);
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
	if (pthread_mutex_init(&data->microphone_mutex, NULL))
	{
		free(data);	
		return (NULL);
	}
	return (data);
}
void	add_exit_struct(void *ptr, t_exit_enum ex_en);
void	flush_exit_struct(void);

int	main(int argc, char *argv[])
{
	t_data *data;
	pthread_t *tids;
	t_philo	*philos;
	
	printf("hello world!\n");
	if (check_argv(argc, argv))
		return (1);
	data = create_data_struct(argv);
	if (!data)
		return (1);    					
	add_exit_struct((void *) data, DAT);
	philos = create_philos(data);
	if (!philos)
		return (1);// err
	tids = create_threads(data, philos);
	if (!tids)
		return (1);
	join_threads(data, tids);
	free(tids);	
	flush_exit_struct();
	return (0);
}
