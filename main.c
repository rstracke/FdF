/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:49:27 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 18:42:52 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_draw.h"

static void	init_graphics(t_fdf *fdf)
{
	fdf->mlx = init_mlx(mlx_init(), WIN_W, WIN_H);
	fdf->mlx.win = init_win(&fdf->mlx, fdf->file.name,
		fdf->mlx.width, fdf->mlx.height);
	fdf->mlx.img = init_img(fdf->mlx.mlx_ptr,
		fdf->mlx.win.width, fdf->mlx.win.height);
	init_camera(&fdf->cam);
	init_iso(fdf);
}

int			main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		exit(0);
	if (!init_file(&fdf.file, argv[1]))
	{
		perror("File error");
		exit(0);
	}
	if (!init_map(fdf.file.dim, &fdf.map, fdf.file.name))
	{
		perror("Map error");
		exit(0);
	}
	fill_map(fdf.file, &fdf.map);
	init_graphics(&fdf);
	draw(&fdf);
	mlx_hook(fdf.mlx.win.win_ptr, 2, 0, key_event, &fdf);
	mlx_hook(fdf.mlx.win.win_ptr, 17, 0, close_fdf, &fdf);
	mlx_loop(fdf.mlx.mlx_ptr);
	return (0);
}
