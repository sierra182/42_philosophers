/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:37:55 by svidot            #+#    #+#             */
/*   Updated: 2024/04/05 17:18:47 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"



int	main(int argc, char *argv[])
{
	t_data	*data;
	
	if (parsing(argc, argv))
		return (1);
	if (setup(argv, &data))
		return (1);	
	if (make_childs(data))
		return (1);
	return (0);
}
