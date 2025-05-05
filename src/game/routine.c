/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:49:25 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/05 18:19:51 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//WHOLE GAME ROUTINE
int	routine(void *param)
{
	t_core		*core;
	const int	y_pos[2] = {
		MENU_START_Y + (0 * MENU_SPACING),
		MENU_START_Y + (1 * MENU_SPACING)
	};

	core = (t_core *)param;
	if (core->state == START_MENU)
	{
		if (update_sprite(core->menu_img->skulls))
			skulls_render(core, core->y_pos, core->menu_img->skulls->frame);
	}
	if (core->state == OPTIONS_MENU)
	{
		if (update_sprite(core->menu_img->skulls))
			skulls_render_tempo(core, y_pos, core->menu_img->skulls->frame);
	}
	else if (core->state == GAME)
		printf("game playing");
	return (0);
}
