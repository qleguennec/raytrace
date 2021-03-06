/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:21:37 by qle-guen          #+#    #+#             */
/*   Updated: 2017/02/28 14:30:45 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

inline void
	normalize
	(t_v3 *v3)
{
	float	l;

	l = length(*v3);
	v3->x /= l;
	v3->y /= l;
	v3->z /= l;
}
