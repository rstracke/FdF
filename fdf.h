/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:11:09 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 18:48:18 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include "libs/libft/libft.h"
# include "libs/libmath/vector.h"
# include "libs/libft/libft.h"
# include "libs/libmath/vector_quat.h"

# include "fdf_map.h"
# include "fdf_reader.h"
# include "fdf_pixel.h"
# include "fdf_point.h"

# include "fdf_camera.h"
# include "mlx_graphics.h"

# ifndef BUFF_SIZE
#  define BUFF_SIZE 1000
# endif

# ifndef A_STEP
#  define A_STEP (M_PI / 18.)
# endif

# ifndef M_STEP
#  define M_STEP 5
# endif

# ifndef Z_STEP
#  define Z_STEP 1.1
# endif

typedef	struct	s_fdf
{
	t_file		file;
	t_map		map;
	t_camera	cam;
	t_mlx		mlx;
}				t_fdf;

void			init_iso(t_fdf *fdf);
t_pixel			project(t_point point, t_fdf *fdf);
void			put_color(t_map *map);
int				get_color(t_pixel dot_curr, t_pixel dot0, t_pixel dot1,
															t_pixel delta);

int				key_event(int key, void *param);
int				rotate_callback(int key, t_camera *cam);
int				move_callback(int key, t_camera *cam);
int				zoom(int key, t_camera *cam);
int				extrude(int key, t_camera *cam);
int				close_fdf(void);

int				*cell_to_int(char *cell);
void			pass_data_to_struct(char *data, t_cell *cell);
void			ft_clear(char ***s);
void			fill_cells(t_file *file);

#endif
