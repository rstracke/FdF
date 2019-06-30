/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:19:47 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 18:27:21 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_draw.h"

void		draw_line(t_pixel a, t_pixel b, t_fdf *fdf)
{
	t_pixel	delta;
	t_pixel	sign;
	t_pixel	cur;
	int		error[2];

	delta.x = ft_abs(b.x - a.x);
	delta.y = ft_abs(b.y - a.y);
	sign.x = a.x < b.x ? 1 : -1;
	sign.y = a.y < b.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = a;
	while (cur.x != b.x || cur.y != b.y)
	{
		put_pix_img(fdf, cur, get_color(cur, a, b, delta));
		if ((error[1] = error[0] << 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			cur.y += sign.y;
			error[0] += delta.x;
		}
	}
}

void		draw_menu(t_fdf *fdf)
{
	int		n;
	char	s[15][50];
	int		delta_y;
	t_pixel	p;

	n = 0;
	ft_strcpy(s[n++], "	AXIS	|	MOVE			|	ROTATE	|");
	ft_strcpy(s[n++], "---------+-------------------+-----------|");
	ft_strcpy(s[n++], "	X		|	ARROW R/L		|	1 / 3	|");
	ft_strcpy(s[n++], s[1]);
	ft_strcpy(s[n++], "	Y		|	ARROW UP/DOWN	|	4 / 6	|");
	ft_strcpy(s[n++], s[1]);
	ft_strcpy(s[n++], "	Z		|	- / +			|	7 / 9	|");
	ft_strcpy(s[n++], "---------+-------------------+-----------|");
	ft_strcpy(s[n++], "Change view : I / P");
	ft_strcpy(s[n++], "Reset zoom : Space");
	delta_y = 11;
	p = init_pixel(5, delta_y * (n - 1), 0xFFFFFF);
	while (n--)
	{
		mlx_string_put(fdf->mlx.mlx_ptr,
			fdf->mlx.win.win_ptr, p.x, p.y, p.color, s[n]);
		p.y -= delta_y;
	}
}

void		draw(t_fdf *fdf)
{
	t_point	p;
	t_pixel	pixel;

	p.y = -1;
	while (++p.y < fdf->map.height)
	{
		p.x = -1;
		while (++p.x < fdf->map.width)
		{
			pixel = project(get_point(p.x, p.y, fdf), fdf);
			if (p.x != fdf->map.width - 1)
				draw_line(pixel,
							project(get_point(p.x + 1, p.y, fdf), fdf), fdf);
			if (p.y != fdf->map.height - 1)
				draw_line(pixel,
							project(get_point(p.x, p.y + 1, fdf), fdf), fdf);
		}
	}
	draw_img(fdf->mlx.mlx_ptr, fdf->mlx.win.win_ptr, fdf->mlx.img);
	draw_menu(fdf);
}

void		redraw(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx.mlx_ptr, fdf->mlx.img.img_ptr);
	fdf->mlx.img =
		init_img(fdf->mlx.mlx_ptr, fdf->mlx.win.width, fdf->mlx.win.height);
	draw(fdf);
}
