/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:37:55 by svidot            #+#    #+#             */
/*   Updated: 2024/04/09 16:20:12 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	wait_childs(pthread_t tid_death_not)
{
	while (wait(&(int){0}) > 0)
		;//usleep(500);
	pthread_join(tid_death_not, NULL);
}

int	main(int argc, char *argv[])
{	
	t_data		*data;
	t_philo		*philos;
	pthread_t	tid_death_not;
	
	if (parsing(argc, argv))
		return (1);
	if (setup(argv, &data, &philos))
		return (1);
	if (make_childs(data, philos))
		return (1);
	if (death_noticer(data, &tid_death_not))
		return (1);
	wait_childs(tid_death_not);	
	return (flush_exit_struct(), 0);
}
