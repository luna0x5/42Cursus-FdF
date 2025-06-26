/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:58:20 by hmoukit           #+#    #+#             */
/*   Updated: 2024/06/21 20:14:26 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_map(t_fdf *fdf, char *file_name)
{
	int	fd;
	int	i;

	fd = open(file_name, O_RDONLY);
	check_open(fd);
	if (!get_columns(&(fdf->map), fd))
	{
		close(fd);
		return ;
	}
	close(fd);
	if (!allocate_matrix(&(fdf->map), &i))
		return ;
	fd = open(file_name, O_RDONLY);
	check_open(fd);
	fill_map(fdf, fd);
	close(fd);
}
