/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_anim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:56:30 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/24 17:37:55 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_enemy_death(t_core *core, t_foes *enemy)
{
	(void)core;
	enemy->death = 1;
}

static void	anim_loop_walk(t_core *core, t_foes *enemy)
{
	struct timeval	current;
	long			elapsed;

	(void)core;
	gettimeofday(&current, NULL);
	elapsed = (current.tv_sec - enemy->walking->update.tv_sec) * 1000
		+ (current.tv_usec - enemy->walking->update.tv_usec) / 1000;
	enemy->activ_img = enemy->walking->img_list;
	if (enemy->walking->speed && elapsed > enemy->walking->speed)
	{
		if (enemy->walking->img_list && enemy->walking->img_list->next)
		{
			enemy->walking->img_list = enemy->walking->img_list->next;
			enemy->activ_img = enemy->walking->img_list;
		}
		enemy->walking->update = current;
	}
}

void	anim_walk_foe(t_core *core)
{
	t_foes	*enemy;

	if (!core->foes)
		return ;
	enemy = core->foes;
	while (enemy)
	{
		enemy->walking->speed = enemy->walk_speed;
		if (enemy->death == 0 && enemy->atk == 0)
		{
			if (!enemy || !enemy->walking)
				return ;
			anim_loop_walk(core, enemy);
		}
		enemy = enemy->next;
	}
}

static void	anim_loop_attack(t_core *core, t_foes *enemy)
{
	struct timeval	current;
	long			elapsed;

	gettimeofday(&current, NULL);
	elapsed = (current.tv_sec - enemy->attack->update.tv_sec) * 1000
		+ (current.tv_usec - enemy->attack->update.tv_usec) / 1000;
	enemy->activ_img = enemy->attack->img_list;
	if (enemy->attack->speed && elapsed > enemy->attack->speed)
	{
		if (enemy->attack->img_list && enemy->attack->img_list->next)
		{
			enemy->attack->img_list = enemy->attack->img_list->next;
			enemy->activ_img = enemy->attack->img_list;
		}
		enemy->attack->update = current;
		if (enemy->atk == 1)
		{
			if (core->player->armor > 0 && core->godmod == 0)
				core->player->armor -= enemy->damage;
			else if (core->godmod == 0)
				core->player->health -= enemy->damage;
		}
		if (core->player->health <= 0)
			core->state = GAME_OVER;
	}
}

void	anim_attack_foe(t_core *core)
{
	t_foes	*enemy;

	enemy = core->foes;
	while (enemy)
	{
		enemy->attack->speed = enemy->atk_speed;
		if (enemy->death == 0 && enemy->atk == 1)
		{
			if (!enemy || !enemy->attack)
				return ;
			anim_loop_attack(core, enemy);
		}
		enemy = enemy->next;
	}
}
