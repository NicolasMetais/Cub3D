/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:55:32 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/31 15:20:01 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	player_init(t_core *core)
{
	core->player = gc_malloc(&core->gc, sizeof(t_player),
			STRUCT, "struct player");
	if (!core->player)
		return (false);
	ft_memset(core->player, 0, sizeof(t_player));
	core->player->position = gc_malloc(&core->gc, sizeof(t_pos),
			STRUCT, "pos player");
	if (!core->player->position)
		return (false);
	core->player->position->x = core->spawn->x;
	core->player->position->y = core->spawn->y;
	core->player->health = 100;
	core->player->ammo[0] = 50;
	core->player->current_weapon = 2;
	core->player->speed = PLAYER_SPEED;
	return (true);
}

bool	hud_init(t_core *core)
{
	t_img	*arms;

	core->hud_img = gc_malloc(&core->gc, sizeof(t_hud_img), STRUCT, "hug_img");
	if (!core->hud_img)
		return (false);
	core->hud_img->clean_hud = (t_img *)hashmap_get(&core->hashmap, "hud");
	core->hud_img->hud = (t_img *)hashmap_get(&core->hashmap, "hud");
	arms = (t_img *)hashmap_get(&core->hashmap, "arms");
	transparency(core->hud_img->hud, arms, 520, 0);
	return (true);
}

bool	game_init(t_core *core)
{
	core->game_img = gc_malloc(&core->gc, sizeof(t_img), STRUCT, "game_img");
	if (!core->game_img)
		return (false);
	core->game_img->img = mlx_new_image(core->mlx, S_LENGHT, S_HEIGHT);
	if (!core->game_img->img)
		return (false);
	core->game_img->addr = mlx_get_data_addr(core->game_img->img,
			&core->game_img->bpp, &core->game_img->line_len,
			&core->game_img->endian);
	core->game_img->width = S_LENGHT;
	core->game_img->height = S_HEIGHT;
	core->redraw = true;
	hashmap_insert(&core->hashmap, "game_img", (void *)core->game_img, core);
	if (!player_init(core))
		return (false);
	if (!hud_init(core))
		return (false);
	if (!head_init(core))
		return (false);
    init_map_textures(core);
	weapons_init(core->player->weapon, core);
	mlx_clear_window(core->mlx, core->win);
	return (true);
}
