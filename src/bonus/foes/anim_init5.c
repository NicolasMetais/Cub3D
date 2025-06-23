/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_init5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:14:43 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/23 19:15:06 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_head_attack_list(t_core *core, t_foes *node)
{
	char		*atk[2];
	t_sprite	*init;

	atk[0] = "head_attack";
	atk[1] = "head_attack";
	init = hashmap_get(&core->hashmap_sprites, "head_attack");
	if (!init)
		return ;
	node->attack = copy_sprite(core, init, 0);
	node->attack->timer = 0;
	node->attack->speed = node->atk_speed;
}

void	init_head_walking_list(t_core *core, t_foes *node)
{
	char		*walk[3];
	t_sprite	*init;

	walk[0] = "head_walking";
	walk[1] = "head_walking";
	walk[2] = "head_walking";
	init = hashmap_get(&core->hashmap_sprites, "head_walking");
	if (!init)
		return ;
	node->walking = copy_sprite(core, init, 0);
	node->walking->timer = 0;
	node->walking->speed = node->walk_speed;
}

void	init_head_death_list(t_core *core, t_foes *node)
{
	char		*death[6];
	t_sprite	*init;

	death[0] = "head_frame_death";
	death[1] = "head_frame_death";
	death[2] = "head_frame_death";
	death[3] = "head_frame_death";
	death[4] = "head_frame_death";
	death[5] = "head_frame_death";
	init = hashmap_get(&core->hashmap_sprites, "head_frame_death");
	if (!init)
		return ;
	node->anim_death = copy_sprite(core, init, 6);
	node->anim_death->timer = 0;
	node->anim_death->speed = 200;
}

void	init_play_attack_list(t_core *core, t_foes *node)
{
	char		*atk[2];
	t_sprite	*init;

	atk[0] = "play_attack";
	atk[1] = "play_attack";
	init = hashmap_get(&core->hashmap_sprites, "play_attack");
	if (!init)
		return ;
	node->attack = copy_sprite(core, init, 0);
	node->attack->timer = 0;
	node->attack->speed = node->atk_speed;
}

void	init_play_walking_list(t_core *core, t_foes *node)
{
	char		*walk[4];
	t_sprite	*init;

	walk[0] = "play_walking";
	walk[1] = "play_walking";
	walk[2] = "play_walking";
	walk[3] = "play_walking";
	init = hashmap_get(&core->hashmap_sprites, "play_walking");
	if (!init)
		return ;
	node->walking = copy_sprite(core, init, 0);
	node->walking->timer = 0;
	node->walking->speed = node->walk_speed;
}
