/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:27:10 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 17:27:26 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_quat.h"

t_vector	vector_rot(t_vector v, t_quat rot)
{
	t_quat	q;

	q = quat_prod(quat_prod(rot, vector_to_quat((t_re)0.0, v)), quat_conj(rot));
	return (quat_to_vector(q));
}