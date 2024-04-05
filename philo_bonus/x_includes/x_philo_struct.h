/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_philo_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:46:32 by svidot            #+#    #+#             */
/*   Updated: 2024/04/05 15:18:30 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X_PHILO_STRUCT_H
# define X_PHILO_STRUCT_H

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

typedef struct s_exit
{
	t_data			*data;
}	t_exit;

typedef enum e_exit
{
	STT,	
	DAT,
	END
}	t_exit_enum;

#endif