/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_over.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 03:13:52 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/21 15:49:24 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_click_pause_menu(t_core *core)
{
	if (core->menu_option == 0)
	{
		core->enter = 0;
		core->state = GAME;
	}
	if (core->menu_option == 1)
	{
		core->state = PAUSE_OPTION;
		core->menu_option = 0;
		render_pause_options(core);
	}
	if (core->menu_option == 2)
		cleanup_game(core);
}

void	starting_menu_hover(int y, t_core *core)
{
	int	i;

	i = -1;
	if (core->state == START_MENU)
	{
		while (++i < 4)
		{
			if (y >= core->y_pos[i] && y < core->y_pos[i] + MENU_SPACING)
			{
				core->menu_option = i;
				render_menu(core);
				break ;
			}
		}
	}
}

void	maps_menu_hover(int y, t_core *core)
{
	int	i;
	int	index;

	i = -1;
	if (core->state == MAPS_MENU)
	{
		while (++i < VISIBLE)
		{
			if (y >= core->y_pos[i] && y < core->y_pos[i] + MENU_SPACING)
			{
				index = i + core->scroll_offset;
				if (index < core->maps_nb && index != core->menu_option)
				{
					core->menu_option = index;
					render_maps_menu(core);
				}
				break ;
			}
		}
	}
}

//CLICK MANAGEMENT
int	mouse_menu_hover(int x, int y, void *param)
{
	t_core		*core;

	core = (t_core *)param;
	starting_menu_hover(y, core);
	options_menu_hover(x, y, core);
	pause_options_hover(x, y, core);
	pause_hover(x, y, core);
	maps_menu_hover(y, core);
	if (core->state == GAME)
	{
		mlx_mouse_hide(core->mlx, core->win);
		mouse_scroll_game(core, x, y);
	}
	return (0);
}
