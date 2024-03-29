/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:37:50 by seblin            #+#    #+#             */
/*   Updated: 2024/03/29 10:37:53 by seblin           ###   ########.fr       */
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

int	even_philo_get_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->rght_fork->mutex);
	if (philo->data->end_needed)
	{
		pthread_mutex_unlock(&philo->rght_fork->mutex);	
		return (1);
	}
	if (iam_actually_dead(philo))
	{
		pthread_mutex_unlock(&philo->rght_fork->mutex);
		return (say_on_shared_microphone(philo, "died\n"), 1);
	}
	if (say_on_shared_microphone(philo, "has taken a fork\n"))
	{
		pthread_mutex_unlock(&philo->rght_fork->mutex);
		return (1);
	}
	pthread_mutex_lock(&philo->lft_fork->mutex);
	if (philo->data->end_needed)
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);
		pthread_mutex_unlock(&philo->rght_fork->mutex);	
		return (1);
	}
	if (iam_actually_dead(philo))
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);
		pthread_mutex_unlock(&philo->rght_fork->mutex);
		return (say_on_shared_microphone(philo, "died\n"), 1);
	}
	if (say_on_shared_microphone(philo, "has taken a fork\n"))
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);
		pthread_mutex_unlock(&philo->rght_fork->mutex);
		return (1);
	}
}

int	odd_philo_get_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->lft_fork->mutex);	
	if (philo->data->end_needed)
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);	
		return (1);
	}
	if (iam_actually_dead(philo))
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);
		return (say_on_shared_microphone(philo, "died\n"), 1);
	}
	say_on_shared_microphone(philo, "has taken a fork\n");
	pthread_mutex_lock(&philo->rght_fork->mutex);
	if (philo->data->end_needed)
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);
		pthread_mutex_unlock(&philo->rght_fork->mutex);	
		return (1);
	}
	if (iam_actually_dead(philo))
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);
		pthread_mutex_unlock(&philo->rght_fork->mutex);
		return (say_on_shared_microphone(philo, "died\n"), 1);
	}
	if (say_on_shared_microphone(philo, "has taken a fork\n"))
	{
		pthread_mutex_unlock(&philo->lft_fork->mutex);
		pthread_mutex_unlock(&philo->rght_fork->mutex);
		return (1);
	}
}

void	update_last_meal(t_philo *philo)
{
	gettimeofday(&philo->last_meal, NULL);	
}

int	is_odd(t_philo *philo)
{
	return (philo->id % 2);
}

int	philo_eat(t_philo *philo)
{	
	if (is_odd(philo))
	{		
		if (odd_philo_get_forks(philo))
		{				
			return (1);
		}
	}
	else if	(even_philo_get_forks(philo))
		return (1);
	update_last_meal(philo);
	if (iam_actually_dead(philo))
		return (say_on_shared_microphone(philo, "died\n"), 1);		
	say_on_shared_microphone(philo, "is eating\n");
	usleep(philo->data->eat_time * 1000);		
	pthread_mutex_unlock(&philo->lft_fork->mutex);
	pthread_mutex_unlock(&philo->rght_fork->mutex);
	return (0);	
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