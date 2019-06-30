/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:22:30 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 16:01:15 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_transform.h"

t_pixel			point_to_pixel(t_point point, t_fdf fdf, char flag)
{
	t_vector	v;
	t_pixel		p;
	double		zoom;

	if (flag == 'F')
		zoom = fdf.cam.zoom;
	else
		zoom = 1.;
	v = vector_init((double)point.x, (double)point.y,
						(double)point.z * fdf.cam.z_div);
	v = vector_rot(v, fdf.cam.rot);
	p.x = (int)((v.x - v.y) * zoom);
	p.y = (int)((v.x / 2 + v.y / 2 - v.z) * zoom);
	p.color = point.color;
	return (p);
}

void			rotation(t_camera *cam, t_vector axis, double angle)
{
	cam->rot = quat_prod(cam->rot, quat_rot(axis, angle));
}
