/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_fired.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:18:48 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/08 19:03:15 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_impact_node	*new_node(t_core *core, float x, float y)
{
	t_impact_node	*new;

	new = malloc(sizeof(t_impact_node));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->lifetime = 15;
	if (core->player->curr_wpn == 6)
		new->sprite = hashmap_get(&core->hashmap_sprites, "plasma_puff");
	else if (core->player->curr_wpn == 5)
		new->sprite = hashmap_get(&core->hashmap_sprites, "rocket_puff");
	else if (core->player->curr_wpn == 7)
		new->sprite = hashmap_get(&core->hashmap_sprites, "BFG9000_puff");
	else
		new->sprite = hashmap_get(&core->hashmap_sprites, "puff");
	if (!new->sprite)
		return (NULL);
	new->activ_img = new->sprite->img_list;
	new->frame = 0;
	gettimeofday(&new->timer, NULL);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

bool	new_impact(t_core *core, float x, float y)
{
	t_impact_node	*new;
	t_impact_node	*last;

	new = new_node(core, x, y);
	if (!new)
		return (false);
	if (!core->impact.impact_list)
		core->impact.impact_list = new;
	else
	{
		last = core->impact.impact_list;
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
	return (true);
}

void	fire_charged_weapons(t_core *core)
{
	int	ammo_index;

	ammo_index = core->player->weapon[core->player->curr_wpn].ammo_type;
	if (!INFINITE_AMMOS)
	{
		if (core->player->ammo[ammo_index] >= 1)
			core->player->ammo[ammo_index] -= 1;
	}
	if (core->player->ammo[ammo_index] == 0)
	{
		core->player->firing = false;
		return ;
	}
	if (core->player->curr_wpn == 4)
		shoot_pistol(core, core->tmp_rc->pl_angle);
	if (core->player->curr_wpn == 6)
		shoot_projectile(core, core->tmp_rc->pl_angle);
}

void	weapon_fired(t_core *core)
{
	int	ammo_index;

	ammo_index = core->player->weapon[core->player->curr_wpn].ammo_type;
	if (core->player->ammo[ammo_index] == 0)
		return ;
	if (!INFINITE_AMMOS)
	{
		if (core->player->ammo[ammo_index] >= 1)
			core->player->ammo[ammo_index] -= 1;
	}
	if (core->player->curr_wpn == 2)
		shoot_pistol(core, core->tmp_rc->pl_angle);
	if (core->player->curr_wpn == 3)
		shoot_shotgun(core);
	if (core->player->curr_wpn > 4)
		shoot_projectile(core, core->tmp_rc->pl_angle);
}
