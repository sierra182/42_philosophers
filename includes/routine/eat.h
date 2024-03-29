/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:40:10 by seblin            #+#    #+#             */
/*   Updated: 2024/03/29 21:42:57 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EAT_H
# define EAT_H

# include "x_philo_struct.h"
# include "unistd.h"

int		iam_actually_dead(t_philo *philo);
void	*take_mic(t_philo *philo, char *str);

#endif