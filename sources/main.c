/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:42:46 by seblin            #+#    #+#             */
/*   Updated: 2024/03/24 13:50:55 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
int	check_argv(int argc, char *argv[]);

void *routine(void *data)
{
	printf("je suis le nouveau tread!\n");
}	

int	main(int argc, char *argv[])
{
	pthread_t tid;
	
	if (check_argv(argc, argv))
		return (1);
	printf("hello world!\n");
	pthread_create(&tid, NULL, routine, NULL);
	pthread_join(tid, NULL);

	return (0);
}