/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_to_quat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:28:06 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 17:28:21 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_quat.h"

t_quat		vector_to_quat(t_re s, t_vector v)
{
	t_quat	q;

	q.s = s;
	q.i = v.x;
	q.j = v.y;
	q.k = v.z;
	return (q);
}