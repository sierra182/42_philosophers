/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:14:58 by seblin            #+#    #+#             */
/*   Updated: 2024/04/10 14:02:46 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include "x_philo_struct.h"

void	rise_end_needed(t_philo *philo);
int		is_end_needed(t_philo *philo);
int		take_mic(t_data *data, t_philo *philo, char *str);

#endif