/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:40:42 by tvacher           #+#    #+#             */
/*   Updated: 2025/05/31 15:08:39 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void handle_straf_right(t_core *core, double move_dist)
{
	double	straf_x;
	double	straf_y;
    double next_x;
    double next_y;
	double	margin_x;
	double	margin_y;
	int map_x;
	int map_y;

	margin_x = 0;
	margin_y = 0;
	straf_x = core->tmp_rc->pldelt_y;
	straf_y = -core->tmp_rc->pldelt_x;
	next_x = core->tmp_rc->pl_x - straf_x * move_dist;
	next_y = core->tmp_rc->pl_y - straf_y * move_dist;
    if (straf_x > 0)
        margin_x = -1.5;
    if (straf_y > 0)
        margin_y = -1.5;
    map_x = (int)((next_x + margin_x) / 8);
    map_y = (int)(core->tmp_rc->pl_y / 8);
    if (core->map[map_y][map_x] != '1')
        core->tmp_rc->pl_x = next_x;
    map_x = (int)(core->tmp_rc->pl_x / 8);
    map_y = (int)((next_y + margin_y) / 8);
    if (core->map[map_y][map_x] != '1')
        core->tmp_rc->pl_y = next_y;
}

static void handle_straf_left(t_core *core, double move_dist)
{
	double	straf_x;
	double	straf_y;
    double next_x;
    double next_y;
	double	margin_x;
	double	margin_y;
	int map_x;
	int map_y;

	margin_x = 0;
	margin_y = 0;
	straf_x = -core->tmp_rc->pldelt_y;
	straf_y = core->tmp_rc->pldelt_x;
	next_x = core->tmp_rc->pl_x - straf_x * move_dist;
	next_y = core->tmp_rc->pl_y - straf_y * move_dist;
    if (straf_x > 0)
        margin_x = -1.5;
    if (straf_y > 0)
        margin_y = -1.5;
    map_x = (int)((next_x + margin_x) / 8);
    map_y = (int)(core->tmp_rc->pl_y / 8);
    if (core->map[map_y][map_x] != '1')
        core->tmp_rc->pl_x = next_x;
    map_x = (int)(core->tmp_rc->pl_x / 8);
    map_y = (int)((next_y + margin_y) / 8);
    if (core->map[map_y][map_x] != '1')
        core->tmp_rc->pl_y = next_y;
}

static void handle_down(t_core *core, double move_dist)
{
    double next_x;
    double next_y;
	double	margin_x;
	double	margin_y;
	int map_x;
	int map_y;

	margin_x = 0;
	margin_y = 0;
	next_x = core->tmp_rc->pl_x - core->tmp_rc->pldelt_x * move_dist;
	next_y = core->tmp_rc->pl_y - core->tmp_rc->pldelt_y * move_dist;
    if (core->tmp_rc->pldelt_x > 0)
        margin_x = -1.5;
    if (core->tmp_rc->pldelt_y > 0)
        margin_y = -1.5;
    map_x = (int)((next_x + margin_x) / 8);
    map_y = (int)(core->tmp_rc->pl_y / 8);
    if (core->map[map_y][map_x] != '1')
        core->tmp_rc->pl_x = next_x;

    map_x = (int)(core->tmp_rc->pl_x / 8);
    map_y = (int)((next_y + margin_y) / 8);
    if (core->map[map_y][map_x] != '1')
        core->tmp_rc->pl_y = next_y;
}

static void handle_up(t_core *core, double move_dist)
{
    double next_x;
    double next_y;
	double	margin_x;
	double	margin_y;
	int map_x;
	int map_y;

	margin_x = 0;
	margin_y = 0;
	next_x = core->tmp_rc->pl_x + core->tmp_rc->pldelt_x * move_dist;
	next_y = core->tmp_rc->pl_y + core->tmp_rc->pldelt_y * move_dist;
    if (core->tmp_rc->pldelt_x < 0)
        margin_x = -1.5;
    if (core->tmp_rc->pldelt_y < 0)
        margin_y = -1.5;
    map_x = (int)((next_x + margin_x) / 8);
    map_y = (int)(core->tmp_rc->pl_y / 8);
    if (core->map[map_y][map_x] != '1')
        core->tmp_rc->pl_x = next_x;
    map_x = (int)(core->tmp_rc->pl_x / 8);
    map_y = (int)((next_y + margin_y) / 8);
    if (core->map[map_y][map_x] != '1')
        core->tmp_rc->pl_y = next_y;
}

void    move_player(t_core *core, t_move move, double delta_time)
{
    double move_dist = core->player->speed * delta_time;

    if (core->tmp_rc->pldelt_x < 0)
        core->tmp_rc->of_x = -move_dist;
    else
        core->tmp_rc->of_x = move_dist;
    if (core->tmp_rc->pldelt_y < 0)
        core->tmp_rc->of_y = -move_dist;
    else
        core->tmp_rc->of_y = move_dist;
    init_new_pos(core);
    if (move == UP)
        handle_up(core, move_dist);
    else if (move == DOWN)
        handle_down(core, move_dist);
    else if (move == LEFT)
        handle_left(core, move_dist);
    else if (move == RIGHT)
        handle_right(core, move_dist);
    else if (move == S_RIGHT)
        handle_straf_right(core, move_dist);
    else if (move == S_LEFT)
        handle_straf_left(core, move_dist);
    core->redraw = true;
}
