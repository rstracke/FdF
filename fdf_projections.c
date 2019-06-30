/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 09:47:13 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 18:25:55 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_area.h"
#include "fdf_draw.h"
#include <stdio.h>

t_pixel		project(t_point point, t_fdf *fdf)
{
	t_pixel	pixel;

	if (fdf->cam.projection == ISO)
	{
		pixel = point_to_pixel(point, *fdf, 'F');
		pixel.x -= fdf->cam.offset.x + fdf->cam.move.x;
		pixel.y -= fdf->cam.offset.y + fdf->cam.move.y;
	}
	if (fdf->cam.projection == PAR)
	{
		pixel.color = point.color;
		pixel.x = (point.x - point.z)
			* cos(M_PI / 4) * fdf->cam.zoom;
		pixel.y = (point.y - point.z)
			* cos(M_PI / 4) * fdf->cam.zoom;
		pixel.x += WIN_W / 2 -
			fdf->map.width * fdf->cam.zoom / 2 - fdf->cam.move.x;
		pixel.y += WIN_H / 2 -
			fdf->map.height * fdf->cam.zoom / 2 - fdf->cam.move.y;
	}
	return (pixel);
}

static void	set_zoom(t_fdf *fdf)
{
	t_area	area;
	double	w_scale;
	double	h_scale;
	int		*dim;

	area = set_area(*fdf);
	dim = area_size(area);
	w_scale = (double)fdf->mlx.win.width / (double)dim[0];
	h_scale = (double)fdf->mlx.win.height / (double)dim[1];
	if (w_scale > h_scale)
	{
		if (ft_adsf(0.9 * h_scale - 1.) > 0.1)
			fdf->cam.zoom *= (0.9 * h_scale);
	}
	else
	{
		if (ft_adsf(0.9 * w_scale - 1.) > 0.1)
			fdf->cam.zoom *= (0.9 * w_scale);
	}
	free(dim);
}

static void	set_offset(t_fdf *fdf)
{
	t_area	area;
	double	w_scale;
	double	h_scale;
	int		*dim;

	area = set_area(*fdf);
	dim = area_size(area);
	w_scale = (double)fdf->mlx.win.width / (double)dim[0];
	h_scale = (double)fdf->mlx.win.height / (double)dim[1];
	fdf->cam.offset = init_pixel(area.min.x - (fdf->mlx.win.width - dim[0]) / 2,
		area.min.y - (fdf->mlx.win.height - dim[1]) / 2, 0);
	free(dim);
}

void		init_iso(t_fdf *fdf)
{
	set_zoom(fdf);
	set_offset(fdf);
}
