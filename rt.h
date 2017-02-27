/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:05:06 by qle-guen          #+#    #+#             */
/*   Updated: 2017/02/27 15:56:18 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# define WIDTH 1200
# define HEIGHT 800
# define W WIDTH
# define H HEIGHT
# define W_2 (W / 2)
# define H_2 (H / 2)
# define TITLE "rt"

# include <Events.h>
# include <X.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# include "scenes/test.h"

typedef struct		s_mlx
{
	void			*mlx;
	void			*img;
	void			*win;
	int				*pix;
}					t_mlx;

typedef struct		s_rt
{
	t_mlx			mlx;
	bool			update : 1;
}					t_rt;

int					rt_ev_keyboard(int key, t_rt *rt);
int					rt_loop(t_rt *rt);
void				rt_exit(t_rt *rt);

float				v3_dot(t_v3 a, t_v3 b);
float				v3_length(t_v3 v3);
void				v3_normalize(t_v3 *v3);

void				scn_draw(t_rt *rt);

bool				eq_sphere(t_v3 d, t_sphere sph, float *hit);

#endif
