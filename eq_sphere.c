/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eq_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:56:09 by qle-guen          #+#    #+#             */
/*   Updated: 2017/02/27 16:02:32 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

bool
	eq_sphere
	(t_v3 d
	, t_sphere sph
	, float *hit)
{
	float	a;
	float	b;
	float	c;
	float	delta;

	a = DOT(d, d);
	b = 2 * d.x * (- sph.center.x)
		+ 2 * d.y * (- sph.center.y)
		+ 2 * d.z * (- sph.center.z);
	c = DOT(sph.center, sph.center) - P2(sph.radius);
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (false);
	*hit = (DOT(d, sph.center) + sqrt(delta)) / DOT(d, d);
	return (true);
}
