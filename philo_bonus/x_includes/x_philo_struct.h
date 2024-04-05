/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_philo_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:46:32 by svidot            #+#    #+#             */
/*   Updated: 2024/04/05 22:23:56 by seblin           ###   ########.fr       */
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

}	t_data;

typedef struct s_philo
{
	int				id;
	int				n_meal;
	int				end_needed;
	int				is_satiated;
	struct timeval	last_meal;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	is_satiated_mutex;
	pthread_mutex_t	end_needed_mutex;

	t_data			*data;
}	t_philo;

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