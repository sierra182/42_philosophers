/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:42:46 by seblin            #+#    #+#             */
/*   Updated: 2024/03/23 12:13:12 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

void *routine(void *data)
{
	printf("je suis le nouveau tread!\n");
}	

int	main(int argc, char *argv[])
{
	pthread_t tid;
	
	printf("hello world!\n");
	tid = pthread_create(&tid, NULL, routine, NULL);
	

	return (0);
}