/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:16:26 by seblin            #+#    #+#             */
/*   Updated: 2024/03/29 10:35:25 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_forks(t_data *data, t_fork *forks)
{
	int	i;

	i = 0;
	while (i < data->n_philo)	
		pthread_mutex_init(&forks[i++].mutex, NULL);	
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