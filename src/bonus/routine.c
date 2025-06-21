/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:49:25 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/21 19:04:32 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	pause_routine(t_sprite *sprite, t_core *core)
{
	if (core->state == PAUSE)
	{
		sprite = hashmap_get(&core->hashmap_sprites, "skulls");
		if (!sprite)
			return (false);
		if (core->redraw)
			render_pause_menu(core);
		if (update_sprite(sprite))
			skulls_render_pause(core, core->y_pos);
	}
	return (true);
}

bool	game_routine(t_sprite *sprite, t_core *core)
{
	if (core->state == GAME)
	{
		if (is_moving(core->player))
			core->player->bobbing_time += core->player->delta_time;
		else
			core->player->bobbing_time = 0;
		calculate_bob(core, 10.0, 2.0);
		core->rc->max_r = S_LENGHT;
		movements(core);
		if (!start_game(core))
			return (false);
	}
	else if (core->state == GAME_OVER)
	{
		printf("yeweqweqewqs\n");
		sprite = (t_sprite *)hashmap_get(&core->hashmap_sprites, "the_end");
		if (update_sprite(sprite))
			render_game_over(core);
	}
	if (!pause_routine(sprite, core))
		return (false);
	return (true);
}

//WHOLE GAME ROUTINE
int	routine(void *param)
{
	t_core		*core;
	t_sprite	*sprite;

	core = (t_core *)param;
	sprite = NULL;
	UpdateMusicStream(core->bg_music);
	if (!IsMusicStreamPlaying(core->bg_music))
	{
		UnloadMusicStream(core->bg_music);
		play_random_music(core);
	}
	if (core->state == START_MENU || core->state == OPTIONS_MENU
		|| core->state == MAPS_MENU)
	{
		sprite = hashmap_get(&core->hashmap_sprites, "skulls");
		if (!sprite)
			return (false);
		if (update_sprite(sprite))
			skulls_render(core, core->y_pos);
	}
	if (!game_routine(sprite, core))
		return (false);
	core->redraw = false;
	return (0);
}
