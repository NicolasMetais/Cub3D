/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaded_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:22:34 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/23 23:29:43 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_miscellaneous2(t_core *core, t_img *minimap, int color)
{
	int	i;
	int	j;
	int	pixel_index;

	if (core->map_height > core->map_width)
		core->rc->map_size = 32 * 8;
	else
		core->rc->map_size = 32 * 8;
	i = 0;
	while (i < core->rc->map_size + 8)
	{
		j = 0;
		while (j < core->rc->map_size + 8)
		{
			pixel_index = j * minimap->line_len + i * \
			(minimap->bpp / 8);
			minimap->addr[pixel_index + 0] = (color & 0x0000FF);
			minimap->addr[pixel_index + 1] = (color & 0x00FF00) >> 8;
			minimap->addr[pixel_index + 2] = (color & 0xFF0000) >> 16;
			if (minimap->bpp == 32)
				minimap->addr[pixel_index + 3] = 0;
			j++;
		}
		i++;
	}
}

void	draw_map_back2(t_core *core, t_img *minimap, int color)
{
	int	i;
	int	j;
	int	pixel_index;

	i = 0;
	while (i < core->rc->map_size)
	{
		j = 0;
		while (j < core->rc->map_size)
		{
			pixel_index = j * minimap->line_len + i * \
			(minimap->bpp / 8);
			minimap->addr[pixel_index + 0] = (color & 0x0000FF);
			minimap->addr[pixel_index + 1] = (color & 0x00FF00) >> 8;
			minimap->addr[pixel_index + 2] = (color & 0xFF0000) >> 16;
			if (minimap->bpp == 32)
				minimap->addr[pixel_index + 3] = 0;
			j++;
		}
		i++;
	}
}

void	draw_tile2(t_img *minimap, int x, int y, int color)
{
	int	i;
	int	j;
	int	pixel_index;

	j = 0;
	while (j < 7)
	{
		i = 0;
		while (i < 7)
		{
			if (x < 32 * 8 && y < 32 * 8)
			{
				pixel_index = (y + j) * minimap->line_len + (x + i) * \
				(minimap->bpp / 8);
				minimap->addr[pixel_index + 0] = (color & 0x0000FF);
				minimap->addr[pixel_index + 1] = (color & 0x00FF00) >> 8;
				minimap->addr[pixel_index + 2] = \
				(color & 0xFF0000) >> 16;
				if (minimap->bpp == 32)
					minimap->addr[pixel_index + 3] = 0;
			}
			i++;
		}
		j++;
	}
}

void	draw_minimap(t_core *core)
{
	int	x;
	int	y;
	int	tile_x;
	int	tile_y;

	y = 0;
	print_miscellaneous2(core, core->menu_img->minimap, 0x3B0F07);
	draw_map_back2(core, core->menu_img->minimap, 0xC98612);
	while (y < core->map_height)
	{
		x = 0;
		while (x < core->map_width)
		{
			tile_x = get_map_tile_x(core, x);
			tile_y = get_map_tile_y(core, y);
			if (core->map[y][x] == '1' || core->map[y][x] == '2')
				draw_tile2(core->menu_img->minimap, tile_x, tile_y, 0xFFFFFF);
			else if (core->map[y][x] != ' ' && core->map[y][x] != 9)
				draw_tile2(core->menu_img->minimap, tile_x, tile_y, 0x000000);
			x++;
		}
		y++;
	}
}

//minimap du menu, a changer par celle du jeu quand elle sera ok
// bool	draw_minimap(t_core *core)
// {
// 	int		radius;
// 	int		color;
// 	int		x;
// 	int		y;
// 	int		x_draw;
// 	int		y_draw;
// 	char	tile;

// 	radius = 11;
// 	y = -radius;
// 	while (y <= radius)
// 	{
// 		y_draw = y + core->spawn->y;
// 		x = -radius;
// 		while (x < radius)
// 		{
// 			x_draw = x + core->spawn->x;
// 			if (y_draw >= 0 && y_draw < core->map_height && x_draw >= 0
// 				&& x_draw < core->map_width)
// 			{
// 				tile = core->map[y_draw][x_draw];
// 				if (tile == '0')
// 					color = 0x555555;
// 				else if (tile == '1')
// 					color = 0xCCCCCC;
// 				else if (tile == 'D')
// 					color = 0x1E90FF;
// 				else if (tile == 'N' || tile == 'S'
// 					|| tile == 'E' || tile == 'W')
// 					color = 0xFF0000;
// 				else
// 					color = 0x000000;
// 			}
// 			else
// 				color = 0x000000;
// 			draw_tile_2(core->menu_img->minimap, color,
// 				(x + radius) * 8, (y + radius) * 8);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (true);
// }

bool	loaded_map(t_img *bg, t_core *core)
{
	t_img	*loaded_map;

	loaded_map = (t_img *)hashmap_get(&core->hashmap, "Menu_loaded_map");
	if (!loaded_map)
		return (false);
	transparency(bg, loaded_map, 1090, 300);
	transparency(bg, core->menu_img->loaded_map, 1220, 400);
	draw_minimap(core);
	transparency(bg, core->menu_img->minimap, 1210, 450);
	return (true);
}
