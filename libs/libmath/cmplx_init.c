/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmplx_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:10:24 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 17:11:07 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

t_cmplx		cmplx_init(t_re re, t_im im)
{
	t_cmplx	z;

	z.re = re;
	z.im = im;
	return (z);
}
