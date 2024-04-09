/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:37:55 by svidot            #+#    #+#             */
/*   Updated: 2024/04/09 10:46:56 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	wait_childs(void)
{
	while (wait(&(int){0}) > 0)
		;//usleep(500);
}

int	main(int argc, char *argv[])
{	
	t_data		*data;
	t_philo		*philos;
	
	if (parsing(argc, argv))
		return (1);
	if (setup(argv, &data, &philos))
		return (1);
	if (make_childs(data, philos))
		return (1);
	if (death_noticer(data))
		return (1);
	wait_childs();	
	;//return (flush_exit_struct(), 0);
}
