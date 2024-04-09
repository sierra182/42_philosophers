/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:14:58 by seblin            #+#    #+#             */
/*   Updated: 2024/04/09 14:46:18 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include "x_philo_struct.h"
# include "x_exit.h"

int	is_end_needed(t_philo *philo);
int	take_mic(t_data *data, t_philo *philo, char *str);

#endif