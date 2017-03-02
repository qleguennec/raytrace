/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 09:57:29 by qle-guen          #+#    #+#             */
/*   Updated: 2017/03/02 09:59:48 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_v3
	sub
	(t_v3 a
	, t_v3 b)
{
	return (V3(a.x - b.x, a.y - b.y, a.z - b.z));
}
