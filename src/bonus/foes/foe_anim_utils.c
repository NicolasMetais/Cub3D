/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_anim_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:02:56 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/24 16:57:44 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bump_enemy_enemy(t_core *core, t_foes *current)
{
	t_foes	*enemy;
	double	dx;
	double	dy;
	double	dist;
	double	knockback_strength;

	enemy = core->foes;
	while (enemy)
	{
		dx = current->foe_x - enemy->foe_x;
		dy = current->foe_y - enemy->foe_y;
		dist = sqrt(dx * dx + dy * dy);
		if (dist < 6.0 && dist > 0.001 && enemy->death == 0)
		{
			knockback_strength = 2;
			current->foe_x += (dx / dist) * knockback_strength;
			current->foe_y += (dy / dist) * knockback_strength;
		}
		enemy = enemy->next;
	}
}

void	bump_player_enemy(t_core *core)
{
	t_foes	*enemy;
	double	dx;
	double	dy;
	double	dist;
	double	knockback_strength;

	enemy = core->foes;
	while (enemy)
	{
		dx = core->rc->pl_x - enemy->foe_x;
		dy = core->rc->pl_y - enemy->foe_y;
		dist = sqrt(dx * dx + dy * dy);
		if (dist < 1.0 && dist > 0.001)
		{
			knockback_strength = 2;
			core->rc->pl_x += (dx / dist) * knockback_strength;
			core->rc->pl_y += (dy / dist) * knockback_strength;
		}
		enemy = enemy->next;
	}
}

bool	is_enemy(t_core *core, float x, float y)
{
	t_foes	*enemy;

	(void)y;
	enemy = core->foes;
	while (enemy)
	{
		if ((x > enemy->foe_x - 2 && x < enemy->foe_x + 2) \
			&& (y > enemy->foe_y - 2 && y < enemy->foe_y + 2) && \
			enemy->death != 2)
		{
			enemy->life -= \
			core->player->weapon[core->player->curr_wpn].damage.max;
			if (enemy->life <= 0 && enemy->death == 0)
				handle_enemy_death(core, enemy);
			return (true);
		}
		enemy = enemy->next;
	}
	return (false);
}

static void	anim_loop_death(t_core *core, t_foes *enemy)
{
	struct timeval	current;
	long			elapsed;

	(void)core;
	gettimeofday(&current, NULL);
	elapsed = (current.tv_sec - enemy->anim_death->update.tv_sec) * 1000
		+ (current.tv_usec - enemy->anim_death->update.tv_usec) / 1000;
	enemy->activ_img = enemy->anim_death->img_list;
	if (enemy->anim_death->speed && \
	elapsed > enemy->anim_death->speed && enemy->anim_death->nb > 0)
	{
		if (enemy->anim_death->img_list && enemy->anim_death->img_list->next)
		{
			enemy->anim_death->img_list = enemy->anim_death->img_list->next;
			enemy->activ_img = enemy->anim_death->img_list;
		}
		enemy->anim_death->update = current;
		enemy->anim_death->nb--;
	}
}

void	anim_death_foe(t_core *core)
{
	t_foes	*enemy;

	enemy = core->foes;
	while (enemy)
	{
		enemy->anim_death->speed = 0;
		if (enemy->death == 1)
		{
			if (!enemy || !enemy->anim_death)
				return ;
			anim_loop_death(core, enemy);
			if (enemy->anim_death->nb == 0 && enemy->death != 2)
			{
				enemy->death = 2;
				drop_object(core, enemy);
			}
		}
		enemy = enemy->next;
	}
}
