/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:52:09 by seblin            #+#    #+#             */
/*   Updated: 2024/03/23 19:13:53 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
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
int	is_overflow(char *str)
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

int check_n_philo(char *n_philo)
{	
	return (is_overflow(n_philo) || ft_atoi(n_philo) <= 0);
}

int	check_argv(char *argv[])
{
	if (check_n_philo(*(argv + 1)))
	{
		printf("problemo!\n");
	}
	else 
		printf("no problemo!\n");
}