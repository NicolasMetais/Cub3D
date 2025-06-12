/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:12:54 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/07 18:13:04 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void loop_tiles_width(t_core *core, int i)
{
	while (i < core->map_width)
	{
		core->tmp_rc->mx = (int)core->tmp_rc->rx >> 3;
		core->tmp_rc->my = (int)core->tmp_rc->ry >> 3;
		if (core->tmp_rc->my >= 0 && core->tmp_rc->my < core->map_height \
			&& core->tmp_rc->mx >= 0 && core->tmp_rc->mx < core->map_width \
			&& core->map[core->tmp_rc->my][core->tmp_rc->mx] == '1')
		{
			core->tmp_rc->vx = core->tmp_rc->rx;
			core->tmp_rc->vy = core->tmp_rc->ry;
			break ;
		}
		else
		{
			core->tmp_rc->rx += core->tmp_rc->x;
			core->tmp_rc->ry += core->tmp_rc->y;
			i++;
		}
	}
}

void loop_tiles_height(t_core *core, int i)
{
    while (i < core->map_height)
    {
        core->tmp_rc->mx = (int)core->tmp_rc->rx >> 3;
        core->tmp_rc->my = (int)core->tmp_rc->ry >> 3;
        if (core->tmp_rc->my >= 0 && core->tmp_rc->my < core->map_height \
            && core->tmp_rc->mx >= 0 && core->tmp_rc->mx < core->map_width \
            && core->map[core->tmp_rc->my][core->tmp_rc->mx] == '1')
		{
			core->tmp_rc->hx = core->tmp_rc->rx;
			core->tmp_rc->hy = core->tmp_rc->ry;
	        break ;
		}
        else
        {
            core->tmp_rc->rx += core->tmp_rc->x;
            core->tmp_rc->ry += core->tmp_rc->y;
            i++;
        }
    }  
}
