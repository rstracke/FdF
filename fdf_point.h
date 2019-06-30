/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:20:28 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 16:48:29 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_POINT_H
# define FDF_POINT_H

typedef	struct		s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}					t_point;

void				init_point(t_point *point);
t_point				set_point(int x, int y, int z, unsigned int color);
t_point				get_point(int x, int y, void *f);

#endif
