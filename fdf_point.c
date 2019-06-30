/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:27:41 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 15:49:59 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_point.h"
#include "fdf.h"

void		init_point(t_point *point)
{
	point->x = 0;
	point->y = 0;
	point->z = 0;
	point->color = 0xFFFFFF;
}

t_point		set_point(int x, int y, int z, unsigned int color)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color = color;
	return (point);
}

t_point		get_point(int x, int y, void *f)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)f;
	return (fdf->map.points[y * fdf->map.width + x]);
}
