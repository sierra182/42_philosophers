/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:49:09 by seblin            #+#    #+#             */
/*   Updated: 2024/04/09 14:46:13 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

# include <pthread.h>
# include <stdlib.h>
# include "x_philo_struct.h"
# include "x_exit.h"

long	get_time_since_start(t_data *data);
void	*mortician_routine(void *ptr);
void	*philo_routine(void *ptr);

#endif