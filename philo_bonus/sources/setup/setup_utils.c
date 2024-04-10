/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:32:52 by svidot            #+#    #+#             */
/*   Updated: 2024/04/10 11:34:07 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *s);

char	*ft_strdup(const char *s)
{
	char	*s_dup;
	size_t	s_len;

	s_len = ft_strlen(s);
	s_dup = (char *) malloc(sizeof(char) * (s_len + 1));
	if (!s_dup)
		return (NULL);
	while (*s)
		*s_dup++ = *s++;
	*s_dup = '\0';
	return (s_dup - s_len);
}

static int	ft_digitlen(int n)
{
	int	i;

	i = 1;
	while (n > 9 && i++)
		n /= 10;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		is_neg;
	int		i;

	is_neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0 && ++is_neg)
		n = -n;
	i = ft_digitlen(n);
	s = (char *) malloc(sizeof (char) * (i + is_neg + 1));
	if (!s)
		return (NULL);
	s[i + is_neg] = '\0';
	while (i-- + is_neg)
	{
		s[i + is_neg] = n % 10 + 48;
		n /= 10;
	}
	if (is_neg)
		*s = '-';
	return (s);
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