/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:22:01 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 16:51:17 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TRANSFORM_H
# define FDF_TRANSFORM_H
# include "fdf.h"

t_pixel	point_to_pixel(t_point point, t_fdf fdf, char flag);
void	rotation(t_camera *cam, t_vector axis, double angle);

#endif
