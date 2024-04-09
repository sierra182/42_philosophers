/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:28:57 by seblin            #+#    #+#             */
/*   Updated: 2024/04/09 10:43:26 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <pthread.h>
# include <sys/wait.h>
# include "x_philo_struct.h"
# include "x_exit.h"

int	parsing(int argc, char *argv[]);
int	setup(char *argv[], t_data **data, t_philo **philos);
int	make_childs(t_data *data, t_philo *philos);
int	death_noticer(t_data *data);

#endif