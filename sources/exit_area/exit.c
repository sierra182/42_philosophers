/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:45:28 by seblin            #+#    #+#             */
/*   Updated: 2024/03/29 14:12:22 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

static t_exit	*get_exit_struct(void)
{
	static t_exit	exit;
	
	return (&exit);
}
static void	store_and_free_data(t_exit *exit, void *data)
{	
	if (exit && data)
		exit->data = (t_data *) data;
	else if (exit)
	{
		pthread_mutex_destroy(&exit->data->microphone_mutex);		
		free(exit->data);
		exit->data = NULL;
	}
}

static void (**get_store_and_free(void))(t_exit *, void *)
{
	static void (*store_and_free[END])(t_exit *, void *);
		
	if (!store_and_free[DAT])
	{
		store_and_free[DAT] = store_and_free_data;		
	}		
	return (store_and_free);
}

void	add_exit_struct(void *ptr, t_exit_enum ex_en)
{
	void 	(**store_and_free)(t_exit *, void *);
	t_exit 	*exit;
		
	exit = get_exit_struct();
	store_and_free = get_store_and_free();
	if (store_and_free[ex_en])
		store_and_free[ex_en](exit, ptr);
}

void	flush_exit_struct(void)
{
	void 	(**store_and_free)(t_exit *, void *);
	t_exit_enum ex_en;	
	t_exit 		*exit;

	ex_en = STT;
	exit = get_exit_struct();
	store_and_free = get_store_and_free();
	while (++ex_en < END)
		if (store_and_free[ex_en])
			store_and_free[ex_en](exit, NULL);
}
