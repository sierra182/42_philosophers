/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:41:37 by seblin            #+#    #+#             */
/*   Updated: 2024/03/29 14:32:56 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include "x_philo_struct.h"
# include "unistd.h"

void	*say_on_shared_microphone(t_philo *philo, char *str);
int		philo_eat(t_philo *philo);

#endif