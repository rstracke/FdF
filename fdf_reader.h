/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:47:38 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 16:51:39 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_READER_H
# define FDF_READER_H

# include "fdf_map.h"

typedef	struct		s_cell
{
	int				field_z;
	unsigned int	field_c;
}					t_cell;

typedef	struct		s_file
{
	char			*name;
	char			**lines;
	int				fd;
	int				*dim;
	t_cell			*cells;
}					t_file;

int					read_file_to_array(t_file *file);
int					check_dim(t_file *file);
int					check_values(char *s);
int					init_file(t_file *file, char *name);
void				fill_map(t_file file, t_map *map);

#endif
