/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:33:49 by tvacher           #+#    #+#             */
/*   Updated: 2025/05/31 15:30:07 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_3d(t_core *core)
{
	get_3d_based_data(core);
	get_draw_start_data(core);
	while (core->tmp_3d->y < core->tmp_3d->draw_end)
	{
		get_draw_loop_data(core);
		while (core->tmp_3d->x < core->tmp_3d->end)
		{
			print_3d_render(core);
			core->tmp_3d->x++;
		}
		core->tmp_3d->y++;
	}
}

void	start_game(t_core *core)
{
	print_background(core);
	//draw_minimap_game(core);
	get_raycast_data(core);
	//print_player(core, 0xFFFF00);
	//render_weapon(core);
	mlx_put_image_to_window(core->mlx, core->win, core->game_img->img, 0, 0);
	core->redraw = false;
}
