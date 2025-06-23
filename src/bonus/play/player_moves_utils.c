/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:56:39 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/23 20:48:36 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map_colision(t_core *core, int x, int y)
{
	if (core->map[x][y] != '1' && \
		core->map[x][y] != '2' && \
		core->map[x][y] != '4' && \
		core->map[x][y] != '5' && \
		core->map[x][y] != '6' && \
		core->map[x][y] != '7')
		return (true);
	else
		return (false);
}

bool	moves_init(t_core *core)
{
	core->r_straff = gc_malloc(&core->gc, sizeof(t_moves),
			STRUCT, "r_straff");
	if (!core->r_straff)
		return (false);
	core->l_straff = gc_malloc(&core->gc, sizeof(t_moves),
			STRUCT, "l_straff");
	if (!core->r_straff)
		return (false);
	core->up = gc_malloc(&core->gc, sizeof(t_moves),
			STRUCT, "up");
	if (!core->r_straff)
		return (false);
	core->down = gc_malloc(&core->gc, sizeof(t_moves),
			STRUCT, "down");
	if (!core->r_straff)
		return (false);
	return (true);
}

void	init_new_pos(t_core *core)
{
	core->rc->px2 = (int)(core->rc->pl_x / 8);
	core->rc->py2 = (int)(core->rc->pl_y / 8);
	core->rc->px2_add = (int)(core->rc->pl_x + core->rc->of_x) / 8;
	core->rc->py2_add = (int)(core->rc->pl_y + core->rc->of_y) / 8;
	core->rc->px2_sub = (int)(core->rc->pl_x - core->rc->of_x) / 8;
	core->rc->py2_sub = (int)(core->rc->pl_y - core->rc->of_y) / 8;
}

void	handle_right(t_core *core, double move_dist)
{
	core->rc->pl_angle += 0.05 * move_dist;
	if (core->rc->pl_angle > 2 * PI)
		core->rc->pl_angle -= 2 * PI;
	core->rc->pldelt_x = cos(core->rc->pl_angle);
	core->rc->pldelt_y = sin(core->rc->pl_angle);
}

void	handle_left(t_core *core, double move_dist)
{
	core->rc->pl_angle -= 0.05 * move_dist;
	if (core->rc->pl_angle < 0)
		core->rc->pl_angle += 2 * PI;
	core->rc->pldelt_x = cos(core->rc->pl_angle);
	core->rc->pldelt_y = sin(core->rc->pl_angle);
}
