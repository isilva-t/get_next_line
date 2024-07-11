/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:27:10 by isilva-t          #+#    #+#             */
/*   Updated: 2024/05/14 13:13:32 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *line, unsigned int start, size_t len)
{
	char			*array;
	unsigned int	i;

	if (!line)
		return (NULL);
	if (ft_strlen(line) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(line) - start)
		len = ft_strlen(line) - start;
	array = malloc(sizeof(char) * len + 1);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (len--)
		array[i++] = line[start++];
	array[i] = '\0';
	return (array);
}

char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	dst = malloc(sizeof(char) * len + 1);
	if (!dst)
		return (0);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *line, char const *buf)
{
	size_t	i;
	size_t	j;
	char	*join;

	i = 0;
	j = 0;
	join = malloc(ft_strlen(line) + ft_strlen(buf) + 1);
	if (!line || !buf || !join)
		return (NULL);
	join [0] = '\0';
	while (line[i])
		join[i++] = line[j++];
	j = 0;
	while (buf[j])
		join[i++] = buf[j++];
	join[i] = '\0';
	return (join);
}
