/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:33:32 by hmoukit           #+#    #+#             */
/*   Updated: 2023/11/24 18:30:50 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*srce;
	size_t		i;

	i = 0;
	dest = (char *)dst;
	srce = (const char *)src;
	if (dest == srce)
		return (dst);
	if (dest < srce)
		ft_memcpy(dest, srce, len);
	else
	{
		while (i < len)
		{
			dest[len - i - 1] = srce[len - i - 1];
			i++;
		}
	}
	return (dst);
}
