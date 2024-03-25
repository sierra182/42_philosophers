/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:45:28 by seblin            #+#    #+#             */
/*   Updated: 2024/03/25 22:43:22 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "x_philo_struct.h"

t_exit	*get_and_free_exit_struct(int flag)
{
	static t_exit exit;
	
	if (!exit)
		exit = (t_exit *) ft_calloc(1, sizeof(t_exit));	
	if (flag)
	{
		free(exit);
		exit = NULL;	
	}
	return (exit);
}

void	store_and_free_data(t_exit *exit, void *data)
{
	if (exit && data)
		exit->data = (t_data *) data;
	else if (exit)
	{
		free(exit->data);
		exit->data = NULL;
	}
}

void	update_exit_struct(void *ptr, t_exit_enum var_id)
{
	t_exit 		exit;
	t_exit_enum exit_enum;
	
	exit = get_and_free_exit_struct(0);	
	store_and_free[var_id](exit, ptr);
}