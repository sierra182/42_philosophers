/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_philo_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:57:26 by seblin            #+#    #+#             */
/*   Updated: 2024/03/25 17:33:23 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X_PHILO_STRUCT_H
# define X_PHILO_STRUCT_H

typedef struct s_data
{
	int	n_philo;
	int	eat_time;
	int	sleep_time;
	int	think_time;
	int	n_cycle;
}	t_data;

typedef struct s_fork {
    pthread_mutex_t mutex;
}	t_fork;

typedef struct s_philo
{
	int		id;
	t_fork	*lft_fork;
	t_fork	*rght_fork;
}	t_philo;

#endif