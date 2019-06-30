/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_graphics.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:00:04 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 17:04:23 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_GRAPHICS_H
# define MLX_GRAPHICS_H

# ifndef WIN_W
#  define WIN_W 1280
# endif

# ifndef WIN_H
#  define WIN_H 720
# endif

# include "minilibx_macos/mlx.h"
# include "fdf_pixel.h"

typedef	struct		s_img
{
	void			*img_ptr;
	unsigned int	*data;
	int				size_line;
	int				end;
	int				bits_per_pixel;
	int				width;
	int				height;
}					t_img;

typedef	struct		s_win
{
	void			*win_ptr;
	char			*title;
	int				width;
	int				height;
}					t_win;

typedef	struct		s_mlx
{
	void			*mlx_ptr;
	int				width;
	int				height;
	t_img			img;
	t_win			win;
}					t_mlx;

t_mlx				init_mlx(void *mlx, int width, int height);
t_win				init_win(t_mlx *mlx, char *title, int width, int height);
t_img				init_img(void *mlx, int width, int height);
int					draw_img(void *mlx, void *win, t_img img);
int					put_pix_img(void *f, t_pixel p, unsigned int color);

#endif
