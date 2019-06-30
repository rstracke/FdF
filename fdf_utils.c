/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:19:26 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 18:35:01 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			*cell_to_int(char *cell)
{
	int		*val;
	char	**fields;

	if (!(val = (int *)malloc(2 * sizeof(int))))
		return (NULL);
	fields = ft_strsplit(cell, ',');
	val[0] = ft_atoi_base(fields[0], 10);
	if (!fields[1])
		val[1] = 0xFFFFFF;
	else
		val[1] = ft_atoi_base(fields[1] + 2, 16);
	ft_mem2del((void ***)&fields, 2);
	return (val);
}

void		pass_data_to_struct(char *data, t_cell *cell)
{
	int		*vals;

	vals = cell_to_int(data);
	cell->field_z = vals[0];
	cell->field_c = (unsigned int)vals[1];
	free(vals);
}

void		ft_clear(char ***s)
{
	char	**str;

	str = *s;
	while (*str)
		ft_strdel(str++);
	ft_memdel((void **)s);
}

void		fill_cells(t_file *file)
{
	int		i;
	char	**cells;
	char	**tmp_cells;
	char	**tmp_lines;

	i = 0;
	tmp_lines = file->lines;
	while (*file->lines)
	{
		cells = ft_strsplit(*(file->lines), ' ');
		tmp_cells = cells;
		while (*tmp_cells)
		{
			if (!check_values(*tmp_cells))
				exit(0);
			pass_data_to_struct(*(tmp_cells++), &file->cells[i++]);
		}
		ft_clear(&cells);
		file->lines++;
	}
	ft_clear(&tmp_lines);
}
