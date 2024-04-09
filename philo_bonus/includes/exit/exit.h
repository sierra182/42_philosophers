/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:35:46 by seblin            #+#    #+#             */
/*   Updated: 2024/04/09 10:33:49 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include <stdlib.h>
# include "x_philo_struct.h"

typedef void	(*t_getsaf)(t_exit *, void *);
void			store_and_free_data(t_exit *exit, void *data);
void			store_and_free_philos(t_exit *exit, void *philos);

#endif