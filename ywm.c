/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ywm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 05:25:52 by mmoussou          #+#    #+#             */
/*   Updated: 2024/01/24 20:39:38 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ywm.h"

static t_wm	g_ywm;

void	window_drag(int xdiff, int ydiff)
{
	if (g_ywm.start.button == 1)
	{
		if (g_ywm.start.button == 3)
			XMoveResizeWindow(g_ywm.display, g_ywm.start.subwindow,
				g_ywm.attributes.x + xdiff, g_ywm.attributes.y + ydiff,
				max(1, g_ywm.attributes.width + xdiff),
				max(1, g_ywm.attributes.height + ydiff));
		else
			XMoveResizeWindow(g_ywm.display, g_ywm.start.subwindow,
				g_ywm.attributes.x + xdiff, g_ywm.attributes.y + ydiff,
				max(1, g_ywm.attributes.width),
				max(1, g_ywm.attributes.width));
	}
	else
	{
		if (g_ywm.start.button == 3)
			XMoveResizeWindow(g_ywm.display, g_ywm.start.subwindow,
				g_ywm.attributes.x + 0, g_ywm.attributes.y + 0,
				max(1, g_ywm.attributes.width + xdiff),
				max(1, g_ywm.attributes.height + ydiff));
		else
			XMoveResizeWindow(g_ywm.display, g_ywm.start.subwindow,
				g_ywm.attributes.x + 0, g_ywm.attributes.y + 0,
				max(1, g_ywm.attributes.width),
				max(1, g_ywm.attributes.width));
	}
}

void	wm_loop(void)
{
	int		xdiff;
	int		ydiff;

	while (69 != 420)
	{
		ft_printf("loop\n");
		XNextEvent(g_ywm.display, &(g_ywm.event));
		ft_printf("caca\n");
		if (g_ywm.event.type == KeyPress)
			break ;
		if (g_ywm.event.type == ButtonPress
			&& g_ywm.event.xbutton.subwindow != None)
		{
			XGetWindowAttributes(g_ywm.display, g_ywm.event.xbutton.subwindow,
				&g_ywm.attributes);
			g_ywm.start = g_ywm.event.xbutton;
		}
		else if (g_ywm.event.type == MotionNotify
			&& g_ywm.start.subwindow != None)
		{
			xdiff = g_ywm.event.xbutton.x_root - g_ywm.start.x_root;
			ydiff = g_ywm.event.xbutton.y_root - g_ywm.start.y_root;
			window_drag(xdiff, ydiff);
		}
		else if (g_ywm.event.type == ButtonRelease)
			g_ywm.start.subwindow = None;
	}
}

int	main(void)
{
	g_ywm.display = XOpenDisplay(NULL);
	if (!g_ywm.display)
	{
		ft_printf("Cant open display.");
		return (1);
	}
	g_ywm.root = XDefaultRootWindow(g_ywm.display);
	XGrabKey(g_ywm.display, XKeysymToKeycode(g_ywm.display,
			XStringToKeysym("F1")), Mod4Mask, g_ywm.root,
		false, GrabModeAsync, GrabModeAsync);
	XGrabButton(g_ywm.display, 1, Mod4Mask, g_ywm.root,
		false, ButtonPressMask | ButtonReleaseMask | PointerMotionMask,
		GrabModeAsync, GrabModeAsync, None, None);
	XGrabButton(g_ywm.display, 3, Mod4Mask, g_ywm.root,
		false, ButtonPressMask | ButtonReleaseMask | PointerMotionMask,
		GrabModeAsync, GrabModeAsync, None, None);
	g_ywm.start.subwindow = None;
	ft_printf("ywm Initialized.\n");
	wm_loop();
	XCloseDisplay(g_ywm.display);
	return (0);
}
