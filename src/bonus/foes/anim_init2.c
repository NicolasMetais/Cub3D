/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_init2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:11:08 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/23 19:11:38 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cybr_attack_list(t_core *core, t_foes *node)
{
	char		*atk[2];
	t_sprite	*init;

	atk[0] = "cybr_attack";
	atk[1] = "cybr_attack";
	init = hashmap_get(&core->hashmap_sprites, "cybr_attack");
	if (!init)
		return ;
	node->attack = copy_sprite(core, init, 0);
	node->attack->timer = 0;
	node->attack->speed = node->atk_speed;
}

void	init_cybr_walking_list(t_core *core, t_foes *node)
{
	char		*walk[4];
	t_sprite	*init;

	walk[0] = "cybr_walking";
	walk[1] = "cybr_walking";
	walk[2] = "cybr_walking";
	walk[3] = "cybr_walking";
	init = hashmap_get(&core->hashmap_sprites, "cybr_walking");
	if (!init)
		return ;
	node->walking = copy_sprite(core, init, 0);
	node->walking->timer = 0;
	node->walking->speed = node->walk_speed;
}

void	init_cybr_death_list(t_core *core, t_foes *node)
{
	char		*death[8];
	t_sprite	*init;

	death[0] = "cybr_frame_death";
	death[1] = "cybr_frame_death";
	death[2] = "cybr_frame_death";
	death[3] = "cybr_frame_death";
	death[4] = "cybr_frame_death";
	death[5] = "cybr_frame_death";
	death[6] = "cybr_frame_death";
	init = hashmap_get(&core->hashmap_sprites, "cybr_frame_death");
	if (!init)
		return ;
	node->anim_death = copy_sprite(core, init, 7);
	node->anim_death->timer = 0;
	node->anim_death->speed = 200;
}

void	init_head_list(t_core *core, t_foes *node)
{
	node->life = 1;
	node->speed = 0.1;
	node->range = 12;
	node->atk_speed = 200;
	node->walk_speed = 300;
	node->damage = 5;
	node->init_frame = 6;
	node->img_body = hashmap_get(&core->hashmap, "HEADL0");
	if (!node->img_body)
		return ;
	init_head_walking_list(core, node);
	init_head_attack_list(core, node);
	init_head_death_list(core, node);
}

void	init_play_list(t_core *core, t_foes *node)
{
	node->life = 1;
	node->speed = 0.1;
	node->range = 32;
	node->atk_speed = 100;
	node->walk_speed = 300;
	node->damage = 1;
	node->init_frame = 6;
	node->img_body = hashmap_get(&core->hashmap, "PLAYW0");
	if (!node->img_body)
		return ;
	init_play_walking_list(core, node);
	init_play_attack_list(core, node);
	init_play_death_list(core, node);
}
