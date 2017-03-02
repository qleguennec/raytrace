/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:13:03 by qle-guen          #+#    #+#             */
/*   Updated: 2017/03/02 13:31:53 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static bool
	eq_plane
	(t_v3 e
	, t_v3 d
	, t_plane *p
	, t_obj *closest)
{
	float	dv;
	float	d2;
	float	dist;

	dv = dot(scale(-1, p->normal), d);
	if (dv > -1e-6)
		return (false);
	d2 = dot(p->normal, e);
	dist = (d2 + p->offset) / dv;
	if (dist < 1e-6 || dist >= closest->dist)
		return (false);
	closest->dist = dist;
	closest->type = OBJ_PLANE;
	closest->obj = p;
	return (true);
}

void
	ray_hit_plane
	(t_v3 e
	, t_v3 d
	, t_obj *closest)
{
	size_t	i;
	size_t	n;

	n = sizeof(planes) / sizeof(*planes);
	i = 0;
	while (i < n)
		eq_plane(e, d, (t_plane *)planes + i++, closest);
}
