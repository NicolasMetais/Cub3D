/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:49:25 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/26 19:19:23 by nmetais          ###   ########.fr       */
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
		start_game(core);
	core->redraw = false;
	return (0);
}
