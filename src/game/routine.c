/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:49:25 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/28 23:50:58 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//WHOLE GAME ROUTINE
int	routine(void *param)
{
	t_core		*core;

	core = (t_core *)param;
	if (core->state == START_MENU || core->state == OPTIONS_MENU
		|| core->state == MAPS_MENU)
	{
		if (update_sprite(core->menu_img->skulls))
			skulls_render(core, core->y_pos, core->menu_img->skulls->frame);
	}
	else if (core->state == GAME)
	{
		init_map_textures(core);
		core->tmp_rc->max_r = S_LENGHT;
		if (core->redraw == true)
			start_game(core);
		render_head(core);
	}
	core->redraw = false;
	return (0);
}
