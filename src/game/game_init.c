/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:55:32 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/28 22:36:34 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	hud_init(t_core *core)
{
	t_img	*arms;

	core->hud_img = gc_malloc(&core->gc, sizeof(t_hud_img), STRUCT, "hug_img");
	if (!core->hud_img)
		return (false);
	core->hud_img->clean_hud = hashmap_get(&core->hashmap, "hud");
	core->hud_img->hud = hashmap_get(&core->hashmap, "hud");
	arms = hashmap_get(&core->hashmap, "arms");
	transparency(core->hud_img->hud, arms, 520, 0);
	return (true);
}

bool	game_init(t_core *core)
{
	core->player = gc_malloc(&core->gc, sizeof(t_player),
			STRUCT, "struct player");
	if (!core->player)
		return (false);
	core->player->position = gc_malloc(&core->gc, sizeof(t_pos),
			STRUCT, "pos player");
	if (!core->player->position)
		return (false);
	core->player->position->x = core->spawn->x;
	core->player->position->y = core->spawn->y;
	core->player->health = 100;
	core->player->armor = 0;
	core->player->ammo[0] = 50;
	core->player->ammo[1] = 0;
	core->player->ammo[2] = 0;
	core->player->ammo[3] = 0;
	core->player->current_weapon = 2;
	if (!hud_init(core))
		return (false);
	if (!head_init(core))
		return (false);
	weapons_init(core->player->weapon);
	mlx_clear_window(core->mlx, core->win);
	return (true);
}
