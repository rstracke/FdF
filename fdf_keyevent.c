/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyevent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:46:04 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 16:18:04 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_keys.h"
#include "fdf_draw.h"

int				key_event(int key, void *param)
{
	t_fdf		*fdf;
	t_camera	*cam;

	fdf = (t_fdf *)param;
	cam = &(fdf->cam);
	if (key == KEY_ESCAPE)
		exit(0);
	if (key == KEY_I)
		cam->projection = ISO;
	else if (key == KEY_P)
		cam->projection = PAR;
	if (key == KEY_SPACEBAR)
	{
		init_camera(&fdf->cam);
		init_iso(fdf);
	}
	else if (rotate_callback(key, cam) + 1 || move_callback(key, cam) + 1
				|| zoom(key, cam) + 1 || extrude(key, cam))
		;
	else
		return (0);
	redraw(fdf);
	return (key);
}
