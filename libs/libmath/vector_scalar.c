/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scalar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:27:31 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 17:27:51 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector		vector_scalar(t_vector v, t_re k)
{
	t_vector	w;

	w.x = k * v.x;
	w.y = k * v.y;
	w.z = k * v.z;
	return (w);
}