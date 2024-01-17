/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ywm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 05:25:52 by mmoussou          #+#    #+#             */
/*   Updated: 2024/01/17 12:32:03 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ywm.h"

static t_ywm	g_wm;

void	grab_global_inputs()
{
	XGrabKey(g_wm.display,XKeysymToKeycode(g_wm.display, WM_TERMINATE_KEY),MASTER_KEY, g_wm.root,false, GrabModeAsync,GrabModeAsync);

	XGrabKey(g_wm.display,XKeysymToKeycode(g_wm.display, DMENU_OPEN_KEY),MASTER_KEY,g_wm.root,false, GrabModeAsync,GrabModeAsync);
	XGrabKey(g_wm.display,XKeysymToKeycode(g_wm.display, TERM_OPEN_KEY),MASTER_KEY, g_wm.root,false, GrabModeAsync,GrabModeAsync);
	XGrabKey(g_wm.display,XKeysymToKeycode(g_wm.display, LOCK_OPEN_KEY),MASTER_KEY, g_wm.root, false, GrabModeAsync,GrabModeAsync);
}

int handle_x_error(Display* display, XErrorEvent* e) {
	(void)display;
	char err_msg[1024];
	XGetErrorText(display, e->error_code, err_msg, sizeof(err_msg));
	ft_printf("X Error:\n\tRequest: %i\n\tError Code: %i - %s\n\tResource ID: %i\n", 
			e->request_code, e->error_code, err_msg, (int)e->resourceid); 
	return 0;  
}

void	ywm_init(void)
{
	g_wm.display = XOpenDisplay(NULL);
	if(!g_wm.display)
	{
		ft_printf("Failed to open X Display.\n");
		return ;
	}
	g_wm.client_c = 0;
	g_wm.cursor_start_frame_size = (t_vec2){ .x = 0.0f, .y = 0.0f};
	g_wm.cursor_start_frame_pos = (t_vec2){ .x = 0.0f, .y = 0.0f}; 
	g_wm.cursor_start_pos = (t_vec2){ .x = 0.0f, .y = 0.0f}; 
	g_wm.status = true;
	g_wm.focused_monitor = MONITOR_COUNT - 1;
	g_wm.window_gap = WINDOW_GAP;
	g_wm.hard_focused_window_index = -1;
	g_wm.focused_client = -1;
	ft_memset(g_wm.focused_desktop, 0, sizeof(g_wm.focused_desktop));
	g_wm.root = DefaultRootWindow(g_wm.display);
	g_wm.screen = DefaultScreen(g_wm.display);

	const char *name = "ywm";
	XChangeProperty(g_wm.display, g_wm.root,
			XInternAtom(g_wm.display, "_NET_WM_NAME", False),
			XInternAtom(g_wm.display, "UTF8_STRING", False),
			8, PropModeReplace, (const unsigned char *)name, ft_strlen(name));
	XFlush(g_wm.display);

	XSelectInput(g_wm.display, g_wm.root, SubstructureRedirectMask | SubstructureNotifyMask); 
	XSync(g_wm.display, false);

	Cursor cursor = XcursorLibraryLoadCursor(g_wm.display, "arrow");
	XDefineCursor(g_wm.display, g_wm.root, cursor);
	XSetErrorHandler(handle_x_error);

	XSetWindowAttributes attributes;
	attributes.event_mask = ButtonPress | KeyPress | SubstructureRedirectMask | SubstructureNotifyMask | PropertyChangeMask;
	XChangeWindowAttributes(g_wm.display, g_wm.root, CWEventMask, &attributes);

	grab_global_inputs();
}

void ywm_terminate()
{
	XCloseDisplay(g_wm.display);
}

void* update_ui() {
	while(true)
	{
		usleep(60 * 1000000);
		XFlush(g_wm.display);
	}
	return NULL;
}

int	main(void)
{
	ywm_init();
	pthread_t ui_thread;
	pthread_create(&ui_thread, NULL, update_ui, NULL);

	ywm_terminate();
	return (0);
}
