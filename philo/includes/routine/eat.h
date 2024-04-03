/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:40:10 by seblin            #+#    #+#             */
/*   Updated: 2024/04/03 21:35:12 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EAT_H
# define EAT_H

# include "x_philo_struct.h"
# include "unistd.h"

int		is_end_needed(t_philo *philo);
int		take_mic(t_philo *philo, char *str);

#endif