/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:49:25 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/06 20:40:56 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	seconds(void)
{
	struct timeval	sec;

	gettimeofday(&sec, NULL);
	return ((double)(sec.tv_sec) + (double)sec.tv_usec / 1000000.0f);
}

void	movements(t_core *core)
{
	double			current_time;

	current_time = seconds();
	if (core->player->last_time == 0.0)
		core->player->delta_time = 0.0;
	else
		core->player->delta_time = current_time - core->player->last_time;
	core->player->last_time = current_time;
	game_keypress(core, core->player->delta_time);
}

void	calculate_bob(t_core *core, double ampli, double freq)
{
	core->player->bobbing_speed = 2.0 * PI * freq;
	core->player->bob_y = ampli * sin(core->player->bobbing_speed
			* core->player->bobbing_time);
	core->player->bob_x = (ampli / 2.0)
		* sin(core->player->bobbing_speed * 2.0 * core->player->bobbing_time);
}

bool	is_moving(t_player *player)
{
	if (player->key_down || player->key_up
		|| player->key_left || player->key_right)
		return (true);
	return (false);
}

//WHOLE GAME ROUTINE
int	routine(void *param)
{
	t_core		*core;
	t_sprite	*sprite;

	core = (t_core *)param;
	if (core->state == START_MENU || core->state == OPTIONS_MENU
		|| core->state == MAPS_MENU)
	{
		sprite = hashmap_get(&core->hashmap_sprites, "skulls");
		if (update_sprite(sprite))
			skulls_render(core, core->y_pos);
	}
	else if (core->state == GAME)
	{
		if (is_moving(core->player))
			core->player->bobbing_time += core->player->delta_time;
		else
			core->player->bobbing_time = 0;
		calculate_bob(core, 10.0, 2.0);
		core->tmp_rc->max_r = S_LENGHT;
		movements(core);
		if (!start_game(core))
			return (false);
	}
	else if (core->state == PAUSE)
	{
		sprite = hashmap_get(&core->hashmap_sprites, "skulls");
		if (core->redraw)
			render_pause_menu(core);
		if (update_sprite(sprite))
			skulls_render_pause(core, core->y_pos);
	}
	//core->redraw = false;
	return (0);
}
