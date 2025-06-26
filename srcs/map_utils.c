/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:17:43 by hmoukit           #+#    #+#             */
/*   Updated: 2024/06/21 22:42:50 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_rows(t_map *data, char *line)
{
	int	i;

	if (!line)
		return ;
	i = 0;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	while (line[i])
	{
		if (line[i] == ' ' && (ft_isdigit(line[i + 1])
				|| line[i + 1] == '-' || line[i + 1] == '+'))
			data->rows++;
		i++;
	}
	if (line[i] == '\0')
		data->rows++;
}

int	get_columns(t_map *data, int fd)
{
	static int	i = 0;
	char		*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->rows = 0;
		get_rows(data, line);
		if (i == 0)
			i = data->rows;
		if (i != data->rows)
		{
			free(line);
			write(2, "Error not rectangular\n", 22);
			exit(1);
		}
		data->columns++;
		free(line);
	}
	return (1);
}

void	draw(t_fdf *fdf, int x, int y)
{
	initialize_pts(fdf);
	check_colors(fdf, x, y);
	extract_rgb(&(fdf->line), &(fdf->pt));
	if (x < fdf->map.rows - 1)
		draw_line(fdf, &(fdf->image), &(fdf->line), &(fdf->pt));
	fdf->initalize.x1 = x * fdf->map.zoom;
	fdf->initalize.y1 = (y + 1) * fdf->map.zoom;
	if (y < fdf->map.columns - 1)
		fdf->pt.z1 = fdf->map.matrix[y + 1][x] * fdf->z_scale;
}

void	draw_color_line(t_fdf *fdf, int x, int y)
{
	fdf->initalize.x0 = x * fdf->map.zoom;
	fdf->initalize.y0 = y * fdf->map.zoom;
	fdf->initalize.x1 = (x + 1) * fdf->map.zoom;
	fdf->initalize.y1 = y * fdf->map.zoom;
	fdf->pt.z0 = fdf->map.matrix[y][x] * fdf->z_scale;
	if (x <= fdf->map.rows - 1 && y <= fdf->map.columns - 1)
	{
		if (x < fdf->map.rows - 1)
			fdf->pt.z1 = fdf->map.matrix[y][x + 1] * fdf->z_scale;
		isometric_projection(&(fdf->initalize.x0),
			&(fdf->initalize.y0), fdf->pt.z0);
		isometric_projection(&(fdf->initalize.x1),
			&(fdf->initalize.y1), fdf->pt.z1);
		draw(fdf, x, y);
		isometric_projection(&(fdf->initalize.x1),
			&(fdf->initalize.y1), fdf->pt.z1);
		initialize_pts(fdf);
		check_colors(fdf, x, y);
		extract_rgb(&(fdf->line), &(fdf->pt));
		if (y < fdf->map.columns - 1)
			draw_line(fdf, &(fdf->image), &(fdf->line), &(fdf->pt));
	}
}

void	draw_map(t_fdf *fdf)
{
	int	x;
	int	y;

	scalling(fdf);
	y = 0;
	while (y < fdf->map.columns)
	{
		x = 0;
		while (x < fdf->map.rows)
		{
			draw_color_line(fdf, x, y);
			x++;
		}
		y++;
	}
	free_2d(fdf->map.matrix, fdf->map.columns);
	free_2d(fdf->map.map_colors, fdf->map.columns);
}
