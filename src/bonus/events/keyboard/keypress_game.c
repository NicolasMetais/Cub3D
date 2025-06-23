/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:38:24 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/23 17:55:47 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	switch_weapons(int key, t_core *core)
{
	int	index;

	index = core->player->curr_wpn;
	if (key == XK_1 && core->player->weapon[0].owned)
		key = XK_0;
	if (key >= XK_0 && key <= XK_7 && core->player->weapon[key - XK_0].owned)
	{
		core->player->firing = false;
		core->player->weapon[index].lock = false;
		core->player->weapon[index].anim->activ = false;
		core->player->weapon[index].anim->started = false;
		core->player->weapon[index].anim->img_list
			= core->player->weapon[index].anim->head;
		core->player->curr_wpn = key - XK_0;
	}
}

void	on_keypress_game(int key, t_core *core)
{
	if (!core->enter)
	{
		core->enter = 1;
		return ;
	}
	if (key == 65361)
		core->player->key_left = true;
	else if (key == 'a')
		core->player->straf_left = true;
	else if (key == 65363)
		core->player->key_right = true;
	else if (key == 'd')
		core->player->straf_right = true;
	else if (key == 65362 || key == 'w')
		core->player->key_up = true;
	else if (key == XK_Down || key == XK_s || key == XK_S)
		core->player->key_down = true;
	else if (key == 'e')
		handle_door(core);
	switch_weapons(key, core);
}

void	on_keyrelease_game(int key, t_core *core)
{
	if (key == 65361)
		core->player->key_left = false;
	else if (key == 'a')
		core->player->straf_left = false;
	else if (key == 65363)
		core->player->key_right = false;
	else if (key == 'd')
		core->player->straf_right = false;
	else if (key == 65362 || key == 'w')
		core->player->key_up = false;
	else if (key == XK_Down || key == XK_s || key == XK_S)
		core->player->key_down = false;
}

void	game_keypress(t_core *core, double delta_time)
{
	if (core->player->key_up)
		move_player(core, UP, delta_time);
	if (core->player->key_down)
		move_player(core, DOWN, delta_time);
	if (core->player->key_left)
		move_player(core, LEFT, delta_time);
	if (core->player->key_right)
		move_player(core, RIGHT, delta_time);
	if (core->player->straf_right)
		move_player(core, S_RIGHT, delta_time);
	if (core->player->straf_left)
		move_player(core, S_LEFT, delta_time);
}
