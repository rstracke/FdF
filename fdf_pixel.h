/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pixel.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:10:15 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 16:48:17 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PIXEL_H
# define FDF_PIXEL_H

typedef	struct		s_pixel
{
	int				x;
	int				y;
	unsigned int	color;
}					t_pixel;

t_pixel				init_pixel(int x, int y, unsigned int color);
int					check_pixel(t_pixel pixel, int width, int height);
#endif
