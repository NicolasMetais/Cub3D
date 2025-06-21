/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:53:24 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/21 16:53:12 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	enter_handler(int key, t_core *core)
{
	if (key == XK_Return)
	{
		if (core->menu_option == 0)
		{
			core->enter = 0;
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
			cleanup_game(core);
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
	if (key == XK_BackSpace)
	{
		core->state = START_MENU;
		core->menu_option = 1;
		render_menu(core);
	}
}

void	escape_manager(int key, t_core *core)
{
	if (key == XK_Escape)
	{
		if (core->state == GAME)
		{
			mlx_mouse_show(core->mlx, core->win);
			if (!create_pause_bg(core))
				return ;
		}
		else if (core->state == PAUSE)
			core->state = GAME;
		else if (core->state == PAUSE_OPTION)
		{
			core->state = PAUSE;
			render_pause_menu(core);
		}
		else if (core->state == OPTIONS_MENU || core->state == MAPS_MENU)
		{
			if (core->state == OPTIONS_MENU)
				core->menu_option = 1;
			else
				core->menu_option = 2;
			core->state = START_MENU;
			render_menu(core);
		}
	}
}

//KEYBOARD MANAGEMENT
int	handle_keypress(int key, void *param)
{
	t_core	*core;

	core = (t_core *)param;
	escape_manager(key, core);
	if (key == XK_q || key == XK_Q || (key && core->state == GAME_OVER))
	{
		if (!core->enter)
		{
			core->enter = 1;
			return (0);
		}
		cleanup_game(core);
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
	return (true);
}
