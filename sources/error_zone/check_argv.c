/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:52:09 by seblin            #+#    #+#             */
/*   Updated: 2024/03/24 13:22:26 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_argv.h"

int	is_philo_error(char *n_philo)
{
	return (!is_digit_arg(n_philo) || ft_isoverflow(n_philo)
		|| ft_atoi(n_philo) <= 0);
}

int	is_arg_error(char *arg)
{
	return (!is_digit_arg(arg) || ft_isoverflow(arg)
		|| ft_atoi(arg) < 0);
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
