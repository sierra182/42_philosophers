/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:37:55 by svidot            #+#    #+#             */
/*   Updated: 2024/04/11 08:05:18 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	is_alone(t_data *data)
{
	if (data->n_philo == 1)
		return (printf("%d 1 died\n", data->death_time), 1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data		*data;
	t_philo		*philos;

	if (parsing(argc, argv))
		return (1);
	if (setup(argv, &data, &philos))
		return (flush_exit_struct(), 1);
	if (is_alone(data))
		return (flush_exit_struct(), 1);
	if (make_childs(data, philos))
		return (flush_exit_struct(), 1);
	if (death_noticer(data, philos))
		return (flush_exit_struct(), 1);
	flush_exit_struct();
	return (0);
}
