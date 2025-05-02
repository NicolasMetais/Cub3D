/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:49:25 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/30 01:08:33 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//WHOLE GAME ROUTINE
int	routine(void *param)
{
	t_core		*core;

	core = (t_core *)param;
	if (core->state == START_MENU)
	{
/* 		if (core->redraw)
			render_menu(core); */
		if (update_sprite(core->menu_img->skulls))
		{
			skulls_render(core, core->y_pos, core->menu_img->skulls->frame);
		}
/* 		mlx_put_image_to_window(core->mlx, core->win,
			core->menu_img->bg->img, 0, 0);
		core->redraw = true;
		render_menu(core); */
	}
	else if (core->state == GAME)
		printf("game playing");
	return (0);
}
