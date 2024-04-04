/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:41:37 by seblin            #+#    #+#             */
/*   Updated: 2024/04/03 21:36:59 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include "x_philo_struct.h"
# include "unistd.h"

int		take_mic(t_philo *philo, char *str);
int		philo_eat(t_philo *philo);

#endif