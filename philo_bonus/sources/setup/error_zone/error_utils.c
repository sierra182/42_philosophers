/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:34:39 by seblin            #+#    #+#             */
/*   Updated: 2024/03/24 13:23:07 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_utils.h"

void	display_error(char *str)
{
	write(2, str, ft_strlen(str));
}

int	is_digit_arg(char *arg)
{
	while (*arg)
		if (!ft_isdigit(*arg++))
			return (0);
	return (1);
}

int	ft_isoverflow(char *str)
{
	long	nbr;
	int		isneg;

	nbr = 0;
	isneg = 0;
	if (*str == '-' && ++isneg)
		str++;
	else if (*str == '+')
		str++;
	while (*str)
	{
		nbr = nbr * 10 + *str++ - 48;
		if (nbr - isneg > INT_MAX)
			return (1);
	}
	return (0);
}
