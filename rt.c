/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:58:21 by qle-guen          #+#    #+#             */
/*   Updated: 2017/02/24 14:22:07 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <X11/Xlib.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "scenes/test.h"

static int
	events
	(XEvent e
	, Display *d
	, Window w
	, XImage *img)
{
	if (e.type == KeyPress)
		return (0);
	if (e.type == ClientMessage)
		return (0);
	if (e.type == Expose)
		XPutImage(d, w, DefaultGC(d, 0), img, 0, 0, 0, 0, WIDTH, HEIGHT);
	return (1);
}

static XImage
	*draw
	(Display *d)
{
	int		*img;
	size_t	i;

	img = malloc(sizeof(*img) * WIDTH * HEIGHT);
	i = 0;
	while (i < WIDTH * HEIGHT)
		img[i++] = 0xffffff;
	return (XCreateImage(d
		, DefaultVisual(d, 0), 24, ZPixmap, 0, (char *)img, WIDTH, HEIGHT, 32, 0));
}

int
	main
	(void)
{
	Display		*d;
	Window		w;
	XEvent		e;
	XImage		*img;

	d = XOpenDisplay(NULL);
	w = XCreateSimpleWindow(d, RootWindow(d, 0), 100, 100, WIDTH, HEIGHT
		, 1, 0, 0xffffff);
	img = draw(d);
	Atom delWindow = XInternAtom( d, "WM_DELETE_WINDOW", 0 );
	XSetWMProtocols(d , w, &delWindow, 1);
	XSelectInput(d, w, ExposureMask | KeyPressMask);
	XMapWindow(d, w);
	while (42)
	{
		XNextEvent(d, &e);
		if (!events(e, d, w, img))
			break ;
	}
	XDestroyWindow(d, w);
	XCloseDisplay(d);
	return (0);
}
