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
	core->tmp_rc->px2 = (int)(core->tmp_rc->pl_x / 8);
	core->tmp_rc->py2 = (int)(core->tmp_rc->pl_y / 8);
	core->tmp_rc->px2_add = (int)(core->tmp_rc->pl_x + core->tmp_rc->of_x) / 8;
	core->tmp_rc->py2_add = (int)(core->tmp_rc->pl_y + core->tmp_rc->of_y) / 8;
	core->tmp_rc->px2_sub = (int)(core->tmp_rc->pl_x - core->tmp_rc->of_x) / 8;
	core->tmp_rc->py2_sub = (int)(core->tmp_rc->pl_y - core->tmp_rc->of_y) / 8;
}

void	handle_right(t_core *core, double move_dist)
{
	core->tmp_rc->pl_angle += 0.05 * move_dist;
	if (core->tmp_rc->pl_angle > 2 * PI)
		core->tmp_rc->pl_angle -= 2 * PI;
	core->tmp_rc->pldelt_x = cos(core->tmp_rc->pl_angle);
	core->tmp_rc->pldelt_y = sin(core->tmp_rc->pl_angle);
}

void	handle_left(t_core *core, double move_dist)
{
	core->tmp_rc->pl_angle -= 0.05 * move_dist;
	if (core->tmp_rc->pl_angle < 0)
		core->tmp_rc->pl_angle += 2 * PI;
	core->tmp_rc->pldelt_x = cos(core->tmp_rc->pl_angle);
	core->tmp_rc->pldelt_y = sin(core->tmp_rc->pl_angle);
}
