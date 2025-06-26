/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:45:04 by hmoukit           #+#    #+#             */
/*   Updated: 2024/06/21 16:05:51 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	matrix_failed(int **matrix, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		free(matrix[j]);
		j++;
	}
	free(matrix);
}

void	free_2d(int **arr, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	put_pixel(t_img	*img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 1080 && y >= 0 && y < 1080)
	{
		dst = img->add + (y * img->s_line + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	isometric_projection(int *x, int *y, int z)
{
	int	previous_x;

	previous_x = *x;
	*x = (previous_x - *y) * cos(0.523599);
	*y = (previous_x + *y) * sin(0.523599) - z;
}

void	scalling(t_fdf *fdf)
{
	int	new_mapw;
	int	new_maph;

	fdf->scale_w = fdf->width / (float)fdf->map.rows;
	fdf->scale_h = fdf->height / (float)fdf->map.columns;
	fdf->min = fdf->scale_h;
	if (fdf->scale_w < fdf->scale_h)
		fdf->min = fdf->scale_w;
	fdf->map.zoom = fdf->min / 2.0;
	fdf->z_scale = fdf->map.zoom * 0.5;
	new_mapw = fdf->map.rows * fdf->map.zoom;
	new_maph = fdf->map.columns * fdf->map.zoom;
	fdf->x_offset = (fdf->width - new_mapw);
	fdf->y_offset = (fdf->height - new_maph) * 0.5;
}
