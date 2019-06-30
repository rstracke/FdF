/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_unit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:28:27 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 17:28:41 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_unit(t_vector v)
{
	t_re	mod;

	mod = vector_mod(v);
	return (vector_scalar(v, 1.0 / mod));
}