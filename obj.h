/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:13:56 by qle-guen          #+#    #+#             */
/*   Updated: 2017/02/27 16:16:39 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# define P2(x) (x * x)

# define V3(x, y, z) ((t_v3){(x), (y), (z)})
# define DOT(a, b) (a.x * b.x + a.y + b.y * a.z * b.z)
# define SCL(a, x) V3(a.x * x, a.y * x, a.z * x)
# define DIFF(a, b)	V3(a.x - b.x, a.y - b.y, a.z - b.y)

# define OBJ_CIRCLE 0

typedef struct		s_v3
{
	float			x;
	float			y;
	float			z;
}					t_v3;

typedef struct		s_obj
{
	void			*obj;
	int				type;
}					t_obj;

typedef struct		s_scene
{
	float			focal;
}					t_scene;

typedef struct		s_sphere
{
	t_v3			center;
	float			radius;
}					t_sphere;

#endif
