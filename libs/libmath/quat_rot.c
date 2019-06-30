/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:21:41 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 17:21:42 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_quat.h"
#include <math.h>

t_quat		quat_rot(t_vector axis, t_re angle)
{
	t_re	cos_a;
	t_re	sin_a;

	cos_a = (t_re)cos(angle / (t_re)2.0);
	sin_a = (t_re)sin(angle / (t_re)2.0);
	return (vector_to_quat(cos_a, vector_scalar(vector_unit(axis), sin_a)));
}