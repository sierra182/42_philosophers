/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:19:37 by seblin            #+#    #+#             */
/*   Updated: 2024/04/06 11:20:56 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHILDS_H
# define CHILDS_H

# include <unistd.h>
# include "x_philo_struct.h"

long	get_time_since_start(t_data *data);
int		philo_routine(t_data *data, t_philo *philo);

#endif