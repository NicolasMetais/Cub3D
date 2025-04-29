/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 03:13:52 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/29 05:00:38 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_menu_hover(int x, int y, void *param)
{
	t_core		*core;
	int			i;

	(void)x;
	core = (t_core *)param;
	i = 0;
	while (i < 4)
	{
		if (y >= core->y_pos[i] && y < core->y_pos[i] + MENU_SPACING)
		{
			if (core->menu_option != i)
			{
				core->menu_option = i;
				core->redraw = true;
			}
			break ;
		}
		i++;
	}
	return (0);
}

int	mouse_menu_click(int button, int x, int y, t_core *core)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		if (core->state == MENU)
		{
			if (core->menu_option == 0)
				core->state = GAME;
			if (core->menu_option == 3)
				handle_destroy(core);
		}
	}
	return (0);
}
