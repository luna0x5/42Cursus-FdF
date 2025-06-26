/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:18:45 by hmoukit           #+#    #+#             */
/*   Updated: 2024/06/14 05:04:10 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_gnl(char *s1)
{
	size_t	len;
	char	*dst;
	size_t	i;

	if (!s1)
		return (NULL);
	len = ft_strlen_gnl(s1);
	dst = malloc(len + 1);
	if (dst == NULL)
		return (s1 = NULL, NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strndup_gnl(char *s1, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s1)
		return (NULL);
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i] && i < len)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strcpy_gnl(char *dst, char *src)
{
	size_t	i;

	if (!src || !dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	char	n;
	char	*s1;
	int		i;

	if (!s)
		return (NULL);
	n = (char)c;
	s1 = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s1[i] == n)
			return (&s1[i]);
		i++;
	}
	if (n == '\0')
		return (&s1[i]);
	return (NULL);
}
