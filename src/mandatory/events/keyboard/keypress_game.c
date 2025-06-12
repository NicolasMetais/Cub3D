/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:38:24 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/30 18:00:32 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	on_keypress_game(int key, t_core *core)
{
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
	else if (key == 65364 || key == 's')
		core->player->key_down = true;
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
	else if (key == 65364 || key == 's')
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
