/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:56:12 by hmoukit           #+#    #+#             */
/*   Updated: 2024/05/31 13:49:27 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi_base(char *line)
{
	int		result;
	int		i;
	char	c;

	result = 0;
	i = 0;
	i += 2;
	while (line[i] && line[i] != ' ')
	{
		c = ft_tolower(line[i]);
		if (c >= '0' && c <= '9')
			result = result * 16 + (c - '0');
		else if (c >= 'a' && c <= 'f')
			result = result * 16 + (c - 'a' + 10);
		else
			break ;
		i++;
	}
	return (result);
}
