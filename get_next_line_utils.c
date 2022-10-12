/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelippe <sfelippe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:10:18 by sfelippe          #+#    #+#             */
/*   Updated: 2022/10/12 03:32:07 by sfelippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (c > 127)
		c = c % 256;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	else
		return (NULL);
}

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;

	new = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	j;
	size_t			max;

	if (!s)
		return (NULL);
	max = ft_strlen(s);
	if (start > max)
		return (NULL);
	if (len >= max)
		len = max - start;
	substring = malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	j = 0;
	while (s[start] != '\0' && j < len)
	{
		substring[j] = (char) s[start];
		start++;
		j++;
	}
	substring[j] = '\0';
	return (substring);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		size_new;
	int		i1;
	int		i2;

	size_new = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	new = malloc((size_new + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i1 = 0;
	while (s1 && s1[i1] != '\0')
	{
		new[i1] = s1[i1];
		i1++;
	}
	i2 = 0;
	while (s2[i2] != '\0')
		new[i1++] = s2[i2++];
	if (s1)
		free ((char *)s1);
	new[i1] = '\0';
	return (new);
}
