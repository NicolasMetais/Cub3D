/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:12:54 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/23 21:26:56 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_angle_in_rc_data(t_core *core)
{
	core->rc->ra = core->rc->pl_angle - RAD * ((core->fov) / 2);
	if (core->rc->ra < 0)
		core->rc->ra += 2 * PI;
	if (core->rc->ra > 2 * PI)
		core->rc->ra -= 2 * PI;
	core->rc->r = 0;
}

void	loop_tiles_width(t_core *core, int i)
{
	while (i < core->map_width)
	{
		core->rc->mx = (int)core->rc->rx >> 3;
		core->rc->my = (int)core->rc->ry >> 3;
		if (core->rc->my >= 0 && core->rc->my < core->map_height \
			&& core->rc->mx >= 0 && core->rc->mx < core->map_width \
			&& (core->map[core->rc->my][core->rc->mx] == '1'\
			|| core->map[core->rc->my][core->rc->mx] == '2' \
			|| core->map[core->rc->my][core->rc->mx] == '4' \
			|| core->map[core->rc->my][core->rc->mx] == '5' \
			|| core->map[core->rc->my][core->rc->mx] == '6' \
			|| core->map[core->rc->my][core->rc->mx] == '7'))
		{
			core->rc->vx = core->rc->rx;
			core->rc->vy = core->rc->ry;
			core->rc->v_wall = core->map[core->rc->my][core->rc->mx];
			break ;
		}
		else
		{
			core->rc->rx += core->rc->x;
			core->rc->ry += core->rc->y;
			i++;
		}
	}
}

void	loop_tiles_height(t_core *core, int i)
{
	while (i < core->map_height)
	{
		core->rc->mx = (int)core->rc->rx >> 3;
		core->rc->my = (int)core->rc->ry >> 3;
		if (core->rc->my >= 0 && core->rc->my < core->map_height \
			&& core->rc->mx >= 0 && core->rc->mx < core->map_width \
			&& (core->map[core->rc->my][core->rc->mx] == '1' \
			|| core->map[core->rc->my][core->rc->mx] == '2' \
			|| core->map[core->rc->my][core->rc->mx] == '4' \
			|| core->map[core->rc->my][core->rc->mx] == '5' \
			|| core->map[core->rc->my][core->rc->mx] == '6' \
			|| core->map[core->rc->my][core->rc->mx] == '7'))
		{
			core->rc->hx = core->rc->rx;
			core->rc->hy = core->rc->ry;
			core->rc->h_wall = core->map[core->rc->my][core->rc->mx];
			break ;
		}
		else
		{
			core->rc->rx += core->rc->x;
			core->rc->ry += core->rc->y;
			i++;
		}
	}
}
