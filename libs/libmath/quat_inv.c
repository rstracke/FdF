/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_inv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:20:06 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 17:20:29 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

t_quat	quat_inv(t_quat q)
{
	t_re	mod;

	mod = quat_mod(q);
	return (quat_scalar(quat_conj(q), 1.0 / mod));
}