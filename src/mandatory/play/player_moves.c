/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:40:42 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/23 22:47:17 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_straf_right(t_core *core, double move_dist)
{
	int	map_x;
	int	map_y;

	core->r_straff->straf_x = core->rc->pldelt_y;
	core->r_straff->straf_y = -core->rc->pldelt_x;
	core->r_straff->next_x = core->rc->pl_x - core->r_straff->straf_x \
	* move_dist;
	core->r_straff->next_y = core->rc->pl_y - core->r_straff->straf_y \
	* move_dist;
	core->r_straff->margin_x = 1.5;
	if (core->r_straff->straf_x > 0)
		core->r_straff->margin_x = -1.5;
	core->r_straff->margin_y = 1.5;
	if (core->r_straff->straf_y > 0)
		core->r_straff->margin_y = -1.5;
	map_x = (int)((core->r_straff->next_x + core->r_straff->margin_x) / 8);
	map_y = (int)(core->rc->pl_y / 8);
	if (is_map_colision(core, map_y, map_x))
		core->rc->pl_x = core->r_straff->next_x;
	map_x = (int)(core->rc->pl_x / 8);
	map_y = (int)((core->r_straff->next_y + core->r_straff->margin_y) / 8);
	if (is_map_colision(core, map_y, map_x))
	core->rc->pl_y = core->r_straff->next_y;
}

static void	handle_straf_left(t_core *core, double move_dist)
{
	int	map_x;
	int	map_y;

	core->l_straff->straf_x = -core->rc->pldelt_y;
	core->l_straff->straf_y = core->rc->pldelt_x;
	core->l_straff->next_x = core->rc->pl_x - core->l_straff->straf_x \
	* move_dist;
	core->l_straff->next_y = core->rc->pl_y - core->l_straff->straf_y \
	* move_dist;
	core->l_straff->margin_x = 1.5;
	if (core->l_straff->straf_x > 0)
		core->l_straff->margin_x = -1.5;
	core->l_straff->margin_y = 1.5;
	if (core->l_straff->straf_y > 0)
		core->l_straff->margin_y = -1.5;
	map_x = (int)((core->l_straff->next_x + core->l_straff->margin_x) / 8);
	map_y = (int)(core->rc->pl_y / 8);
	if (is_map_colision(core, map_y, map_x))
		core->rc->pl_x = core->l_straff->next_x;
	map_x = (int)(core->rc->pl_x / 8);
	map_y = (int)((core->l_straff->next_y + core->l_straff->margin_y) / 8);
	if (is_map_colision(core, map_y, map_x))
		core->rc->pl_y = core->l_straff->next_y;
}

static void	handle_down(t_core *core, double move_dist)
{
	int	map_x;
	int	map_y;

	core->down->next_x = core->rc->pl_x - core->rc->pldelt_x * move_dist;
	core->down->next_y = core->rc->pl_y - core->rc->pldelt_y * move_dist;
	core->down->margin_x = 1.5;
	if (core->rc->pldelt_x > 0)
		core->down->margin_x = -1.5;
	core->down->margin_y = 1.5;
	if (core->rc->pldelt_y > 0)
		core->down->margin_y = -1.5;
	map_x = (int)((core->down->next_x + core->down->margin_x) / 8);
	map_y = (int)(core->rc->pl_y / 8);
	if (is_map_colision(core, map_y, map_x))
		core->rc->pl_x = core->down->next_x;
	map_x = (int)(core->rc->pl_x / 8);
	map_y = (int)((core->down->next_y + core->down->margin_y) / 8);
	if (is_map_colision(core, map_y, map_x))
		core->rc->pl_y = core->down->next_y;
}

static void	handle_up(t_core *core, double move_dist)
{
	int		map_x;
	int		map_y;

	core->up->next_x = core->rc->pl_x + core->rc->pldelt_x * move_dist;
	core->up->next_y = core->rc->pl_y + core->rc->pldelt_y * move_dist;
	core->up->margin_x = 1.5;
	if (core->rc->pldelt_x < 0)
		core->up->margin_x = -1.5;
	core->up->margin_y = 1.5;
	if (core->rc->pldelt_y < 0)
		core->up->margin_y = -1.5;
	map_x = (int)((core->up->next_x + core->up->margin_x) / 8);
	map_y = (int)(core->rc->pl_y / 8);
	if (is_map_colision(core, map_y, map_x))
		core->rc->pl_x = core->up->next_x;
	map_x = (int)(core->rc->pl_x / 8);
	map_y = (int)((core->up->next_y + core->up->margin_y) / 8);
	if (is_map_colision(core, map_y, map_x))
		core->rc->pl_y = core->up->next_y;
}

void	move_player(t_core *core, t_move move, double delta_time)
{
	double	move_dist;

	move_dist = core->player->speed * delta_time;
	if (core->rc->pldelt_x < 0)
		core->rc->of_x = -move_dist;
	else
		core->rc->of_x = move_dist;
	if (core->rc->pldelt_y < 0)
		core->rc->of_y = -move_dist;
	else
		core->rc->of_y = move_dist;
	init_new_pos(core);
	if (move == UP)
		handle_up(core, move_dist);
	else if (move == DOWN)
		handle_down(core, move_dist);
	else if (move == LEFT)
		handle_left(core, move_dist);
	else if (move == RIGHT)
		handle_right(core, move_dist);
	else if (move == S_RIGHT)
		handle_straf_right(core, move_dist);
	else if (move == S_LEFT)
		handle_straf_left(core, move_dist);
}
