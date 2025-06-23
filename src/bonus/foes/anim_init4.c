/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_init4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:13:35 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/23 19:14:00 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_play_death_list(t_core *core, t_foes *node)
{
	char		*death[6];
	t_sprite	*init;

	death[0] = "play_frame_death";
	death[1] = "play_frame_death";
	death[2] = "play_frame_death";
	death[3] = "play_frame_death";
	death[4] = "play_frame_death";
	death[5] = "play_frame_death";
	init = hashmap_get(&core->hashmap_sprites, "play_frame_death");
	if (!init)
		return ;
	node->anim_death = copy_sprite(core, init, 6);
	node->anim_death->timer = 0;
	node->anim_death->speed = 200;
}

void	init_poss_attack_list(t_core *core, t_foes *node)
{
	char		*atk[2];
	t_sprite	*init;

	atk[0] = "poss_attack";
	atk[1] = "poss_attack";
	init = hashmap_get(&core->hashmap_sprites, "poss_attack");
	if (!init)
		return ;
	node->attack = copy_sprite(core, init, 0);
	node->attack->timer = 0;
	node->attack->speed = node->atk_speed;
}

void	init_poss_walking_list(t_core *core, t_foes *node)
{
	char		*walk[4];
	t_sprite	*init;

	walk[0] = "poss_walking";
	walk[1] = "poss_walking";
	walk[2] = "poss_walking";
	walk[3] = "poss_walking";
	init = hashmap_get(&core->hashmap_sprites, "poss_walking");
	if (!init)
		return ;
	node->walking = copy_sprite(core, init, 0);
	node->walking->timer = 0;
	node->walking->speed = node->walk_speed;
}

void	init_poss_death_list(t_core *core, t_foes *node)
{
	char		*death[7];
	t_sprite	*init;

	death[0] = "poss_frame_death";
	death[1] = "poss_frame_death";
	death[2] = "poss_frame_death";
	death[3] = "poss_frame_death";
	death[4] = "poss_frame_death";
	death[5] = "poss_frame_death";
	death[6] = "poss_frame_death";
	init = hashmap_get(&core->hashmap_sprites, "poss_frame_death");
	if (!init)
		return ;
	node->anim_death = copy_sprite(core, init, 7);
	node->anim_death->timer = 0;
	node->anim_death->speed = 200;
}

void	init_sarg_attack_list(t_core *core, t_foes *node)
{
	char		*atk[2];
	t_sprite	*init;

	atk[0] = "sarg_attack";
	atk[1] = "sarg_attack";
	init = hashmap_get(&core->hashmap_sprites, "sarg_attack");
	if (!init)
		return ;
	node->attack = copy_sprite(core, init, 0);
	node->attack->timer = 0;
	node->attack->speed = node->atk_speed;
}
