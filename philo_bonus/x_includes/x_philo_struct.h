/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_philo_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:46:32 by svidot            #+#    #+#             */
/*   Updated: 2024/04/09 11:06:47 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X_PHILO_STRUCT_H
# define X_PHILO_STRUCT_H

# include <semaphore.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_data
{
	int				n_philo;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				max_meals;	
	struct timeval	start_time;
	sem_t			*sem_mic;
	sem_t			*sem_forks;
	sem_t			*sem_death;
	sem_t			*sem_death_notice;	
}	t_data;

typedef struct s_philo
{
	int				id;
	int				n_meal;
	struct timeval	last_meal;
	int				end_needed;
	sem_t			*sem_last_meal;	
	sem_t			*sem_end_needed;	
}	t_philo;

typedef struct s_exit
{
	t_data	*data;
	t_philo	*philos;
}	t_exit;

typedef enum e_exit
{
	STT,	
	PHI,
	DAT,
	END
}	t_exit_enum;

#endif