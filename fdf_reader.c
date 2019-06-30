/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:03:24 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 18:34:31 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_reader.h"
#include "fdf.h"

int					read_file_to_array(t_file *file)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	char			*content;

	if ((file->fd = open(file->name, O_RDONLY)) < 0)
		return (-1);
	if (read(file->fd, buff, 0) < 0)
		return (-1);
	content = ft_strnew(0);
	while ((ret = read(file->fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(content, buff);
		free(content);
		content = tmp;
	}
	file->lines = ft_strsplit(content, '\n');
	ft_strdel(&content);
	return (ret);
}

int					check_dim(t_file *file)
{
	int				cur_colls;
	char			**lines;

	if (!file->lines)
		return (0);
	lines = file->lines;
	if (!(file->dim = malloc(2 * sizeof(int))))
		return (0);
	cur_colls = 0;
	file->dim[0] = 0;
	file->dim[1] = 0;
	while (*lines)
	{
		if (file->dim[0] != cur_colls)
			return (0);
		cur_colls = ft_wordscnt(*file->lines, ' ');
		file->dim[0] = file->dim[0] == 0 ? cur_colls : file->dim[0];
		lines++;
		file->dim[1]++;
	}
	return (1);
}

int					check_values(char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	while (ft_isdigit(*s))
		s++;
	if (*s == '\0')
		return (1);
	if (*s != ',')
		return (0);
	s++;
	if (ft_strcmp(s, "0") == 'x')
		return ((unsigned int)ft_atoi_base(s + 2, 16) <= 0xFFFFFF);
	return ((unsigned int)ft_atoi_base(s, 10) <= 0xFFFFFF);
}

void				fill_map(t_file file, t_map *map)
{
	t_point			point;
	int				z;
	unsigned int	c;

	point.y = 0;
	while (point.y < map->height)
	{
		point.x = 0;
		while (point.x < map->width)
		{
			z = file.cells[point.y * file.dim[0] + point.x].field_z;
			map->z_min = z < map->z_min ? z : map->z_min;
			map->z_max = z > map->z_max ? z : map->z_max;
			c = file.cells[point.y * file.dim[0] + point.x].field_c;
			map->points[point.y * map->width + point.x] =
						set_point(point.x, point.y, z, c);
			point.x++;
		}
		point.y++;
	}
	put_color(map);
}

int					init_file(t_file *file, char *name)
{
	int				*val;

	file->name = name;
	if ((read_file_to_array(file) < 0) || !check_dim(file))
		return (0);
	val = file->dim;
	if (!(file->cells = (t_cell *)malloc(val[0] * val[1] * sizeof(t_cell))))
		return (0);
	fill_cells(file);
	return (1);
}
