/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:52:40 by qle-guen          #+#    #+#             */
/*   Updated: 2017/03/02 13:31:58 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static bool
	eq_sphere
	(t_v3 e
	, t_v3 d
	, t_sphere *s
	, t_obj *closest)
{
	float	d2;
	float	dv;
	float	sq;
	float	dist;
	t_v3	v;

	v = sub(e, s->center);
	dv = dot(d, v);
	d2 = dot(d, d);
	sq = dv * dv - d2 * (dot(v, v) - s->radius * s->radius);
	if (sq < 1e-6)
		return (false);
	sq = sqrt(sq);
	dist = (-dv - sq) / d2;
	if (dist < 1e-6 || dist >= closest->dist)
		return (false);
	closest->dist = dist;
	closest->type = OBJ_SPHERE;
	closest->obj = s;
	return (true);
}

void
	ray_hit_sphere
	(t_v3 e
	, t_v3 d
	, t_obj *closest)
{
	size_t	i;
	size_t	n;

	n = sizeof(spheres) / sizeof(*spheres);
	i = 0;
	while (i < n)
		eq_sphere(e, d, (t_sphere *)spheres + i++, closest);
}
