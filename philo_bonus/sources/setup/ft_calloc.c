/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:15:30 by seblin            #+#    #+#             */
/*   Updated: 2024/04/10 11:34:01 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_calloc.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_uc;

	s_uc = (unsigned char *) s;
	while (n--)
		*s_uc++ = (unsigned char) c;
	return (s);
}

static void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size && nmemb * size / size != nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
