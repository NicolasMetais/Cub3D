/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_tp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:14:57 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/24 17:59:31 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_tp(t_core *core, int map_x, int map_y)
{
	if (core->valid_map_tiles[map_y][map_x] != 'V' && \
	core->valid_map_tiles[map_y][map_x] != 'D' && \
	core->valid_map_tiles[map_y][map_x] != '1')
	{
		core->rc->pl_x = core->spawn->x * 8;
		core->rc->pl_y = core->spawn->y * 8;
	}
}
