/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_philo_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:57:26 by seblin            #+#    #+#             */
/*   Updated: 2024/04/04 13:26:58 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X_PHILO_STRUCT_H
# define X_PHILO_STRUCT_H

# include <stdio.h>
# include <sys/time.h>

typedef struct s_data
{
	int				n_philo;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				max_meals;
	struct timeval	start_time;
}	t_data;

typedef struct s_philo
{
	int				id;	
	int				n_meal;
	int				end_needed;
	int				is_satiated;
	struct timeval	last_meal;	
	t_data			*data;
}	t_philo;

typedef struct s_exit
{
	t_data			*data;
	t_philo			*philos;
}	t_exit;

typedef enum e_exit_flag
{
	STT,
	PHI,	
	DAT,
	END
}	t_exit_enum;

#endif