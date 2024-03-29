/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:28:57 by seblin            #+#    #+#             */
/*   Updated: 2024/03/29 14:25:39 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include "x_philo_struct.h"
# include "x_setup.h"
# include "x_exit.h"

long	get_time_since_start(t_philo *philo);
int		check_argv(int argc, char *argv[]);
void	check_death_notice(t_data *data, t_philo *philos);

#endif