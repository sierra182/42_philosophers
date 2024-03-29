/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:42:46 by seblin            #+#    #+#             */
/*   Updated: 2024/03/29 15:04:21 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*say_on_shared_microphone(t_philo *philo, char *str)
{
	long			time;
	pthread_mutex_t	*mutex;

	mutex = &philo->data->microphone_mutex;
	pthread_mutex_lock(mutex);
	if (philo->data->end_needed)
	{
		pthread_mutex_unlock(mutex);
		return (NULL);
	}
	time = get_time_since_start(philo);
	if (time < 0)
		return (NULL);
	printf("%ld ", time);
	printf("%d ", philo->id);
	printf("%s", str);
	pthread_mutex_unlock(mutex);
}

static void	join_threads(t_data *data, pthread_t *tids)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
		pthread_join(tids[i++], NULL);
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
