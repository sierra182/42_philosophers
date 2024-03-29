/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_exit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:10:54 by seblin            #+#    #+#             */
/*   Updated: 2024/03/29 14:13:09 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X_EXIT_H
# define X_EXIT_H

# include "x_philo_struct.h"

void	add_exit_struct(void *ptr, t_exit_enum ex_en);
void	flush_exit_struct(void);

#endif