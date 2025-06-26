/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:30:38 by hmoukit           #+#    #+#             */
/*   Updated: 2024/06/21 23:13:25 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_map(int i, int j, char *line, t_fdf *fdf)
{
	int	k;

	k = 0;
	while (line[k] && ft_isdigit(line[k]))
		k++;
	if (line[k] == ',')
	{
		fdf->map.check = 1;
		k++;
		fdf->map.map_colors[i][j] = ft_atoi_base(&line[k]);
	}
	else
		fdf->map.map_colors[i][j] = ft_atoi_base("0x000000");
	while (line[k] && line[k] != ' ')
		k++;
	while (line[k] && line[k] == ' ')
		k++;
}

void	fill_matrix(int *matrix, char *line)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(line, ' ');
	if (!tmp)
		exit(1);
	while (tmp[i] && tmp[i][0] != '\n')
	{
		matrix[i] = ft_atoi(tmp[i]);
		free(tmp[i]);
		i++;
	}
	if (tmp[i] && tmp[i][0] == '\n')
		free(tmp[i]);
	free(tmp);
}

void	loop_color(char **tmp, int i, int j, t_fdf *fdf)
{
	while (tmp[j] && tmp[j][0] != '\n')
	{
		get_map(i, j, tmp[j], fdf);
		free(tmp[j]);
		j++;
	}
	if (tmp[j] && tmp[j][0] == '\n')
		free(tmp[j]);
}

void	fill_map(t_fdf *fdf, int fd)
{
	char	*line;
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	while (i < fdf->map.columns)
	{
		j = 0;
		line = get_next_line(fd);
		if (!line)
			exit(1);
		fill_matrix(fdf->map.matrix[i], line);
		tmp = ft_split(line, ' ');
		if (!tmp)
			exit(1);
		loop_color(tmp, i, j, fdf);
		free(tmp);
		free(line);
		i++;
	}
}

int	allocate_matrix(t_map *data, int *i)
{
	data->matrix = (int **)malloc(data->columns * sizeof(int *));
	if (!data->matrix)
		return (0);
	data->map_colors = (int **)malloc(data->columns * sizeof(int *));
	if (!data->map_colors)
		return (0);
	*i = 0;
	while (*i < data->columns)
	{
		data->matrix[*i] = (int *)malloc(data->rows * sizeof(int));
		if (!data->matrix[*i])
		{
			matrix_failed(data->matrix, *i);
			return (0);
		}
		data->map_colors[*i] = (int *)malloc(data->rows * sizeof(int));
		if (!data->map_colors[*i])
		{
			matrix_failed(data->map_colors, *i);
			return (0);
		}
		(*i)++;
	}
	return (1);
}
