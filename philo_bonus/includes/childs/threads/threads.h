/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:49:09 by seblin            #+#    #+#             */
/*   Updated: 2024/04/08 13:57:12 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

# include <pthread.h>
# include "x_philo_struct.h"
# include <stdlib.h>

long	get_time_since_start(t_data *data);
void	*mortician_routine(void *ptr);
void	*philo_routine(void *ptr);

#endif