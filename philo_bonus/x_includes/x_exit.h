/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_exit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:12:29 by svidot            #+#    #+#             */
/*   Updated: 2024/04/05 15:14:00 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X_EXIT_H
# define X_EXIT_H

# include "x_philo_struct.h"

void	add_exit_struct(void *ptr, t_exit_enum ex_en);
void	flush_exit_struct(void);

#endif
