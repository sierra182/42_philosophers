/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:37:50 by seblin            #+#    #+#             */
/*   Updated: 2024/03/29 12:18:16 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	philo_think(t_philo *philo)
{
	say_on_shared_microphone(philo, "is thinking\n");
}

void	philo_sleep(t_philo *philo)
{
	if (say_on_shared_microphone(philo, "is sleeping\n"))
		return ;
	usleep(philo->data->sleep_time * 1000);	
}



void	*philo_routine(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *) arg;
	while (1)
	{	
		if (philo->data->end_needed)
			break;
		if (philo_eat(philo))
			return (NULL);
		if (philo->data->end_needed)
			break;
		philo_sleep(philo);
		if (philo->data->end_needed)
			break;
		philo_think(philo);
	}
}