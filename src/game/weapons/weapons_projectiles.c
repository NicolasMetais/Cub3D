/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_projectiles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:41:57 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/06 15:29:05 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_projectile_node	*new_node(t_core *core,
		float x, float y, float angle)
{
	t_projectile_node	*new;

	new = malloc(sizeof(t_projectile_node));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->dir_x = cosf(angle);
	new->dir_y = sinf(angle);
	if (core->player->curr_wpn == 5)
		new->speed = 0.6f;
	else
		new->speed = 0.4f;
	new->angle = angle;
	if (core->player->curr_wpn == 6)
		new->sprite = hashmap_get(&core->hashmap_sprites, "plasma_proj");
	else if (core->player->curr_wpn == 5)
			new->sprite = hashmap_get(&core->hashmap_sprites, "rocket");
	else if (core->player->curr_wpn == 7)
			new->sprite = hashmap_get(&core->hashmap_sprites, "BFG9000_proj");
	new->activ_img = new->sprite->img_list;
	gettimeofday(&new->timer, NULL);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

bool	new_proj(t_core *core, float x, float y, float angle)
{
	t_projectile_node	*new;
	t_projectile_node	*last;

	new = new_node(core, x, y, angle);
	if (!new)
		return (false);
	if (!core->proj.proj_list)
		core->proj.proj_list = new;
	else
	{
		last = core->proj.proj_list;
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
	return (true);
}
