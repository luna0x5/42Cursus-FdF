/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:07:22 by hmoukit           #+#    #+#             */
/*   Updated: 2024/04/08 12:24:17 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, char *src)
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*s;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
	{
		s2 = ft_strdup(s1);
		free(s1);
		return (s2);
	}
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s = malloc(s1len + s2len + 1);
	if (s == NULL)
		return (free(s1), s1 = NULL, NULL);
	ft_strcpy(s, s1);
	ft_strcpy(s + s1len, s2);
	if (s1)
		free(s1);
	return (s);
}
