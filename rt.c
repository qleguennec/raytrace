/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:58:21 by qle-guen          #+#    #+#             */
/*   Updated: 2017/02/27 13:49:08 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int
	main
	(void)
{
	t_rt	rt;
	int		ox;

	rt.mlx.mlx = mlx_init();
	rt.mlx.img = mlx_new_image(rt.mlx.mlx, WIDTH, HEIGHT);
	rt.mlx.pix = (int *)mlx_get_data_addr(rt.mlx.img, &ox, &ox, &ox);
	rt.mlx.win = mlx_new_window(rt.mlx.mlx, WIDTH, HEIGHT, TITLE);
	mlx_loop_hook(rt.mlx.mlx, (int (*)(void))&rt_loop, &rt);
	mlx_hook(rt.mlx.win, DestroyNotify, StructureNotifyMask
		, (int (*)(void))&rt_exit, &rt);
	mlx_hook(rt.mlx.win, KeyPress, 0, &rt_ev_keyboard, &rt);
	rt.update = true;
	mlx_loop(rt.mlx.mlx);
}
