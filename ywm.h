/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ywm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 05:36:23 by mmoussou          #+#    #+#             */
/*   Updated: 2024/01/17 08:39:42 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YWM_H
# define YWM_H

# include <X11/Xlib.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>

# define CLIENT_WINDOW_CAP 256
# define MONITOR_COUNT 1

# define TERM_CMD		"alacritty &"
# define MENU_CMD		"eww_menu &"
# define LOCK_CMD		"ft_lock &"
# define DMENU_CMD		"dmenu_run &"

# define MASTER_KEY				Mod4Mask 
# define TERM_OPEN_KEY			XK_Return 
# define MENU_OPEN_KEY			XK_Escape
# define LOCK_OPEN_KEY			XK_l
# define DMENU_OPEN_KEY			XK_space

# define WINDOW_CLOSE_KEY		XK_w
# define WINDOW_FULLSCREEN_KEY	XK_f

# define WM_TERMINATE_KEY		XK_m

# define FONT                                    "GohuFont 11 Nerd Font Mono:size=12"
# define FONT_SIZE                               12
# define FONT_COLOR                              "#ffffff"

# define WINDOW_BORDER_WIDTH                     2
# define WINDOW_BORDER_COLOR                     0x7c6f64
# define WINDOW_BORDER_COLOR_ACTIVE              0xb16286

 struct	s_monitor {
	uint32_t	width;
	uint32_t	height;
}				t_monitor;

typedef struct	s_keybind {
	const char* cmd; 
	uint32_t key;
}				t_keybind;

typedef struct	s_vec2 {
	float x;
	float y;
}				t_vec2;

typedef struct	s_client{
	Window	win;
	Window	frame;

	bool	fullscreen;
	t_vec2	fullscreen_revert_size;
	t_vec2	fullscreen_revert_pos;

	uint8_t	monitor_index;
	int8_t	desktop_index;
}				t_client;

typedef struct	s_ywm {
	Display		*display;
	Window		root;
	int			screen;

	bool		status;

	t_client	client_windows[CLIENT_WINDOW_CAP];
	uint32_t	client_c;

	int8_t		focused_monitor;
	int32_t		focused_client;
	int8_t		focused_desktop[MONITOR_COUNT];
	int32_t		hard_focused_window_index;

	t_vec2		cursor_start_pos;
	t_vec2		cursor_start_frame_pos;
	t_vec2		cursor_start_frame_size;
	
	int32_t		window_gap;
}				t_ywm;

#endif
