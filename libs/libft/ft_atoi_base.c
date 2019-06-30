/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:14:04 by rstracke          #+#    #+#             */
/*   Updated: 2019/03/30 21:27:17 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_atoi_base(const char *s, unsigned int base)
{
    unsigned char   c;
    long            res;
    int             sign;

    while (*s == ' ' || *s == '\t' || *s == '\n'
            || *s == '\r' || *s == '\v' || *s == '\f')
            s++;
    if ((sign = (*s == '-')) && (base != 10))
        return (0);
    if (*s == '-' || *s == '+')
        s++;
    res = 0;
    while (*s)
    {
        c = (unsigned char)*s++;
        if (c >= 'A' && c <= 'Z')
            c += ('a' - 'A');
        c = (c >= '0' && c <= '9') ? c - '0' : c - 'a' + 10;
        if (c >= base)
            return ((int)(sign ? -res : res));
        res = base * res + c;
    }
    return ((int)(sign ? -res : res));
}