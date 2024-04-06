/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:37:55 by svidot            #+#    #+#             */
/*   Updated: 2024/04/06 12:34:34 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char *argv[])
{
	t_data	*data;
	t_philo	*philos;
	
	if (parsing(argc, argv))
		return (1);
	if (setup(argv, &data, &philos))
		return (1);	
	if (make_childs(data, philos))
		return (1);
	// if (mortician(data))
	// 	return (1);
	return (0);
}
