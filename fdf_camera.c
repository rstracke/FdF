/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 03:29:05 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 14:19:09 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_camera.h"

void	init_camera(t_camera *cam)
{
	cam->zoom = 1.0;
	cam->angle = 0.0;
	cam->z_div = 1.0;
	cam->rot = quat_rot(vector_init(0., 0., 1.), 0);
	cam->move = init_pixel(0, 0, 0);
}
