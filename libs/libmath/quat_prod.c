/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_prod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:20:52 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 17:21:14 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

t_quat		quat_prod(t_quat q1, t_quat q2)
{
	t_quat	q;

	q.s = q1.s * q2.s - q1.i * q2.i - q1.j * q2.j - q1.k * q2.k;
	q.i = q1.j * q2.k - q2.j * q1.k + q1.s * q2.i + q1.i * q2.s;
	q.j = q1.k * q2.i - q2.k * q1.i + q1.s * q2.j + q1.j * q2.s;
	q.k = q1.i * q2.j - q2.i * q1.j + q1.s * q2.k + q1.k * q2.s;
	return (q);
}

