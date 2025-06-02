/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaded_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:22:34 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/02 21:13:20 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_tile_2(t_img *minimap, int color, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < 8)
			put_on_bg(minimap, y + i, x + j, color);
	}
}
//minimap du menu, a changer par celle du jeu quand elle sera ok
bool	draw_minimap(t_core *core)
{
	int		radius;
	int		color;
	int		x;
	int		y;
	int		x_draw;
	int		y_draw;
	char	tile;

	radius = 11;
	y = -radius;
	while (y <= radius)
	{
		y_draw = y + core->spawn->y;
		x = -radius;
		while (x < radius)
		{
			x_draw = x + core->spawn->x;
			if (y_draw >= 0 && y_draw < core->map_height && x_draw >= 0
				&& x_draw < core->map_width)
			{
				tile = core->map[y_draw][x_draw];
				if (tile == '0')
					color = 0x555555;
				else if (tile == '1')
					color = 0xCCCCCC;
				else if (tile == 'D')
					color = 0x1E90FF;
				else if (tile == 'N' || tile == 'S'
					|| tile == 'E' || tile == 'W')
					color = 0xFF0000;
				else
					color = 0x000000;
			}
			else
				color = 0x000000;
			draw_tile_2(core->menu_img->minimap, color,
				(x + radius) * 8, (y + radius) * 8);
			x++;
		}
		y++;
	}
	return (true);
}

bool	loaded_map(t_img *bg, t_core *core)
{
	t_img	*loaded_map;

	loaded_map = (t_img *)hashmap_get(&core->hashmap, "Menu_loaded_map");
	transparency(bg, loaded_map, 1090, 300);
	transparency(bg, core->menu_img->loaded_map, 1220, 400);
	if (!draw_minimap(core))
		return (false);
	transparency(bg, core->menu_img->minimap, 1210, 450);
	return (true);
}
