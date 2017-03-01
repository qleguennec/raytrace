/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:13:56 by qle-guen          #+#    #+#             */
/*   Updated: 2017/02/28 14:08:18 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# define V3(x, y, z) ((t_v3){(x), (y), (z)})

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
