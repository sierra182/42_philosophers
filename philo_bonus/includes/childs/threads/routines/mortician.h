/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mortician.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:00:44 by seblin            #+#    #+#             */
/*   Updated: 2024/04/09 14:46:08 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MORTICIAN_H
# define MORTICIAN_H

# include <stdlib.h>
# include <unistd.h>
# include "x_philo_struct.h"
# include "x_exit.h"

long	get_time_since_last_meal(t_philo *philo);
long	get_time_since_start(t_data *data);
int		is_end_needed(t_philo *philo);

#endif