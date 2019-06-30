/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmplx_conj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:09:43 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 17:10:02 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

t_cmplx		cmplx_conj(t_cmplx z)
{
	return (cmplx_init(z.re, -z.im));
}