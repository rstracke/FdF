/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_callback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:47:36 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 18:43:13 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_transform.h"
#include "fdf_draw.h"
#include "fdf_keys.h"

int			rotate_callback(int key, t_camera *cam)
{
	if (key == KEY_PAD_1)
		rotation(cam, vector_init(1., 0., 0.), -A_STEP);
	else if (key == KEY_PAD_3)
		rotation(cam, vector_init(1., 0., 0.), +A_STEP);
	else if (key == KEY_PAD_4)
		rotation(cam, vector_init(0., 1., 0.), -A_STEP);
	else if (key == KEY_PAD_6)
		rotation(cam, vector_init(0., 1., 0.), +A_STEP);
	else if (key == KEY_PAD_7)
		rotation(cam, vector_init(0., 0., 1.), -A_STEP);
	else if (key == KEY_PAD_9)
		rotation(cam, vector_init(0., 0., 1.), +A_STEP);
	else
		return (-1);
	return (key);
}

int			move_callback(int key, t_camera *cam)
{
	double	m_step;

	m_step = M_STEP;
	if (key == KEY_UP)
		cam->move.y += m_step;
	else if (key == KEY_DOWN)
		cam->move.y -= m_step;
	else if (key == KEY_LEFT)
		cam->move.x += m_step;
	else if (key == KEY_RIGHT)
		cam->move.x -= m_step;
	else
		return (-1);
	return (key);
}

int			zoom(int key, t_camera *cam)
{
	double	z_step;

	z_step = Z_STEP;
	if (key == KEY_EQUAL)
		cam->zoom = cam->zoom * z_step;
	else if (key == KEY_MINUS)
		cam->zoom = cam->zoom / z_step;
	else
		return (-1);
	return (key);
}

int			extrude(int key, t_camera *cam)
{
	double	z_step;

	z_step = Z_STEP;
	if (key == KEY_PAD_ADD)
		cam->z_div = cam->z_div * z_step;
	else if (key == KEY_PAD_SUB)
		cam->z_div = cam->z_div / z_step;
	else
		return (-1);
	return (key);
}

int			close_fdf(void)
{
	exit(0);
	return (0);
}
