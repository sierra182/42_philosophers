/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_setup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:53:23 by seblin            #+#    #+#             */
/*   Updated: 2024/03/29 14:00:52 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X_SETUP_H
# define X_SETUP_H

# include "x_philo_struct.h"

t_data		*create_data_struct(char *argv[]);
pthread_t	*create_threads(t_data *data, t_philo *philos);
t_philo		*create_philos(t_data *data);

#endif