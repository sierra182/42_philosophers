/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:42:46 by seblin            #+#    #+#             */
/*   Updated: 2024/03/24 14:23:25 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include "x_philo_struct.h"
#include "x_philo_utils.h"

int	check_argv(int argc, char *argv[]);

void *routine(void *data)
{
	printf("je suis le nouveau tread!\n");
}	

create_data_struct(char *argv[])
{
	t_data *data;
	
	data = (t_data *) ft_calloc(1, sizeof(t_data));
	data->n_philo = ft_atoi(*++argv);
	data->eat_time = ft_atoi(*++argv);
	data->sleep_time = ft_atoi(*++argv);
	data->think_time = ft_atoi(*++argv);
	if (*++argv)
		data->n_cycle = ft_atoi(*argv);
	return (data);
}

int	main(int argc, char *argv[])
{
	t_data *data;
	pthread_t tid;
	
	if (check_argv(argc, argv))
		return (1);
	data = create_data_struct(argv);
	printf("hello world!\n");
	pthread_create(&tid, NULL, routine, NULL);
	pthread_join(tid, NULL);

	return (0);
}