/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:52:09 by seblin            #+#    #+#             */
/*   Updated: 2024/03/24 11:35:53 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <unistd.h>

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

int is_philo_error(char *n_philo)
{	
	return (!is_digit_arg(n_philo) || ft_isoverflow(n_philo)
		|| ft_atoi(n_philo) <= 0);
}
int is_arg_error(char *arg)
{	
	return (!is_digit_arg(arg) || ft_isoverflow(arg)
		|| ft_atoi(arg) < 0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void	display_error(char *str)
{
	write(2, str, ft_strlen(str));
}
int	check_argv(int argc, char *argv[])
{
	int	i;

	if (argc <= 4 || argc > 6)	
		return (display_error("Arg number must be four or five!\n"), 1);			
	if (is_philo_error(*++argv))	
		return (display_error("Philosophers number is not valid!\n"), 1);
	i = 1;
	while (argv[i])
	{
		if (is_arg_error(argv[i]))	
			return (display_error("Arg is not valid!\n"), 1);		
		i++;	
	}
	return (0);
}
