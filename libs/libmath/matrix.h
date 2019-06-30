/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:17:58 by rstracke          #+#    #+#             */
/*   Updated: 2019/04/13 17:18:28 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

typedef struct	s_matrix
{
	int			width;
	int			height;
	double		**data;
}				t_matrix;

t_matrix		matrix_init(int width, int height);

#endif