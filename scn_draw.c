/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:33:30 by qle-guen          #+#    #+#             */
/*   Updated: 2017/03/02 14:15:55 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int
	get_pixel_color
	(t_v3 e
	, t_v3 d)
{
	t_obj	closest;

	closest.dist = 1e6;
	ray_hit_sphere(e, d, &closest);
	//ray_hit_plane(e, d, &closest);
	if (closest.type == OBJ_SPHERE)
		return (0xFF0);
//	if (closest.type == OBJ_PLANE)
//		return (0xFFFFFF);
	return (0);
}

void
	scn_draw
	(t_rt *rt)
{
	size_t	i;
	size_t	j;
	t_v3	d;

	j = 0;
	while (j < H)
	{
		i = 0;
		while (i < W)
		{
			d.x = (float)i / W - 0.5;
			d.y = (float)j / H - 0.5;
			d.z = scene.focal;
			normalize(&d);
			rt->mlx.pix[j * WIDTH + i]
				= get_pixel_color(scene.eye, d);
			i++;
		}
		j++;
	}
}
