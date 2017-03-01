/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_v1_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 14:17:40 by qle-guen          #+#    #+#             */
/*   Updated: 2017/02/28 14:37:10 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float
	dot
	(t_v3 a
	, t_v3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

float
	length
	(t_v3 a)
{
	return (sqrt(dot(a, a)));
}