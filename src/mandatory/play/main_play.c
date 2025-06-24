/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:33:49 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/23 22:47:55 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_3d(t_core *core)
{
	get_3d_based_data(core);
	get_draw_start_data(core);
	while (core->rc3d->y < core->rc3d->draw_end)
	{
		get_draw_loop_data(core);
		while (core->rc3d->x < core->rc3d->end)
		{
			print_3d_render(core);
			core->rc3d->x++;
		}
		core->rc3d->y++;
	}
}

bool	start_game(t_core *core)
{
	print_background(core);
	get_raycast_data(core);
	mlx_put_image_to_window(core->mlx, core->win, core->game_img->img, 0, 0);
	return (true);
}
