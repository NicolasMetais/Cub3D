/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:53:24 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/06 23:06:21 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	enter_handler(int key, t_core *core)
{
	if (key == XK_Return)
	{
		if (core->menu_option == 0)
		{
			mlx_clear_window(core->mlx, core->win);
			if (!game_init(core))
				return ;
			core->state = GAME;
		}
		if (core->menu_option == 1)
		{
			core->menu_option = 0;
			render_options_menu(core);
		}
		if (core->menu_option == 2)
		{
			core->menu_option = 0;
			core->enter = 0;
			render_maps_menu(core);
		}
		if (core->menu_option == 3)
			handle_destroy(core);
	}
}

//MANAGE MENUING DEPLACEMENT
void	menu_keypress(int key, t_core *core)
{
	if (!core->enter)
	{
		core->enter = 1;
		return ;
	}
	if (key == XK_Up)
	{
		if (core->menu_option > 0)
			core->menu_option--;
		else
			core->menu_option = 3;
		render_menu(core);
	}
	else if (key == XK_Down)
	{
		if (core->menu_option < 3)
			core->menu_option++;
		else
			core->menu_option = 0;
		render_menu(core);
	}
	enter_handler(key, core);
}



void	option_menu_keypress(int key, t_core *core)
{
/* 	if (key == XK_Up)
	{
		core->redraw = true;
		if (core->menu_option > 0)
			core->menu_option--;
		else
			core->menu_option = 1;
		render_options_menu(core);
	}
	else if (key == XK_Down)
	{
		core->redraw = true;
		if (core->menu_option < 1)
			core->menu_option++;
		else
			core->menu_option = 0;
		render_options_menu(core);
	} */
	if (key == XK_BackSpace)
	{
		core->state = START_MENU;
		core->menu_option = 1;
		render_menu(core);
	}
}

//KEYBOARD MANAGEMENT
int	handle_keypress(int key, void *param)
{
	t_core	*core;

	core = (t_core *)param;
	if (key == XK_Escape && core->state != GAME)
		handle_destroy(core);
	else if (key == XK_Escape && core->state == GAME)
	{
		if (!create_pause_bg(core))
			return (0);
		core->redraw = true;
		core->menu_option = 0;
		core->state = PAUSE;
	}
	if (core->state == PAUSE)
		pause_menu_keypress(key, core);
	if (core->state == START_MENU)
		menu_keypress(key, core);
	if (core->state == OPTIONS_MENU)
		option_menu_keypress(key, core);
	if (core->state == MAPS_MENU)
		maps_menu_keypress(key, core);
	if (core->state == GAME)
		on_keypress_game(key, core);
	if (core->state == PAUSE_OPTION)
		pause_option_keypress(key, core);
	return (true);
}
