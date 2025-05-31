/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:38:24 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/01 00:13:08 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	on_keypress_game(int key, t_core *core)
{
	if (key == XK_Left || key == XK_a || key == XK_A)
		core->player->key_left = true;
	else if (key == XK_Right || key == XK_d || key == XK_D)
		core->player->key_right = true;
	else if (key == XK_Up || key == XK_w || key == XK_W)
		core->player->key_up = true;
	else if (key == XK_Down || key == XK_s || key == XK_S)
		core->player->key_down = true;
	if (key == XK_1 && core->player->weapon[1].owned)
		core->player->current_weapon = 1;
	if (key == XK_2 && core->player->weapon[2].owned)
		core->player->current_weapon = 2;
	if (key == XK_3 && core->player->weapon[3].owned)
		core->player->current_weapon = 3;
	if (key == XK_5 && core->player->weapon[5].owned)
		core->player->current_weapon = 5;
	if (key == XK_6 && core->player->weapon[6].owned)
		core->player->current_weapon = 6;
	if (key == XK_7 && core->player->weapon[7].owned)
		core->player->current_weapon = 7;

}

void	on_keyrelease_game(int key, t_core *core)
{
	if (key == XK_Left || key == XK_a || key == XK_A)
		core->player->key_left = false;
	else if (key == XK_Right || key == XK_d || key == XK_D)
		core->player->key_right = false;
	else if (key == XK_Up || key == XK_w || key == XK_W)
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
}
