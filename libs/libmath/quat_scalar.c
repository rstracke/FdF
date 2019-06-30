/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_scalar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:21:47 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 17:22:06 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

t_quat		quat_scalar(t_quat q, t_re k)
{
	t_quat	res;

	res.s = k * q.s;
	res.i = k * q.i;
	res.j = k * q.j;
	res.k = k * q.k;
	return (res);
}