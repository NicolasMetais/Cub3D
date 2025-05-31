/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:40:42 by tvacher           #+#    #+#             */
/*   Updated: 2025/05/30 19:45:46 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void handle_down(t_core *core, double move_dist)
{
    double next_x = core->tmp_rc->pl_x - core->tmp_rc->pldelt_x * move_dist;
    double next_y = core->tmp_rc->pl_y - core->tmp_rc->pldelt_y * move_dist;

    double margin_x = 1.5;
    if (core->tmp_rc->pldelt_x > 0)
        margin_x = -margin_x;

    double margin_y = 1.5;
    if (core->tmp_rc->pldelt_y > 0)
        margin_y = -margin_y;
    int map_x = (int)((next_x + margin_x) / 8);
    int map_y = (int)(core->tmp_rc->pl_y / 8);
    if (core->map[map_y][map_x] != '1')
        core->tmp_rc->pl_x = next_x;

    map_x = (int)(core->tmp_rc->pl_x / 8);
    map_y = (int)((next_y + margin_y) / 8);
    if (core->map[map_y][map_x] != '1')
        core->tmp_rc->pl_y = next_y;
}

static void handle_up(t_core *core, double move_dist)
{
    double next_x = core->tmp_rc->pl_x + core->tmp_rc->pldelt_x * move_dist;
    double next_y = core->tmp_rc->pl_y + core->tmp_rc->pldelt_y * move_dist;

    double margin_x = 1.5;
    if (core->tmp_rc->pldelt_x < 0)
        margin_x = -margin_x;

    double margin_y = 1.5;
    if (core->tmp_rc->pldelt_y < 0)
        margin_y = -margin_y;
    
    int map_x = (int)((next_x + margin_x) / 8);
    int map_y = (int)(core->tmp_rc->pl_y / 8);
    if (core->map[map_y][map_x] != '1')
        core->tmp_rc->pl_x = next_x;

    map_x = (int)(core->tmp_rc->pl_x / 8);
    map_y = (int)((next_y + margin_y) / 8);
    if (core->map[map_y][map_x] != '1')
        core->tmp_rc->pl_y = next_y;
}

static void    handle_left(t_core *core, double move_dist)
{
    core->tmp_rc->pl_angle -= 0.05 * move_dist;
    if (core->tmp_rc->pl_angle < 0)
        core->tmp_rc->pl_angle += 2 * PI;
    core->tmp_rc->pldelt_x = cos(core->tmp_rc->pl_angle);
    core->tmp_rc->pldelt_y = sin(core->tmp_rc->pl_angle);
}

static void handle_right(t_core *core, double move_dist)
{
    core->tmp_rc->pl_angle += 0.05 * move_dist;
    if (core->tmp_rc->pl_angle > 2 * PI)
        core->tmp_rc->pl_angle -= 2 * PI;
    core->tmp_rc->pldelt_x = cos(core->tmp_rc->pl_angle);
    core->tmp_rc->pldelt_y = sin(core->tmp_rc->pl_angle);
}

void    move_player(t_core *core, t_move move, double delta_time)
{
    double move_dist = core->player->speed * delta_time;

    core->tmp_rc->of_x = 0;
    core->tmp_rc->of_y = 0;
    if (core->tmp_rc->pldelt_x < 0)
        core->tmp_rc->of_x = -move_dist;
    else
        core->tmp_rc->of_x = move_dist;
    if (core->tmp_rc->pldelt_y < 0)
        core->tmp_rc->of_y = -move_dist;
    else
        core->tmp_rc->of_y = move_dist;
    core->tmp_rc->px2 = (int)(core->tmp_rc->pl_x / 8);
    core->tmp_rc->py2 = (int)(core->tmp_rc->pl_y / 8);
    core->tmp_rc->px2_add = (int)(core->tmp_rc->pl_x + core->tmp_rc->of_x) / 8;
    core->tmp_rc->py2_add = (int)(core->tmp_rc->pl_y + core->tmp_rc->of_y) / 8;
    core->tmp_rc->px2_sub = (int)(core->tmp_rc->pl_x - core->tmp_rc->of_x) / 8;
    core->tmp_rc->py2_sub = (int)(core->tmp_rc->pl_y - core->tmp_rc->of_y) / 8;
    if (move == UP)
        handle_up(core, move_dist);
    else if (move == DOWN)
        handle_down(core, move_dist);
    else if (move == LEFT)
        handle_left(core, move_dist);
    else if (move == RIGHT)
        handle_right(core, move_dist);
    core->redraw = true;
}
