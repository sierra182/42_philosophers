/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_philo_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:57:26 by seblin            #+#    #+#             */
/*   Updated: 2024/03/24 14:08:06 by seblin           ###   ########.fr       */
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

#endif