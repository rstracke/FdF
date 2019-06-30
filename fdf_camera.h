/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_camera.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 01:55:27 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 16:47:26 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_CAMERA_H
# define FDF_CAMERA_H

# include "libs/libmath/vector_quat.h"
# include "fdf_pixel.h"

typedef	enum
{
	ISO,
	PAR
}	t_projection;

typedef	struct		s_camera
{
	t_projection	projection;
	int				width;
	int				height;
	double			zoom;
	double			angle;
	double			z_div;
	t_pixel			offset;
	t_vector		axis;
	t_quat			rot;
	t_pixel			move;
}					t_camera;

void				init_camera(t_camera *cam);

#endif
