/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:22:50 by hmoukit           #+#    #+#             */
/*   Updated: 2024/06/22 00:11:10 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	int	**matrix;
	int	**map_colors;
	int	columns;
	int	rows;
	int	zoom;
	int	color;
	int	check;
}		t_map;

typedef struct s_img
{
	void	*img;
	char	*add;
	int		bpp;
	int		s_line;
	int		end;
}			t_img;

typedef struct s_line
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	int		red0;
	int		red1;
	int		green0;
	int		green1;
	int		blue0;
	int		blue1;
	float	fraction;
}			t_line;

typedef struct s_point
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	z0;
	int	z1;
	int	color0;
	int	color1;
}		t_point;

typedef struct s_initalize
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}		t_initalize;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_line		line;
	t_img		image;
	t_point		pt;
	t_initalize	initalize;
	int			x_offset;
	int			y_offset;
	int			width;
	int			height;
	float		scale_w;
	float		scale_h;
	float		z_scale;
	float		min;
}				t_fdf;

//some useful functions
void			matrix_failed(int **matrix, int i);
void			free_2d(int **arr, int rows);
int				ft_atoi_base(char *str);
void			put_pixel(t_img	*img, int x, int y, int color);
void			initialize_pts(t_fdf *fdf);

// parsing and error checking functions
int				check_name(char *name);
void			check_open(int fd);

// map functions
int				get_columns(t_map *data, int fd);
int				allocate_matrix(t_map *data, int *i);
void			fill_map(t_fdf *fdf, int fd);
void			read_map(t_fdf *fdf, char *file_name);
void			draw_map(t_fdf *fdf);

// projection and scalling functions
void			isometric_projection(int *x, int *y, int z);
void			scalling(t_fdf *fdf);

// draw functions
void			check_colors(t_fdf *fdf, int x, int y);
void			extract_rgb(t_line *data, t_point *pt);
unsigned int	make_color(t_line *data);
void			cal_fraction(t_line *data, int total_steps, int current_step);
void			draw_line(t_fdf *fdf, t_img *img, t_line *data, t_point *pt);

#endif
