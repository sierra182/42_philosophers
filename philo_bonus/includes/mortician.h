/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mortician.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:00:14 by seblin            #+#    #+#             */
/*   Updated: 2024/04/06 16:35:47 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MORTICIAN_H
# define MORTICIAN_H

# include <unistd.h>
# include "x_philo_struct.h"

long	get_time_since_start(t_data *data);
long	get_time_since_last_meal(t_philo *philo);

#endif