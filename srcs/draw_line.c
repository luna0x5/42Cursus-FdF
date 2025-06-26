/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:25:08 by hmoukit           #+#    #+#             */
/*   Updated: 2024/06/14 00:58:11 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	total_stps(t_point *data)
{
	int	total_steps;

	total_steps = 0;
	if (abs(data->x1 - data->x0) > abs(data->y1 - data->y0))
		total_steps = abs(data->x1 - data->x0);
	else
		total_steps = abs(data->y1 - data->y0);
	return (total_steps);
}

static void	looping_line(t_img *img, t_line *data, t_fdf *fdf)
{
	int	total_steps;
	int	current_step;

	total_steps = total_stps(&(fdf->pt));
	current_step = 0;
	while (1)
	{
		cal_fraction(&(fdf->line), total_steps, current_step);
		fdf->map.color = make_color(&(fdf->line));
		put_pixel(img, fdf->pt.x0, fdf->pt.y0, fdf->map.color);
		if (fdf->pt.x0 == fdf->pt.x1 && fdf->pt.y0 == fdf->pt.y1)
			break ;
		data->e2 = data->err;
		if (data->e2 > data->dx * -1)
		{
			data->err -= data->dy;
			fdf->pt.x0 += data->sx;
		}
		if (data->e2 < data->dy)
		{
			data->err += data->dx;
			fdf->pt.y0 += data->sy;
		}
		current_step++;
	}
}

void	draw_line(t_fdf *fdf, t_img *img, t_line *data, t_point *pt)
{
	data->dx = abs(pt->x1 - pt->x0);
	data->dy = abs(pt->y1 - pt->y0);
	data->sx = -1;
	if (pt->x0 < pt->x1)
		data->sx = 1;
	data->sy = -1;
	if (pt->y0 < pt -> y1)
		data->sy = 1;
	data->err = (data->dy * -1) / 2;
	if (data->dx > data->dy)
		data->err = data->dx / 2;
	looping_line(img, data, fdf);
}
