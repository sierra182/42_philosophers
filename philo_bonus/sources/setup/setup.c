/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:41:21 by svidot            #+#    #+#             */
/*   Updated: 2024/04/05 18:44:37 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

int	create_data_struct(char *argv[], t_data **data)
{
	*data = (t_data *) ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	(*data)->n_philo = ft_atoi(*++argv);
	(*data)->death_time = ft_atoi(*++argv);
	(*data)->eat_time = ft_atoi(*++argv);
	(*data)->sleep_time = ft_atoi(*++argv);
	if (*++argv)
		(*data)->max_meals = ft_atoi(*argv);	
	return (0);
}

int	setup(char *argv[], t_data **data)
{
	if (create_data_struct(argv, data))
		return (1);
	add_exit_struct((void *) *data, DAT);
	return (0);
}
