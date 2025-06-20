/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:34:06 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/15 01:59:06 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_menu_release(int button, int x, int y, t_core *core)
{
	(void)x;
	(void)y;
	if (core->state == OPTIONS_MENU || core->state == PAUSE_OPTION)
	{
		if (button == 1)
		{
			core->isclicked = 0;
			core->active_slider = -1;
		}
	}
	if (core->state == GAME)
	{
		if (button == 1 && (core->player->curr_wpn == 4
				|| core->player->curr_wpn > 5))
			core->player->firing = false;
	}
	return (0);
}
