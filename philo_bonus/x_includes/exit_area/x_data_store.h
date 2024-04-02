/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_data_store.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:41:55 by seblin            #+#    #+#             */
/*   Updated: 2024/04/01 14:37:43 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X_DATA_STORE_H
# define X_DATA_STORE_H

# include "x_philo_struct.h"

void	store_and_free_forks(t_exit *exit, void *forks);
void	store_and_free_philos(t_exit *exit, void *philos);
void	store_and_free_tids(t_exit *exit, void *tids);
void	store_and_free_data(t_exit *exit, void *data);

#endif