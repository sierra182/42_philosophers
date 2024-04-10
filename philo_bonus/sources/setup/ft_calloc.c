/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:15:30 by seblin            #+#    #+#             */
/*   Updated: 2024/04/10 10:04:00 by seblin           ###   ########.fr       */
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
int	ft_strlen(const char *s);//!
char	*ft_strjoin(char const *s1, char const *s2)//!
{
	size_t	s1_len;
	size_t	s2_len;
	char	*s3;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = (char *) malloc(sizeof (char) * (s1_len + s2_len + 1));
	if (!s3)
		return (NULL);
	while (*s1)
		*s3++ = *s1++;
	while (*s2)
		*s3++ = *s2++;
	*s3 = '\0';
	return (s3 - s2_len - s1_len);
}
char	*ft_strjoin_up(char *s1, char *s2, int s1_free, int s2_free)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = (char *) malloc(sizeof (char) * (s1_len + s2_len + 1));
	if (!s3)
		return (NULL);
	while (*s1)
		*s3++ = *s1++;
	while (*s2)
		*s3++ = *s2++;
	*s3 = '\0';
	if (s1_free)
		free(s1 - s1_len);
	if (s2_free)
		free(s2 - s2_len);
	return (s3 - s2_len - s1_len);
}