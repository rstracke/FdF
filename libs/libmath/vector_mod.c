/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:26:15 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 17:26:22 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_re	vector_mod(t_vector v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}