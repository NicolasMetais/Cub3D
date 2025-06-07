/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause_options_hover.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 20:18:16 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/06 23:04:35 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pause_options_hover(int x, int y, t_core *core)
{
	int		i;
	t_pos	pos;

	i = -1;
	pos.x = core->hud_img->pause_buffer->width / 2 + 5 - 70;
	pos.y = pos.x + core->menu_img->slider_bar->width
		- 90 - core->menu_img->cursor->width;
	if (core->state == PAUSE_OPTION)
	{
		while (++i < 1)
		{
			if (y >= core->y_pos[i] && y < core->y_pos[i] + MENU_SPACING)
			{
				core->menu_option = i;
				render_pause_options(core);
				break ;
			}
		}
		if (core->isclicked)
			slider(core, pos, x, core->hud_img->pause_buffer);
	}
}
