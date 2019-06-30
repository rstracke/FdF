/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:31:33 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 16:48:03 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MAP_H
# define FDF_MAP_H

# include "fdf_point.h"

typedef	struct	s_map
{
	char		*name;
	int			width;
	int			height;
	t_point		*points;
	int			z_min;
	int			z_max;
}				t_map;

int				init_map(int *size, t_map *map, char *name);
void			print_map(t_map map);

#endif
