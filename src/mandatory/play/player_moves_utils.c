/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:56:39 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/07 17:56:50 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
