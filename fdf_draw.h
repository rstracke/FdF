/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:27:19 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 16:46:35 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DRAW_H
# define FDF_DRAW_H

# include "fdf.h"
# include "fdf_pixel.h"

void	draw_line(t_pixel f, t_pixel s, t_fdf *fdf);
void	draw(t_fdf *fdf);
void	redraw(t_fdf *fdf);

#endif
