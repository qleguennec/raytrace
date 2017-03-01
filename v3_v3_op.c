/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_v3_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 14:05:33 by qle-guen          #+#    #+#             */
/*   Updated: 2017/02/28 14:36:36 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"

t_v3
	add
	(t_v3 a
	, t_v3 b)
{
	return (V3(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_v3
	sub
	(t_v3 a
	, t_v3 b)
{
	return (V3(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_v3
	mult
	(t_v3 a
	, t_v3 b)
{
	return (V3(a.x * b.x, a.y * b.y, a.z * b.z));
}

t_v3
	scale
	(float x
	, t_v3 a)
{
	return (V3(x * a.x, x * a.y, x * a.z));
}

t_v3
	apply_mat
	(float *mat
	, t_v3 a)
{
	return (V3(a.x * mat[0] + a.y * mat[1] + a.z * mat[2]
		, a.x * mat[3] + a.y * mat[4] + a.z * mat[5]
		, a.x * mat[6] + a.y * mat[7] + a.z * mat[8]));
}
