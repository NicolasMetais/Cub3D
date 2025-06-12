/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:13:56 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/12 17:02:27 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_miscellaneous(t_core *core, int color)
{
	int	i;
	int j;
	int	pixel_index;

	if (core->map_height > core->map_width)
		core->tmp_rc->map_size = 32 * 8;
	else
		core->tmp_rc->map_size = 32 * 8;
	i = 0;
	while (i < core->tmp_rc->map_size + 8)
	{
		j = 0;
		while (j < core->tmp_rc->map_size + 8)
		{
			pixel_index = j * core->game_img->line_len
				+ i * (core->game_img->bpp / 8);
			core->game_img->addr[pixel_index + 0] = (color & 0x0000FF);
			core->game_img->addr[pixel_index + 1] = (color & 0x00FF00) >> 8;
			core->game_img->addr[pixel_index + 2] = (color & 0xFF0000) >> 16;
			if (core->game_img->bpp == 32)
				core->game_img->addr[pixel_index + 3] = 0;
			j++;			
		}
		i++;
	}
}

static void	draw_map_back(t_core *core, int color)
{
	int i;
	int j;
	int pixel_index;

	i = 0;
	while (i < core->tmp_rc->map_size)
	{
		j = 0;
		while (j < core->tmp_rc->map_size)
		{
			pixel_index = j * core->game_img->line_len + i * (core->game_img->bpp / 8);
			core->game_img->addr[pixel_index + 0] = (color & 0x0000FF);
			core->game_img->addr[pixel_index + 1] = (color & 0x00FF00) >> 8;
			core->game_img->addr[pixel_index + 2] = (color & 0xFF0000) >> 16;
			if (core->game_img->bpp == 32)
				core->game_img->addr[pixel_index + 3] = 0;
			j++;			
		}
		i++;
	}
}

static void	draw_tile(t_core *core, int x, int y, int color)
{
	int	i;
	int j;
	int pixel_index;

	j = 0;
	while (j < 7)
	{
		i = 0;
		while (i < 7)
		{
			if (x < 32 * 8 && y < 32 * 8)
			{
				pixel_index = (y + j) * core->game_img->line_len + (x + i) * (core->game_img->bpp / 8);
				core->game_img->addr[pixel_index + 0] = (color & 0x0000FF);
				core->game_img->addr[pixel_index + 1] = (color & 0x00FF00) >> 8;
				core->game_img->addr[pixel_index + 2] = (color & 0xFF0000) >> 16;
				if (core->game_img->bpp == 32)
					core->game_img->addr[pixel_index + 3] = 0;
			}
			i++;
		}
		j++;
	}
}

void	draw_minimap_game(t_core *core)
{
	int	x;
	int	y;
	int	tile_x;
	int	tile_y;

	y = 0;
	print_miscellaneous(core, 0x3B0F07);
	draw_map_back(core, 0xC98612);
	while (y < core->map_height)
	{
		x = 0;
		while (x < core->map_width)
		{
			tile_x = x * 8 - core->tmp_rc->pl_x + core->tmp_rc->map_size / 2;
			tile_y = y * 8 - core->tmp_rc->pl_y + core->tmp_rc->map_size / 2;
			if (tile_x < 0)
				tile_x = 0;
			if (tile_x > 32 * 8)
				tile_x = 32 * 8;
			if (tile_y < 0)
				tile_y = 0;
			if (tile_y > 32 * 8)
				tile_y = 32 * 8;
			if (core->map[y][x] == '1')
				draw_tile(core, tile_x, tile_y, 0xFFFFFF);
			else if (core->map[y][x] != ' ' && core->map[y][x] != 9)
				draw_tile(core, tile_x, tile_y, 0x000000);
			x++;
		}
		y++;
	}
}
