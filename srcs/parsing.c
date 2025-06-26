/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:26:54 by hmoukit           #+#    #+#             */
/*   Updated: 2024/06/21 19:49:03 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_name(char *name)
{
	char	*s;
	int		i;
	int		j;

	s = ".fdf";
	i = 0;
	j = 0;
	while (name[i] != '.' && name[i])
		i++;
	if (name[i] == '\0')
		return (0);
	while (s[j] && name[i])
	{
		if (name[i] != s[j])
			return (0);
		i++;
		j++;
	}
	if (!name[i] && !s[j])
		return (1);
	return (0);
}

void	check_open(int fd)
{
	if (fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
}
