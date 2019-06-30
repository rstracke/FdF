/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_area.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:37:57 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 16:47:12 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_AREA_H
# define FDF_AREA_H

# include "fdf.h"
# include "fdf_transform.h"

typedef	struct	s_area
{
	t_pixel		min;
	t_pixel		max;
}				t_area;

t_area			set_area(t_fdf fdf);
t_area			init_area(t_pixel pix_min, t_pixel pix_max);
int				area_resize(t_area *area, t_pixel p);
int				*area_size(t_area area);

#endif
