/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:55:32 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/21 16:22:59 by nmetais          ###   ########.fr       */
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
	if (core->map_height > core->map_width)
		core->rc->map_size = core->map_height * 8;
	else
		core->rc->map_size = core->map_width * 8;
	core->player->position->x = core->spawn->x;
	core->player->position->y = core->spawn->y;
	core->player->health = 100;
	core->player->ammo[0] = 200;
	core->player->ammo[1] = 50;
	core->player->ammo[2] = 50;
	core->player->ammo[3] = 300;
	core->player->curr_wpn = 2;
	core->player->speed = core->speed;
	core->menu_img->sliders[1].int_var = &core->player->speed;
	return (true);
}

bool	hud_buffers(t_core *core)
{
	core->hud_img->ammo1 = load_buffer(core->hud_img->ammo1, 60, 30, core);
	if (!core->hud_img->ammo1)
		return (false);
	core->hud_img->ammo2 = load_buffer(core->hud_img->ammo2, 60, 30, core);
	if (!core->hud_img->ammo2)
		return (false);
	core->hud_img->ammo3 = load_buffer(core->hud_img->ammo3, 60, 30, core);
	if (!core->hud_img->ammo3)
		return (false);
	core->hud_img->ammo4 = load_buffer(core->hud_img->ammo4, 60, 30, core);
	if (!core->hud_img->ammo4)
		return (false);
	core->hud_img->life = load_buffer(core->hud_img->life, 220, 48, core);
	if (!core->hud_img->life)
		return (false);
	core->hud_img->ammo = load_buffer(core->hud_img->ammo, 220, 48, core);
	if (!core->hud_img->ammo)
		return (false);
	core->hud_img->armor = load_buffer(core->hud_img->armor, 220, 48, core);
	if (!core->hud_img->armor)
		return (false);
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
	if (!core->hud_img->clean_hud || !core->hud_img->hud || !arms)
		return (false);
	transparency(core->hud_img->hud, arms, 520, 0);
	if (!hud_buffers(core))
		return (false);
	core->hud_img->hud_render = true;
	core->hud_img->ammo1_render = true;
	core->hud_img->ammo2_render = true;
	core->hud_img->ammo3_render = true;
	core->hud_img->ammo4_render = true;
	core->hud_img->health_render = true;
	core->hud_img->armor_render = true;
	core->hud_img->new_weapon_render = true;
	return (true);
}

bool	more_buffers(t_core *core)
{
	if (!weapons_init(core->player->weapon, core))
		return (false);
	core->weapon_buffer = load_buffer(core->weapon_buffer, 880, 804, core);
	if (!core->weapon_buffer)
		return (false);
	core->hud_img->pause_buffer = load_buffer(core->hud_img->pause_buffer,
			S_LENGHT, S_HEIGHT, core);
	if (!core->hud_img->pause_buffer)
		return (false);
	core->hud_img->clean_pause_buffer = load_buffer(
			core->hud_img->clean_pause_buffer, S_LENGHT, S_HEIGHT, core);
	if (!core->hud_img->clean_pause_buffer)
		return (false);
	if (!item_init(core))
		return (false);
	if (!notif_init(core))
		return (false);
	if (!init_foes(core))
		return (false);
	return (true);
}

bool	game_init(t_core *core)
{
	core->game_img = gc_malloc(&core->gc, sizeof(t_img), STRUCT, "game_img");
	if (!core->game_img)
		return (false);
	core->game_img = load_buffer(core->game_img, S_LENGHT,
			S_HEIGHT - 160, core);
	if (!core->game_img)
		return (false);
	core->scroll_ingame = S_LENGHT / 2;
	core->redraw = true;
	if (!player_init(core))
		return (false);
	if (!moves_init(core))
		return (false);
	if (!hud_init(core))
		return (false);
	if (!head_init(core))
		return (false);
	if (!init_map_textures(core))
		return (false);
	if (!more_buffers(core))
		return (false);
	mlx_clear_window(core->mlx, core->win);
	core->hud_redraw = true;
	return (true);
}
