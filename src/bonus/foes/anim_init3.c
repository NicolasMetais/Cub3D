/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_init3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:12:15 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/23 19:12:37 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sarg_walking_list(t_core *core, t_foes *node)
{
	char		*walk[4];
	t_sprite	*init;

	walk[0] = "sarg_walking";
	walk[1] = "sarg_walking";
	walk[2] = "sarg_walking";
	walk[3] = "sarg_walking";
	init = hashmap_get(&core->hashmap_sprites, "sarg_walking");
	if (!init)
		return ;
	node->walking = copy_sprite(core, init, 0);
	node->walking->timer = 0;
	node->walking->speed = node->walk_speed;
}

void	init_sarg_death_list(t_core *core, t_foes *node)
{
	char		*death[5];
	t_sprite	*init;

	death[0] = "sarg_frame_death";
	death[1] = "sarg_frame_death";
	death[2] = "sarg_frame_death";
	death[3] = "sarg_frame_death";
	death[4] = "sarg_frame_death";
	init = hashmap_get(&core->hashmap_sprites, "sarg_frame_death");
	if (!init)
		return ;
	node->anim_death = copy_sprite(core, init, 5);
	node->anim_death->timer = 0;
	node->anim_death->speed = 200;
}

void	init_skul_attack_list(t_core *core, t_foes *node)
{
	char		*atk[2];
	t_sprite	*init;

	atk[0] = "skul_attack";
	atk[1] = "skul_attack";
	init = hashmap_get(&core->hashmap_sprites, "skul_attack");
	if (!init)
		return ;
	node->attack = copy_sprite(core, init, 0);
	node->attack->timer = 0;
	node->attack->speed = node->atk_speed;
}

void	init_skul_walking_list(t_core *core, t_foes *node)
{
	char		*walk[2];
	t_sprite	*init;

	walk[0] = "skul_walking";
	walk[1] = "skul_walking";
	init = hashmap_get(&core->hashmap_sprites, "skul_walking");
	if (!init)
		return ;
	node->walking = copy_sprite(core, init, 0);
	node->walking->timer = 0;
	node->walking->speed = node->walk_speed;
}

void	init_skul_death_list(t_core *core, t_foes *node)
{
	char		*death[4];
	t_sprite	*init;

	death[0] = "skul_frame_death";
	death[1] = "skul_frame_death";
	death[2] = "skul_frame_death";
	death[3] = "skul_frame_death";
	init = hashmap_get(&core->hashmap_sprites, "skul_frame_death");
	if (!init)
		return ;
	node->anim_death = copy_sprite(core, init, 4);
	node->anim_death->timer = 0;
	node->anim_death->speed = 200;
}
