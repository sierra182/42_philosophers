/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mortuary.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:37:37 by seblin            #+#    #+#             */
/*   Updated: 2024/03/30 15:33:46 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MORTUARY_H
# define MORTUARY_H

# include "x_philo_struct.h"

void	*take_mic(t_philo *philo, char *str);
long	get_delta_time(struct timeval *time_a, struct timeval *time_b);
int		is_max_meal_over(t_philo *philo);

#endif