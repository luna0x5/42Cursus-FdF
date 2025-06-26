/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:22:42 by hmoukit           #+#    #+#             */
/*   Updated: 2024/06/23 14:01:53 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize(t_fdf *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->image.img = NULL;
	data->image.add = NULL;
	data->image.bpp = 0;
	data->image.s_line = 0;
	data->image.end = 0;
	data->map.map_colors = NULL;
	data->map.rows = 0;
	data->map.columns = 0;
	data->map.check = 0;
	data->width = 1080;
	data->height = 1080;
	data->pt.x0 = 0;
	data->pt.y0 = 0;
	data->pt.x1 = 0;
	data->pt.y1 = 0;
	data->pt.z0 = 0;
	data->pt.z1 = 0;
	data->map.color = 0;
}

void	mlx_inialized(t_fdf *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		perror("Error initializing mlx");
		exit(1);
	}
	data->win = mlx_new_window(data->mlx, data->width, data->height, "fdf");
	if (!data->win)
	{
		perror("Error creating window");
		exit(1);
	}
	data->image.img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->image.img)
	{
		perror("Error creating image");
		exit(1);
	}
	data->image.add = mlx_get_data_addr(data->image.img, &(data->image.bpp),
			&(data->image.s_line), &(data->image.end));
	if (!data->image.add)
	{
		perror("Error getting image address");
		exit(1);
	}
}

int	handle_keypress(int keysym, t_fdf *data)
{
	if (keysym == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_image(data->mlx, data->image.img);
		exit(0);
	}
	return (0);
}

int	handle_close(t_fdf *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->image.img);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	data;

	if (ac != 2)
	{
		perror("less or more arguments");
		exit(1);
	}
	if (!check_name(av[1]))
	{
		perror("Error file name");
		exit(1);
	}
	initialize(&data);
	mlx_inialized(&data);
	read_map(&data, av[1]);
	draw_map(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.image.img, 0, 0);
	mlx_key_hook(data.win, handle_keypress, &data);
	mlx_hook(data.win, 17, 0, handle_close, &data);
	mlx_loop(data.mlx);
}
