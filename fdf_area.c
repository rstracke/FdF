/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_area.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:41:31 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 15:49:35 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_area.h"

int			is_area(t_area area, t_pixel pixel)
{
	return (!(pixel.x < area.min.x || pixel.x > area.max.x
			|| pixel.y < area.min.y || pixel.y > area.max.y));
}

int			area_resize(t_area *area, t_pixel pixel)
{
	if (is_area(*area, pixel))
		return (0);
	if (pixel.x < area->min.x)
		area->min.x = pixel.x;
	else if (pixel.x > area->max.x)
		area->max.x = pixel.x;
	if (pixel.y < area->min.y)
		area->min.y = pixel.y;
	else if (pixel.y > area->max.y)
		area->max.y = pixel.y;
	return (1);
}

t_area		init_area(t_pixel pix_min, t_pixel pix_max)
{
	t_area	area;

	if (pix_min.x > pix_max.x)
	{
		area.min.x = pix_max.x;
		area.max.x = pix_min.x;
	}
	else
	{
		area.min.x = pix_min.x;
		area.max.x = pix_max.x;
	}
	if (pix_min.y > pix_max.y)
	{
		area.min.y = pix_max.y;
		area.max.y = pix_min.y;
	}
	else
	{
		area.min.y = pix_min.y;
		area.max.y = pix_max.y;
	}
	return (area);
}

t_area		set_area(t_fdf fdf)
{
	int		x;
	int		y;
	t_pixel	pixel;
	t_area	area;

	y = 0;
	while (y < fdf.map.height)
	{
		x = 0;
		while (x < fdf.map.width)
		{
			pixel = point_to_pixel(get_point(x, y, &fdf), fdf, 'F');
			if (x || y)
				area_resize(&area, pixel);
			else
				area = init_area(pixel, pixel);
			x++;
		}
		y++;
	}
	return (area);
}

int			*area_size(t_area area)
{
	int		*dim;

	dim = (int *)malloc(2 * sizeof(int));
	dim[0] = area.max.x - area.min.x;
	dim[1] = area.max.y - area.min.y;
	return (dim);
}
