/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:37:55 by svidot            #+#    #+#             */
/*   Updated: 2024/04/08 18:13:57 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	wait_all_philos(void)
{
	while (wait(&(int){0}) > 0)
		usleep(500);
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
	wait_all_philos();
	return (0);
}
