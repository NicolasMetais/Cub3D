/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_fired.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:18:48 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/21 17:01:33 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	choose_size_and_sprite(t_core *core, t_impact_node **new)
{
	if ((*new)->wpn_type == 6)
	{
		(*new)->size = 3;
		(*new)->sprite = hashmap_get(&core->hashmap_sprites, "plasma_puff");
	}
	else if ((*new)->wpn_type == 5)
	{
		(*new)->size = 5;
		(*new)->sprite = hashmap_get(&core->hashmap_sprites, "rocket_puff");
	}
	else if ((*new)->wpn_type == 7)
	{
		(*new)->size = 3;
		(*new)->sprite = hashmap_get(&core->hashmap_sprites, "BFG9000_puff");
	}
	else
	{
		(*new)->size = 0.2;
		(*new)->sprite = hashmap_get(&core->hashmap_sprites, "puff");
	}
	if (!(*new)->sprite)
		return (false);
	return (true);
}

static t_impact_node	*new_node(t_core *core, float x, float y, int wpn_type)
{
	t_impact_node	*new;

	new = malloc(sizeof(t_impact_node));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->lifetime = 15;
	new->wpn_type = wpn_type;
	if (!choose_size_and_sprite(core, &new))
		return (NULL);
	new->activ_img = new->sprite->img_list;
	new->frame = 0;
	gettimeofday(&new->timer, NULL);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

bool	new_impact(t_core *core, float x, float y, int wpn_type)
{
	t_impact_node	*new;
	t_impact_node	*last;

	new = new_node(core, x, y, wpn_type);
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
	if (!core->infinite_ammos)
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
		shoot_pistol(core, core->rc->pl_angle);
	if (core->player->curr_wpn == 6)
		shoot_projectile(core, core->rc->pl_angle);
}

void	weapon_fired(t_core *core)
{
	int	ammo_index;

	ammo_index = core->player->weapon[core->player->curr_wpn].ammo_type;
	if (core->player->ammo[ammo_index] == 0)
		return ;
	if (!core->infinite_ammos)
	{
		if (core->player->ammo[ammo_index] >= 1)
			core->player->ammo[ammo_index] -= 1;
	}
	if (core->player->curr_wpn == 2)
		shoot_pistol(core, core->rc->pl_angle);
	if (core->player->curr_wpn == 3)
		shoot_shotgun(core);
	if (core->player->curr_wpn > 4)
		shoot_projectile(core, core->rc->pl_angle);
}
