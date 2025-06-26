/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:51:43 by hmoukit           #+#    #+#             */
/*   Updated: 2023/11/24 18:31:21 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*srce;

	i = 0;
	dest = (char *)dst;
	srce = (char *)src;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		dest[i] = srce[i];
		i++;
	}
	return (dst);
}
