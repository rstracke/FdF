/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:36:41 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 18:32:44 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map.h"
#include <stdlib.h>

int		init_map(int *size, t_map *map, char *name)
{
	int	i;

	i = 0;
	map->width = size[0];
	map->height = size[1];
	map->name = name;
	map->z_max = 0;
	map->z_min = 0;
	if (!(map->points =
			(t_point *)malloc(map->width * map->height * sizeof(t_point))))
		return (0);
	while (i < map->width * map->height)
		init_point(&map->points[i++]);
	return (1);
}
