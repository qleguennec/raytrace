/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:33:30 by qle-guen          #+#    #+#             */
/*   Updated: 2017/03/01 15:56:16 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int
	get_pixel_color
	(t_v3 e
	, t_v3 d)
{
	bool	set;
	float	t;
	float	tmin;
	size_t	nsph;
	t_obj	hit;

	nsph = sizeof(spheres) / sizeof(*spheres);
	set = false;
	while (--nsph)
	{
		if (eq_sphere(e, d, spheres[nsph], &t))
		{
			printf("ok\n");
			return (0xff00);
			if (!set && (set = true))
				tmin = t;
			else if (t < tmin)
			{
				tmin = t;
				hit.obj = spheres + nsph;
				hit.type = OBJ_CIRCLE;
			}
		}
	}
	return (0Xff);
}

void
	scn_draw
	(t_rt *rt)
{
	size_t	i;
	size_t	j;
	t_v3	d;
	t_v3	e;

	j = 0;
	e = V3(0, 0, 16);
	while (j < H)
	{
		i = 0;
		while (i < W)
		{
			d.x = (float)i / W - 0.5;
			d.y = (float)j / H - 0.5;
			d.x *= 4.0/3.0;
			d.z = scene.focal;
			normalize(&d);
			rt->mlx.pix[j * WIDTH + i] = get_pixel_color(e, d);
			i++;
		}
		j++;
	}
}
