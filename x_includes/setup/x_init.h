/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_init.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:55:50 by seblin            #+#    #+#             */
/*   Updated: 2024/03/30 18:56:56 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X_INIT_H
# define X_INIT_H

# include "x_philo_struct.h"

int		init_forks(t_data *data, t_fork *forks);
int		init_philos(t_data *data, t_philo *philos, t_fork *forks);
void	init_lastmeal_philos(t_data *data, t_philo *philos);

#endif