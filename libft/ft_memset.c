/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:23:49 by hmoukit           #+#    #+#             */
/*   Updated: 2023/11/22 16:09:14 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	n;
	char			*a;
	size_t			i;

	n = (unsigned char)c;
	a = (char *)b;
	i = 0;
	while (i < len)
	{
		a[i] = n;
		i++;
	}
	return (b);
}
