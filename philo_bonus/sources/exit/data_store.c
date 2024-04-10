/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_store.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:35:28 by seblin            #+#    #+#             */
/*   Updated: 2024/04/10 10:06:01 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_store.h"

// void	store_and_free_tids(t_exit *exit, void *tids)
// {
// 	if (exit && tids)
// 		exit->tids = (pthread_t *) tids;
// 	else if (exit && exit->tids)
// 	{
// 		free(exit->tids);
// 		exit->tids = NULL;
// 	}
// }

// void	store_and_free_forks(t_exit *exit, void *forks)
// {
// 	int	i;

// 	if (exit && forks)
// 		exit->forks = (t_fork *) forks;
// 	else if (exit && exit->forks)
// 	{
// 		i = -1;
// 		while (++i < exit->data->n_philo)
// 			pthread_mutex_destroy(&exit->forks[i].mutex);
// 		free(exit->forks);
// 		exit->forks = NULL;
// 	}
// }
char	*ft_strjoin(char const *s1, char const *s2);//!
char	*ft_strjoin_up(char *s1, char *s2, int s1_free, int s2_free);
char	*ft_itoa(int n);//!
void	store_and_free_philos(t_exit *exit, void *philos)
{
	int		i;
	char	*name;
	
	if (exit && philos)
		exit->philos = (t_philo *) philos;
	else if (exit && exit->philos)
	{	
		i = -1;
		while (++i < exit->data->n_philo)
		{
			sem_close(exit->philos[i].sem_last_meal);
			name = ft_strjoin_up("/sem_last_meal", ft_itoa(exit->philos[i].id), 0, 1);
			sem_unlink(name);
			free(name);
			sem_close(exit->philos[i].sem_end_needed);
			name = ft_strjoin_up("/sem_end_needed", ft_itoa(exit->philos[i].id), 0, 1);
			sem_unlink(name);
			free(name);
		}
		free(exit->philos);
		exit->philos = NULL;	
	}
}

void	store_and_free_data(t_exit *exit, void *data)
{
	if (exit && data)
		exit->data = data;
	else if (exit && exit->data)
	{
		sem_close(exit->data->sem_death);
		sem_unlink("/sem_death");
		sem_close(exit->data->sem_death_notice);
		sem_unlink("/sem_death_notice");
		sem_close(exit->data->sem_mic);
		sem_unlink("/sem_mic");
		sem_close(exit->data->sem_forks);
		sem_unlink("/sem_forks");		
		free(exit->data);
		exit->data = NULL;
	}
}
