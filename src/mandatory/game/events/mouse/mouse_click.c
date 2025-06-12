/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:49:13 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/30 19:48:43 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//CLICK MANAGEMENT
void	mouse_click_starting_menu(t_core *core)
{
	if (core->menu_option == 0)
	{
		if (!game_init(core))
			return ;
		core->state = GAME;
	}
	if (core->menu_option == 1)
	{
		core->state = OPTIONS_MENU;
		core->menu_option = 0;
		render_options_menu(core);
	}
	if (core->menu_option == 2)
	{
		core->state = MAPS_MENU;
		core->menu_option = 0;
		render_maps_menu(core);
	}
	if (core->menu_option == 3)
		handle_destroy(core);
}

void	mouse_click_maps_menu(t_core *core)
{
	if (core->menu_option < core->maps_nb)
		if (!map_selector(core))
			return ;
}

void	mouse_click_options_menu(int x, int y, t_core *core)
{
	if (x >= core->x && x <= core->x + core->menu_img->cursor->width
		&& y >= core->y_pos[0] + 5 && y <= core->y_pos[0]
		+ 5 + core->menu_img->cursor->height)
		core->isclicked = true;
}

int	mouse_menu_click(int button, int x, int y, t_core *core)
{
	if (button == 1)
	{
		if (core->state == START_MENU)
			mouse_click_starting_menu(core);
		if (core->state == MAPS_MENU)
			mouse_click_maps_menu(core);
		if (core->state == OPTIONS_MENU)
			mouse_click_options_menu(x, y, core);
	}
	if (core->state == MAPS_MENU)
	{
		if (button == 4 && core->scroll_offset > 0)
			core->scroll_offset--;
		if (button == 5 && core->scroll_offset < core->maps_nb - VISIBLE)
			core->scroll_offset++;
		render_maps_menu(core);
	}
	if (core->state == GAME)
		mouse_click_game(core, button);
	return (0);
}
