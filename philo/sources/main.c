/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:42:46 by seblin            #+#    #+#             */
/*   Updated: 2024/04/11 07:52:27 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	death_mic(t_philo *philo, char *str)
{
	long			time;
	pthread_mutex_t	*mutex;

	mutex = &philo->data->microphone_mutex;
	pthread_mutex_lock(mutex);
	time = get_time_since_start(philo);
	if (time < 0)
		return (pthread_mutex_unlock(mutex), 1);
	printf("%ld ", time);
	printf("%d ", philo->id);
	printf("%s", str);
	pthread_mutex_unlock(mutex);
	if (is_end_needed(philo))
		return (1);
	return (0);
}

int	take_mic(t_philo *philo, char *str)
{
	long			time;
	pthread_mutex_t	*mutex;

	mutex = &philo->data->microphone_mutex;
	pthread_mutex_lock(mutex);
	if (is_end_needed(philo))
		return (pthread_mutex_unlock(mutex), 1);
	time = get_time_since_start(philo);
	if (time < 0)
		return (pthread_mutex_unlock(mutex), 1);
	printf("%ld ", time);
	printf("%d ", philo->id);
	printf("%s", str);
	pthread_mutex_unlock(mutex);
	if (is_end_needed(philo))
		return (1);
	return (0);
}

static void	join_threads(t_data *data, pthread_t *tids)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
		pthread_join(tids[i++], NULL);
}

static void	only_one_philosopher(t_data *data)
{
	printf("%d 1 died\n", data->death_time);
	flush_exit_struct();
}

int	main(int argc, char *argv[])
{
	t_data		*data;
	pthread_t	*tids;
	t_philo		*philos;

	if (check_argv(argc, argv))
		return (1);
	data = create_data_struct(argv);
	if (!data)
		return (1);
	if (data->n_philo == 1)
		return (only_one_philosopher(data), 1);
	philos = create_philos(data);
	if (!philos)
		return (flush_exit_struct(), 1);
	tids = create_threads(data, philos);
	if (!tids)
		return (flush_exit_struct(), 1);
	mortician(data, philos);
	join_threads(data, tids);
	return (flush_exit_struct(), 0);
}
