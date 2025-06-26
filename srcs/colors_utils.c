/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:15:45 by hmoukit           #+#    #+#             */
/*   Updated: 2024/06/21 19:01:12 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	extract_rgb(t_line *data, t_point *pt)
{
	data->red0 = (pt->color0 >> 16) & 0xFF;
	data->green0 = (pt->color0 >> 8) & 0xFF;
	data->blue0 = pt->color0 & 0xFF;
	data->red1 = (pt->color1 >> 16) & 0xFF;
	data->green1 = (pt->color1 >> 8) & 0xFF;
	data->blue1 = pt->color1 & 0xFF;
}

unsigned int	make_color(t_line *data)
{
	int	r;
	int	g;
	int	b;

	r = data->red0 + (data->red1 - data->red0) * data->fraction;
	g = data->green0 + (data->green1 - data->green0) * data->fraction;
	b = data->blue0 + (data->blue1 - data->blue0) * data->fraction;
	return ((r << 16) | (g << 8) | b);
}

void	cal_fraction(t_line *data, int total_steps, int current_step)
{
	if (total_steps == 0)
		data->fraction = 0.0;
	else
		data->fraction = (float)current_step / total_steps;
}

void	initialize_pts(t_fdf *fdf)
{
	fdf->pt.x0 = fdf->initalize.x0 + fdf->x_offset;
	fdf->pt.y0 = fdf->initalize.y0 + fdf->y_offset;
	fdf->pt.x1 = fdf->initalize.x1 + fdf->x_offset;
	fdf->pt.y1 = fdf->initalize.y1 + fdf->y_offset;
}

void	check_colors(t_fdf *fdf, int x, int y)
{
	fdf->pt.color0 = 0x0000FF;
	if (fdf->pt.z0 != 0)
		fdf->pt.color0 = 0x008080;
	fdf->pt.color1 = 0x0000FF;
	if (fdf->pt.z1 != 0)
		fdf->pt.color1 = 0x008080;
	if (fdf->map.check)
	{
		if (fdf->map.map_colors[y][x] != 0x000000)
			fdf->pt.color0 = fdf->map.map_colors[y][x];
		if (fdf->map.map_colors[y][x + 1] != 0x000000)
			fdf->pt.color1 = fdf->map.map_colors[y][x + 1];
	}
}
