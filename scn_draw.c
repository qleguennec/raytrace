/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:33:30 by qle-guen          #+#    #+#             */
/*   Updated: 2017/02/27 16:23:07 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int
	get_pixel_color
	(t_v3 d)
{
	bool	set;
	float	t;
	float	tmin;
	size_t	nsph;
	t_obj	hit;

	nsph = sizeof(spheres) / sizeof(*spheres);
	set = false;
	while (nsph)
	{
		if (eq_sphere(d, spheres[nsph], &t))
		{
			if (!set && (set = true))
				tmin = t;
			else if (t < tmin)
			{
				tmin = t;
				hit.obj = spheres + nsph;
				hit.type = OBJ_CIRCLE;
			}
		}
		nsph--;
	}
	return (set ? 0xffffff : 0);
}

void
	scn_draw
	(t_rt *rt)
{
	size_t	i;
	size_t	j;
	t_v3	d;

	j = 0;
	(void)rt;
	d.z = scene.focal;
	while (j < H)
	{
		i = 0;
		while (i < W)
		{
			d.x = W_2 + i - 0.5;
			d.y = j + 0.5 - H_2;
			v3_normalize(&d);
			rt->mlx.pix[j * WIDTH + i] = get_pixel_color(d);
			i++;
		}
		j++;
	}
}
