/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:19:08 by qle-guen          #+#    #+#             */
/*   Updated: 2017/03/01 15:27:21 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../obj.h"

static t_scene		scene = {
	.focal = 46.0,
};

static t_sphere		spheres[] = {
	{ {0,0,0}, 7 },
	{ {19.4, -19.4, 0}, 2.1 },
	{ {-19.4, 19.4, 0}, 2.1 },
	{ {13.1, 5.1, 0}, 1.1 },
	{ { -5.1, -13.1, 0}, 1.1 },
	{ {-30,30,15}, 11},
	{ {15,-30,30}, 6},
	{ {30,15,-30}, 6}
};

#endif
