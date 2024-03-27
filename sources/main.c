/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:42:46 by seblin            #+#    #+#             */
/*   Updated: 2024/03/27 17:40:35 by seblin           ###   ########.fr       */
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
#include <unistd.h>



long	get_time(t_philo *philo)
{
	struct timeval	start_time;
	struct timeval	actual_time;
	long			delta_sec;
	long 			delta_microsec;

	start_time = philo->data->start_time;
	if (!gettimeofday(&actual_time, NULL))
	{
		delta_sec = actual_time.tv_sec - start_time.tv_sec;
		delta_microsec = actual_time.tv_usec - start_time.tv_usec;
		if (delta_microsec < 0)
		{
			delta_sec--;
			delta_microsec += 1000000;
		}
		return (delta_sec * 1000 + delta_microsec / 1000);
	}
	else
		return (-1);
}

void	*shared_microphone(t_philo *philo, char *str)
{	
	long	time;
	pthread_mutex_t *mutex;
	
	mutex = &philo->data->microphone_mutex;
	pthread_mutex_lock(mutex);	
	time = get_time(philo);
	if (time < 0)
		return (NULL);
	printf("%ld ", time);
	printf("%d ", philo->id);
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

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->lft_fork->mutex);
	shared_microphone(philo, "has taken a fork\n");
	pthread_mutex_unlock(&philo->lft_fork->mutex);
}

void	*philo_routine(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *) arg;	
	eat(philo);
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
		pthread_create(&tids[i], NULL, philo_routine, (void *) &philos[i++]);	
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
	if (gettimeofday(&(data->start_time), NULL))	
		return (free(data), NULL);
	//printf("%ld\n", data->start_time.tv_sec);
	// sleep(2);
	// printf("%ld\n", data->start_time.tv_sec);
	// exit(1);
	if (pthread_mutex_init(&data->microphone_mutex, NULL))
		return (free(data), NULL);
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
