/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 03:13:52 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/02 21:09:29 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	starting_menu_hover(int y, t_core *core)
{
	int	i;

	i = -1;
	if (core->state == START_MENU)
	{
		while (i < 4)
		{
			if (y >= core->y_pos[i] && y < core->y_pos[i] + MENU_SPACING)
			{
				core->menu_option = i;
				render_menu(core);
				break ;
			}
			i++;
		}
	}
}

//CLICK MANAGEMENT
int	mouse_menu_hover(int x, int y, void *param)
{
	t_core		*core;
	int			i;

	(void)x;
	core = (t_core *)param;
	i = 0;
	starting_menu_hover(y, core);
	return (0);
}

//CLICK MANAGEMENT
int	mouse_menu_click(int button, int x, int y, t_core *core)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		if (core->state == START_MENU)
		{
			if (core->menu_option == 0)
				core->state = GAME;
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
				render_options_menu(core);
			}
			if (core->menu_option == 3)
				handle_destroy(core);
		}
	}
	return (0);
}
