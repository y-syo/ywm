/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ywm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 05:36:23 by mmoussou          #+#    #+#             */
/*   Updated: 2024/01/24 20:41:49 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YWM_H
# define YWM_H

# include "libft.h"
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <stdbool.h>

# define TERM_CMD		"alacritty &"
# define MENU_CMD		"eww_menu &"
# define LOCK_CMD		"ft_lock &"
# define DMENU_CMD		"dmenu_run &"

# define MASTER_KEY				Mod4Mask 
# define TERM_OPEN_KEY			XK_Return 
# define MENU_OPEN_KEY			XK_Escape
# define LOCK_OPEN_KEY			XK_L
# define DMENU_OPEN_KEY			XK_space

# define WINDOW_CLOSE_KEY		XK_W
# define WINDOW_FULLSCREEN_KEY	XK_F

# define WM_TERMINATE_KEY		XK_M

# define FONT				"GohuFont 11 Nerd Font Mono:size=12"
# define FONT_SIZE          12
# define FONT_COLOR         "#ffffff"

# define WINDOW_GAP					6

# define WINDOW_BORDER_WIDTH		2
# define WINDOW_BORDER_COLOR		0x7c6f64
# define WINDOW_BORDER_COLOR_ACTIVE	0xb16286

typedef struct s_wm
{
	Display				*display;
	Window				root;
	XWindowAttributes	attributes;
	XButtonEvent		start;
	XEvent				event;
}				t_wm;

#endif
