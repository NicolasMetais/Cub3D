/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:09:26 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/07 18:09:37 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	print_foes(t_core *core, int color)
// {
// 	int	x;
// 	int	y;
// 	int	px_index;

// 	y = enemy->;
// 	while (y < core->rc->map_size / 2 + 4)
// 	{
// 		x = core->rc->map_size / 2;
// 		while (x < core->rc->map_size / 2 + 4)
// 		{
// 			px_index = y * core->game_img->line_len + x * \
// 			(core->game_img->bpp / 8);
// 			core->game_img->addr[px_index + 0] = (color >> 0) & 0xFF;
// 			core->game_img->addr[px_index + 1] = (color >> 8) & 0xFF;
// 			core->game_img->addr[px_index + 2] = (color >> 16) & 0xFF;
// 			if (core->game_img->bpp == 4)
// 				core->game_img->addr[px_index + 0] = 0xFF;
// 			x++;
// 		}
// 		y++;
// 	}
// 	draw_player_line(core, color);
// }

void	print_player(t_core *core, int color)
{
	int	x;
	int	y;
	int	px_index;

	y = core->rc->map_size / 2;
	while (y < core->rc->map_size / 2 + 4)
	{
		x = core->rc->map_size / 2;
		while (x < core->rc->map_size / 2 + 4)
		{
			px_index = y * core->game_img->line_len + x * \
			(core->game_img->bpp / 8);
			core->game_img->addr[px_index + 0] = (color >> 0) & 0xFF;
			core->game_img->addr[px_index + 1] = (color >> 8) & 0xFF;
			core->game_img->addr[px_index + 2] = (color >> 16) & 0xFF;
			if (core->game_img->bpp == 4)
				core->game_img->addr[px_index + 0] = 0xFF;
			x++;
		}
		y++;
	}
	draw_player_line(core, color);
}

void	draw_player_line(t_core *core, int color)
{
	int	i;
	int	px;
	int	py;
	int	px_index;

	i = 0;
	while (i < 8)
	{
		px = core->rc->map_size / 2 + cos(core->rc->pl_angle) * i;
		py = core->rc->map_size / 2 + sin(core->rc->pl_angle) * i;
		if (px >= 0 && py >= 0)
		{
			px_index = py * core->game_img->line_len + px * \
			(core->game_img->bpp / 8);
			core->game_img->addr[px_index + 0] = (color >> 0) & 0xFF;
			core->game_img->addr[px_index + 1] = (color >> 8) & 0xFF;
			core->game_img->addr[px_index + 2] = (color >> 16) & 0xFF;
			if (core->game_img->bpp == 4)
				core->game_img->addr[px_index + 0] = 0xFF;
		}
		i++;
	}
}

void	print_rays(t_core *core, int color)
{
	int	i;
	int	px_index;

	if (core->rc->r == core->rc->max_r / 2)
	{
		i = 0;
		color = 0xFF0000;
	}
	else
		i = (int)core->rc->dist3[core->rc->r] - 2;
	while (i < (int)core->rc->dist3[core->rc->r] + 2)
	{
		core->rc->px = core->rc->map_size / 2 + \
		cos(core->rc->ra) * i;
		core->rc->py = core->rc->map_size / 2 + \
		sin(core->rc->ra) * i;
		if (core->rc->px >= 0 && core->rc->py >= 0 \
			&& core->rc->px < 32 * 8 - 8)
		{
			px_index = core->rc->py * core->game_img->line_len + \
			core->rc->px * (core->game_img->bpp / 8);
			core->game_img->addr[px_index + 0] = (color >> 0) & 0xFF;
			core->game_img->addr[px_index + 1] = (color >> 8) & 0xFF;
			core->game_img->addr[px_index + 2] = (color >> 16) & 0xFF;
			if (core->game_img->bpp == 4)
				core->game_img->addr[px_index + 0] = 0xFF;
		}
		i++;
	}
}
