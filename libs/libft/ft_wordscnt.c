/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:36:07 by rstracke          #+#    #+#             */
/*   Updated: 2019/03/30 21:37:28 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordscnt(char const *s, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (*(s + i))
	{
		while (*(s + i) == c)
			i++;
		if (*(s + i) != c && *(s + i) != '\0')
			count++;
		while (*(s + i) != c && *(s + i) != '\0')
			i++;
	}
	return (count);
}