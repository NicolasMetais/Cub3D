/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_life_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:48:48 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/23 20:57:07 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	manage_col(t_core *core, t_foes *enemy)
{
	int		map_x;
	int		map_y;
	float	margin_x;
	float	margin_y;
	t_pos	new_pos;

	new_pos.x = enemy->foe_x - cosf(enemy->angle_to_foe) * enemy->speed;
	new_pos.y = enemy->foe_y - sinf(enemy->angle_to_foe) * enemy->speed;
	margin_x = 2;
	if (enemy->foedelt_x < 0)
		margin_x = -2;
	margin_y = 2;
	if (enemy->foedelt_y < 0)
		margin_y = -2;
	map_x = (int)((new_pos.x + margin_x) / 8);
	map_y = (int)(enemy->foe_y / 8);
	if (is_map_colision(core, map_y, map_x))
		enemy->foe_x = new_pos.x;
	map_x = (int)(enemy->foe_x / 8);
	map_y = (int)((new_pos.y + margin_y) / 8);
	if (is_map_colision(core, map_y, map_x))
		enemy->foe_y = new_pos.y;
	bump_enemy_enemy(core, enemy);
}

static void	handle_col(t_core *core, t_foes *enemy)
{
	int		ray;

	if (core->rc->ra == enemy->angle_to_foe)
		ray = core->rc->r;
	if (enemy->dist < enemy->range && can_see_player(core, \
		enemy->foe_y, enemy->foe_x))
		enemy->atk = 1;
	else
		enemy->atk = 0;
	if (enemy->dist < 128 && enemy->dist > 8 && enemy->atk == 0)
		manage_col(core, enemy);
}

void	update_foes(t_core *core)
{
	t_foes	*enemy;

	enemy = core->foes;
	while (enemy)
	{
		if (enemy->death == 0)
			handle_col(core, enemy);
		enemy = enemy->next;
	}
}

bool	all_dead(t_foes *foes)
{
	t_foes	*enemy;

	enemy = foes;
	while (enemy)
	{
		if (enemy->death != 2)
			return (false);
		enemy = enemy->next;
	}
	return (true);
}

void	revive_all(t_foes *foes)
{
	t_foes	*enemy;

	enemy = foes;
	while (enemy)
	{
		enemy->death = 0;
		enemy->anim_death->nb = enemy->init_frame;
		enemy = enemy->next;
	}
}
