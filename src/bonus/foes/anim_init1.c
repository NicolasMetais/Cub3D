/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_init1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:09:37 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/24 19:21:51 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_poss_list(t_core *core, t_foes *node)
{
	node->life = 1;
	node->speed = 0.1;
	node->range = 32;
	node->atk_speed = 100;
	node->walk_speed = 300;
	node->damage = 1;
	node->init_frame = 7;
	node->img_body = hashmap_get(&core->hashmap, "POSSU0");
	if (!node->img_body)
		return ;
	node->death_sound = &core->sound_list.player_death;
	init_poss_walking_list(core, node);
	init_poss_attack_list(core, node);
	init_poss_death_list(core, node);
}

void	init_sarg_list(t_core *core, t_foes *node)
{
	node->life = 1;
	node->speed = 0.2;
	node->range = 12;
	node->atk_speed = 200;
	node->walk_speed = 300;
	node->damage = 10;
	node->init_frame = 5;
	node->img_body = hashmap_get(&core->hashmap, "SARGN0");
	if (!node->img_body)
		return ;
	node->death_sound = &core->sound_list.imp_death;
	init_sarg_walking_list(core, node);
	init_sarg_attack_list(core, node);
	init_sarg_death_list(core, node);
}

void	init_skul_list(t_core *core, t_foes *node)
{
	node->life = 1;
	node->speed = 0.3;
	node->range = 8;
	node->atk_speed = 200;
	node->walk_speed = 300;
	node->damage = 5;
	node->init_frame = 4;
	node->death_sound = &core->sound_list.barrel_exp;
	init_skul_walking_list(core, node);
	init_skul_attack_list(core, node);
	init_skul_death_list(core, node);
}

void	init_cybr_list(t_core *core, t_foes *node)
{
	node->life = 1;
	node->speed = 0.1;
	node->range = 24;
	node->atk_speed = 200;
	node->walk_speed = 300;
	node->damage = 4;
	node->init_frame = 7;
	node->img_body = hashmap_get(&core->hashmap, "CYBRP0");
	if (!node->img_body)
		return ;
	node->death_sound = &core->sound_list.demon_death;
	init_cybr_walking_list(core, node);
	init_cybr_attack_list(core, node);
	init_cybr_death_list(core, node);
}

void	init_foe_img(t_core *core, t_foes *node)
{
	if (node->type == 1)
		init_cybr_list(core, node);
	else if (node->type == 2)
		init_head_list(core, node);
	else if (node->type == 3)
		init_poss_list(core, node);
	else if (node->type == 4)
		init_play_list(core, node);
	else if (node->type == 5)
		init_skul_list(core, node);
	else
		init_sarg_list(core, node);
	gettimeofday(&node->walking->update, NULL);
	gettimeofday(&node->attack->update, NULL);
	gettimeofday(&node->anim_death->update, NULL);
	node->activ_img = node->walking->img_list;
}
