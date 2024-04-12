/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:34:39 by seblin            #+#    #+#             */
/*   Updated: 2024/04/05 14:17:08 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
		res = res * 10 + *nptr++ - 48;
	return (res * sign);
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
