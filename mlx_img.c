/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:56:34 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 17:05:48 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "mlx_graphics.h"
#include "fdf.h"

int					draw_img(void *mlx, void *win, t_img img)
{
	return (mlx_put_image_to_window(mlx, win, img.img_ptr, 0, 0));
}

int					put_pix_img(void *f, t_pixel p, unsigned int color)
{
	t_fdf			*fdf;

	fdf = (t_fdf *)f;
	p.color = color;
	if ((p.y < fdf->mlx.img.height) && (p.y > 0) &&
		(p.x < fdf->mlx.img.width) && (p.x > 0))
		fdf->mlx.img.data[(int)p.y * fdf->mlx.img.width + (int)p.x] = color;
	return (1);
}
