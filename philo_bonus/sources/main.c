/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:37:55 by svidot            #+#    #+#             */
/*   Updated: 2024/04/10 09:31:06 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	wait_childs(t_data *data, pthread_t tid_death_not)
{
	while (waitpid(-1, NULL, 0) > 0)
		;//usleep(500);
	sem_post(data->sem_death);
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
	wait_childs(data, tid_death_not);	
	return (flush_exit_struct(), 0);
}
