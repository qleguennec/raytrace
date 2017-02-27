/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 12:03:14 by qle-guen          #+#    #+#             */
/*   Updated: 2017/02/27 15:49:57 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int
	rt_loop
	(t_rt *rt)
{
	if (!rt->update)
		return (0);
	rt->update = false;
	scn_draw(rt);
	mlx_put_image_to_window(rt->mlx.mlx, rt->mlx.win, rt->mlx.img, 0, 0);
	return (1);
}
