/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:42:06 by seblin            #+#    #+#             */
/*   Updated: 2024/03/30 18:57:36 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include <stdlib.h>
# include "x_philo_struct.h"
# include "x_philo_utils.h"
# include "x_init.h"
# include "x_exit.h"

void	*ft_calloc(size_t nmemb, size_t size);
void	*philo_routine(void *arg);

#endif