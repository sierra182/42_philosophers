/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_philo_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:57:26 by seblin            #+#    #+#             */
/*   Updated: 2024/03/30 15:54:30 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X_PHILO_STRUCT_H
# define X_PHILO_STRUCT_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				n_philo;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				max_meals;
	int				is_ready;
	int				end_needed;
	struct timeval	start_time;	
	pthread_mutex_t	is_ready_mutex;
	pthread_mutex_t	end_needed_mutex;
	pthread_mutex_t	microphone_mutex;
}	t_data;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	int				id;
	t_fork			*lft_fork;
	t_fork			*rght_fork;
	int				n_meal;
	struct timeval	last_meal;
	int				is_satiated;
	pthread_mutex_t	is_satiated_mutex;
	t_data			*data;
}	t_philo;

typedef struct s_exit
{
	t_data			*data;
	t_philo			*philos;
	t_fork			*forks;
	pthread_t		*tids;
	pthread_mutex_t	exit_mutex;
}	t_exit;

typedef enum e_exit_flag
{
	STT,
	FRK,
	PHI,
	TID,
	DAT,
	END
}	t_exit_enum;

#endif