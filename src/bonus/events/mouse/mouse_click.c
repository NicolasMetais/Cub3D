/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:49:13 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/20 18:25:10 by nmetais          ###   ########.fr       */
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
		cleanup_game(core);
}

void	mouse_click_maps_menu(t_core *core)
{
	if (core->menu_option < core->maps_nb)
		if (!map_selector(core))
			return ;
}

bool	on_off_cursors_update(t_slider *slider, int i)
{
	if (i == 3 || i == 4)
	{
		if (*slider->int_var == 0)
		{
			*slider->int_var = 1;
			*slider->x_var = slider->slider_max;
		}
		else
		{
			*slider->int_var = 0;
			*slider->x_var = slider->slider_min;
		}
		return (true);
	}
	return (false);
}

void	mouse_click_options_menu(int x, int y, t_core *core)
{
	t_slider	*slider;
	int			i;
	int			cursor_x;
	int			cursor_y;

	i = -1;
	while (++i < 5)
	{
		slider = &core->menu_img->sliders[i];
		cursor_x = *slider->x_var;
		cursor_y = core->y_pos[i] + 5;
		if (x >= cursor_x && x <= cursor_x + core->menu_img->cursor->width
			&& y >= cursor_y && y <= cursor_y
			+ core->menu_img->cursor->height)
		{
			if (on_off_cursors_update(slider, i))
				return ;
			core->isclicked = true;
			core->active_slider = i;
		}
	}
}

int	mouse_menu_click(int button, int x, int y, t_core *core)
{
	if (button == 1)
	{
		if (core->state == START_MENU)
			mouse_click_starting_menu(core);
		if (core->state == MAPS_MENU)
			mouse_click_maps_menu(core);
		if (core->state == OPTIONS_MENU || core->state == PAUSE_OPTION)
			mouse_click_options_menu(x, y, core);
		if (core->state == PAUSE)
			mouse_click_pause_menu(core);
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
	if (button && core->state == GAME_OVER)
		cleanup_game(core);
	return (0);
}
