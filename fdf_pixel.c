/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:11:55 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 15:49:17 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_pixel.h"

t_pixel		init_pixel(int x, int y, unsigned int color)
{
	t_pixel	pixel;

	pixel.x = x;
	pixel.y = y;
	pixel.color = color;
	return (pixel);
}

int			check_pixel(t_pixel pixel, int width, int height)
{
	return (pixel.x > 0 && pixel.y > 0 && pixel.x < width && pixel.y < height);
}
