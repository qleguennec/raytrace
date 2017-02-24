/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:13:56 by qle-guen          #+#    #+#             */
/*   Updated: 2017/02/24 14:29:35 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

#define F3(x, y, z) ((t_f3){x, y, z})

typedef struct		s_f3
{
	float			x;
	float			y;
	float			z;
}					t_f3;

typedef struct		s_sphere
{
	t_f3			center;
	float			radius;
}					t_sphere;

#endif
