/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:52:09 by seblin            #+#    #+#             */
/*   Updated: 2024/04/05 14:17:58 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	display_error(char *str)
{
	write(2, str, ft_strlen(str));
}

static int	is_digit_arg(char *arg)
{
	while (*arg)
		if (!ft_isdigit(*arg++))
			return (0);
	return (1);
}

static int	is_philo_error(char *n_philo)
{
	return (!is_digit_arg(n_philo) || ft_isoverflow(n_philo)
		|| ft_atoi(n_philo) <= 0);
}

static int	is_arg_error(char *arg)
{
	return (!is_digit_arg(arg) || ft_isoverflow(arg)
		|| ft_atoi(arg) < 0);
}

int	parsing(int argc, char *argv[])
{
	int	i;

	if (argc <= 4 || argc > 6)
		return (display_error("Arg number must be four or five.\n"), 1);
	if (is_philo_error(*++argv))
		return (display_error("Philosophers number is not valid.\n"), 1);
	i = 1;
	while (argv[i])
	{
		if (is_arg_error(argv[i]))
			return (display_error("Arg is not valid.\n"), 1);
		i++;
	}
	if (argv[4] && *argv[4] == '0')
		return (1);
	return (0);
}
