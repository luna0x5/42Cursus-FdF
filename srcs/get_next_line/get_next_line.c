/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:19:14 by hmoukit           #+#    #+#             */
/*   Updated: 2024/04/24 16:15:21 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*s;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup_gnl(s2));
	if (s2 == NULL)
	{
		s2 = ft_strdup_gnl(s1);
		return (free(s1), s2);
	}
	s1len = ft_strlen_gnl(s1);
	s2len = ft_strlen_gnl(s2);
	s = malloc(s1len + s2len + 1);
	if (s == NULL)
		return (free(s1), s1 = NULL, NULL);
	ft_strcpy_gnl(s, s1);
	ft_strcpy_gnl(s + s1len, s2);
	if (s1)
		free(s1);
	return (s);
}

char	*read_line(int fd)
{
	ssize_t	count;
	char	*all_buffer;
	char	*buffer;

	count = 1;
	all_buffer = NULL;
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return ((char *)1);
	while (count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
			return (free(buffer), buffer = NULL, (char *)1);
		buffer[count] = '\0';
		if (count == 0)
			break ;
		all_buffer = ft_strjoin_gnl(all_buffer, buffer);
		if (!all_buffer)
			return (free(buffer), buffer = NULL, (char *)1);
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	return (free(buffer), buffer = NULL, all_buffer);
}

char	*rest_buffer(char *buffer)
{
	char	*srch;

	if (!buffer)
		return (NULL);
	srch = ft_strchr_gnl(buffer, '\n');
	if (!srch)
		return (free(buffer), buffer = NULL, NULL);
	if (*(srch + 1) == '\0')
		return (free(buffer), buffer = NULL, NULL);
	buffer = ft_strcpy_gnl(buffer, srch + 1);
	if (buffer[0] == '\0')
		return (free(buffer), buffer = NULL, NULL);
	return (buffer);
}

char	*make_line(char **buffer)
{
	char	*line;
	char	*tmp;

	line = NULL;
	if (!*buffer || !buffer)
		return (NULL);
	tmp = ft_strchr_gnl(*buffer, '\n');
	if (!tmp)
	{
		line = ft_strdup_gnl(*buffer);
		return (free(*buffer), *buffer = NULL, line);
	}
	if (*(tmp + 1) == '\0')
	{
		line = ft_strdup_gnl(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	else
	{
		line = ft_strndup_gnl(*buffer, tmp - *buffer + 1);
		if (!line)
			return (free(*buffer), *buffer = NULL, NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;

	line = NULL;
	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer)
			return (free(buffer), buffer = NULL, NULL);
		return (NULL);
	}
	temp = read_line(fd);
	if (temp == (char *)1)
	{
		if (buffer)
			return (free(buffer), buffer = NULL, NULL);
		return (NULL);
	}
	buffer = ft_strjoin_gnl(buffer, temp);
	if (!buffer)
		return (free(temp), temp = NULL, NULL);
	line = make_line(&buffer);
	buffer = rest_buffer(buffer);
	return (free(temp), temp = NULL, line);
}
