/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:28:57 by seblin            #+#    #+#             */
/*   Updated: 2024/03/30 12:46:13 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include "x_philo_struct.h"
# include "x_setup.h"
# include "x_exit.h"

int		is_end_needed(t_philo *philo);
long	get_time_since_start(t_philo *philo);
int		check_argv(int argc, char *argv[]);
void	mortician(t_data *data, t_philo *philos);

#endif