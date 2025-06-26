/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:16:12 by hmoukit           #+#    #+#             */
/*   Updated: 2024/06/22 00:10:26 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen_gnl(char *s);
char	*ft_strdup_gnl(char *s1);
char	*ft_strndup_gnl(char *s1, size_t len);
char	*ft_strcpy_gnl(char *dst, char *src);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*read_line(int fd);
char	*rest_buffer(char *buffer);
char	*make_line(char **buffer);
char	*get_next_line(int fd);

#endif