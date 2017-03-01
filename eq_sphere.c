/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eq_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:56:09 by qle-guen          #+#    #+#             */
/*   Updated: 2017/03/01 15:34:56 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

bool
	eq_sphere
	(t_v3 e
	, t_v3 d
	, t_sphere s
	, float *hit)
{
	float	d2;
	float	dv;
	float	sq;
	t_v3	v;

	v = sub(e, s.center);
	dv = dot(d, v);
	d2 = dot(d, d);
	sq = dv * dv - d2 * (dot(v, v) - s.radius * s.radius);
	if (sq < 1e-6)
		return (false);
	*hit = 0;
	return (true);
}
