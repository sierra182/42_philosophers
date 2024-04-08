/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_noticer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:27:55 by seblin            #+#    #+#             */
/*   Updated: 2024/04/08 15:38:57 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEATH_NOTICER_H
# define DEATH_NOTICER_H

# include <pthread.h>
# include <unistd.h>
# include "x_philo_struct.h"

long	get_time_since_start(t_data *data);
long	get_time_since_last_meal(t_philo *philo);

#endif