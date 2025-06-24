/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:47:07 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/24 15:03:42 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall_in_minimap(t_core *core, int x, int y)
{
	if (core->map[y][x] == '1' \
	|| core->map[y][x] == '4' || core->map[y][x] == '5' \
	|| core->map[y][x] == '6' || core->map[y][x] == '7')
		return (true);
	return (false);
}

int	get_map_tile_x(t_core *core, int x)
{
	int	tile_x;

	tile_x = x * 8 - core->rc->pl_x + core->rc->map_size / 2;
	if (tile_x < 0)
		tile_x = 0;
	if (tile_x > 32 * 8)
		tile_x = 32 * 8;
	return (tile_x);
}

int	get_map_tile_y(t_core *core, int y)
{
	int	tile_y;

	tile_y = y * 8 - core->rc->pl_y + core->rc->map_size / 2;
	if (tile_y < 0)
		tile_y = 0;
	if (tile_y > 32 * 8)
		tile_y = 32 * 8;
	return (tile_y);
}
