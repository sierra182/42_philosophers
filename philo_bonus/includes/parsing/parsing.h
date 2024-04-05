/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:54:55 by svidot            #+#    #+#             */
/*   Updated: 2024/04/05 14:42:54 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>

int	ft_isoverflow(char *str);
int	ft_atoi(const char *nptr);
int	ft_strlen(const char *s);
int	ft_isdigit(int c);

#endif