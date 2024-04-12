/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:41:39 by svidot            #+#    #+#             */
/*   Updated: 2024/04/10 11:54:07 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include <stdlib.h>
# include <fcntl.h>
# include "x_philo_struct.h"
# include "x_exit.h"

void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
char	*ft_strjoin_up(char *s1, char *s2, int s1_free, int s2_free);

#endif