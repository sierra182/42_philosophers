/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:42:46 by seblin            #+#    #+#             */
/*   Updated: 2024/03/28 15:11:22 by seblin           ###   ########.fr       */
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

long	get_delta_time(struct timeval *time_a, struct timeval *time_b)
{
	long			delta_sec;
	long 			delta_microsec;

	delta_sec = time_b->tv_sec - time_a->tv_sec;
	delta_microsec = time_b->tv_usec - time_a->tv_usec;
	if (delta_microsec < 0)
	{
		delta_sec--;
		delta_microsec += 1000000;
	}
	return (delta_sec * 1000 + delta_microsec / 1000);
}

long	get_time_since_start(t_philo *philo)
{
	struct timeval	start_time;
	struct timeval	actual_time;

	start_time = philo->data->start_time;
	if (!gettimeofday(&actual_time, NULL))	
		return (get_delta_time(&start_time, &actual_time));	
	else
		return (-1);
}

void	*say_on_shared_microphone(t_philo *philo, char *str)
{	
	long	time;
	pthread_mutex_t *mutex;
	
	mutex = &philo->data->microphone_mutex;
	pthread_mutex_lock(mutex);	
	time = get_time_since_start(philo);
	if (time < 0)
		return (NULL);
	printf("%ld ", time);
	printf("%d ", philo->id);
	printf("%s", str);
	pthread_mutex_unlock(mutex);
}



void	philo_think(t_philo *philo)
{
	say_on_shared_microphone(philo, "is thinking\n");	
}

void	philo_sleep(t_philo *philo)
{
	say_on_shared_microphone(philo, "is sleeping\n");
	usleep(philo->data->sleep_time * 1000);	
}

void	even_philo_get_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->rght_fork->mutex);
	say_on_shared_microphone(philo, "has taken a fork\n");
	pthread_mutex_lock(&philo->lft_fork->mutex);
	say_on_shared_microphone(philo, "has taken a fork\n");
}

void	odd_philo_get_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->lft_fork->mutex);
	say_on_shared_microphone(philo, "has taken a fork\n");
	pthread_mutex_lock(&philo->rght_fork->mutex);
	say_on_shared_microphone(philo, "has taken a fork\n");
}

int	iam_actually_dead(t_philo *philo)
{		
	struct timeval	actual_time;
	long			delta_last_meal;
	
	if (!gettimeofday(&actual_time, NULL))
	{
		delta_last_meal = get_delta_time(&philo->last_meal, &actual_time);
		if (delta_last_meal >= philo->data->death_time)
			return (1);
		return (0);
	}		
	else
		return (-1);
}

void	update_last_meal(t_philo *philo)
{
	gettimeofday(&philo->last_meal, NULL);	
}

int	is_odd(t_philo *philo)
{
	return (philo->id % 2);
}

int	philo_eat(t_philo *philo)
{	
	if (is_odd(philo))	
		odd_philo_get_forks(philo);
	else
		even_philo_get_forks(philo);
	update_last_meal(philo);
	if (iam_actually_dead(philo))
		return (say_on_shared_microphone(philo, "died\n"), 1);		
	say_on_shared_microphone(philo, "is eating\n");
	usleep(philo->data->eat_time * 1000);		
	pthread_mutex_unlock(&philo->lft_fork->mutex);
	pthread_mutex_unlock(&philo->rght_fork->mutex);
	return (0);	
}

void	*philo_routine(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *) arg;
	while (1)
	{	
		if (philo->data->end_needed)
			break;
		if (philo_eat(philo))
			return (NULL);
		if (philo->data->end_needed)
			break;
		philo_sleep(philo);
		if (philo->data->end_needed)
			break;
		philo_think(philo);
	}
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
		philos[i].last_meal = data->start_time;
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

pthread_t *create_threads(t_data *data, t_philo *philos)
{		
	pthread_t *tids;
	int i;
	
	tids = (pthread_t *) ft_calloc(data->n_philo, sizeof(pthread_t));
	if (!tids)
		return (NULL);
	i = 0;
	while (i < data->n_philo)		
		pthread_create(&tids[i], NULL, philo_routine, (void *) &philos[i++]);	
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
	data->death_time = ft_atoi(*++argv);
	data->eat_time = ft_atoi(*++argv);
	data->sleep_time = ft_atoi(*++argv);
	if (*++argv)
		data->n_cycle = ft_atoi(*argv);	
	if (gettimeofday(&(data->start_time), NULL))	
		return (free(data), NULL);	
	if (pthread_mutex_init(&data->microphone_mutex, NULL))
		return (free(data), NULL);
	return (data);
}
void	add_exit_struct(void *ptr, t_exit_enum ex_en);
void	flush_exit_struct(void);

void	join_threads(t_data *data, pthread_t *tids)
{
	int		i;	
	
	i = 0;
	while (i < data->n_philo)		
		pthread_join(tids[i++], NULL);	
}

void	check_death_notice(t_data *data, t_philo *philos)
{
	int	i;

	while (1)
	{		
		i = 0;
		while (i < data->n_philo)
		{			
			if (philos[i++].is_dead)
			{
				data->end_needed = 1;		
				return ;
			}
		}
	}
}

int	main(int argc, char *argv[])
{
	t_data *data;
	pthread_t *tids;
	t_philo	*philos;

	if (check_argv(argc, argv))
		return (1);
	data = create_data_struct(argv);
	if (!data)
		return (1);    					
	add_exit_struct((void *) data, DAT);
	philos = create_philos(data);
	if (!philos)
		return (1);
	tids = create_threads(data, philos);
	if (!tids)
		return (1);
	check_death_notice(data, philos);
	join_threads(data, tids);
	free(tids);
	flush_exit_struct();
	return (0);
}
