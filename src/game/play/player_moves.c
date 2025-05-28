/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:40:42 by tvacher           #+#    #+#             */
/*   Updated: 2025/05/25 15:40:55 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void handle_down(t_core *core)
{
    if (core->map[core->tmp_rc->py2][core->tmp_rc->px2_sub] != '1')
        core->tmp_rc->pl_x -= core->tmp_rc->pldelt_x * 0.2;
    if (core->map[core->tmp_rc->py2_sub][core->tmp_rc->px2] != '1')
        core->tmp_rc->pl_y -= core->tmp_rc->pldelt_y * 0.2;
    // core->tmp_rc->pl_y += core->tmp_rc->pldelt_y;
    // core->tmp_rc->pl_x += core->tmp_rc->pldelt_x;
}

static void handle_up(t_core *core)
{
    if (core->map[core->tmp_rc->py2][core->tmp_rc->px2_add] != '1')
        core->tmp_rc->pl_x += core->tmp_rc->pldelt_x * 0.5;
    if (core->map[core->tmp_rc->py2_add][core->tmp_rc->px2] != '1')
        core->tmp_rc->pl_y += core->tmp_rc->pldelt_y * 0.5;
    // core->tmp_rc->pl_y += core->tmp_rc->pldelt_y;
    // core->tmp_rc->pl_x += core->tmp_rc->pldelt_x;
}

static void    handle_left(t_core *core)
{
    core->tmp_rc->pl_angle -= 0.05;
    if (core->tmp_rc->pl_angle < 0)
        core->tmp_rc->pl_angle += 2 * PI;
    core->tmp_rc->pldelt_x = cos(core->tmp_rc->pl_angle) * 5;
    core->tmp_rc->pldelt_y = sin(core->tmp_rc->pl_angle) * 5;
}

static void handle_right(t_core *core)
{
    core->tmp_rc->pl_angle += 0.05;
    if (core->tmp_rc->pl_angle > 2 * PI)
        core->tmp_rc->pl_angle -= 2 * PI;
    core->tmp_rc->pldelt_x = cos(core->tmp_rc->pl_angle) * 5;
    core->tmp_rc->pldelt_y = sin(core->tmp_rc->pl_angle) * 5;
}

void    move_player(t_core *core, t_move move)
{
    core->tmp_rc->of_x = 0;
    core->tmp_rc->of_y = 0;
    if (core->tmp_rc->pldelt_x < 0)
        core->tmp_rc->of_x = -5;
    else
        core->tmp_rc->of_x = 5;
    if (core->tmp_rc->pldelt_y < 0)
        core->tmp_rc->of_y = -5;
    else
        core->tmp_rc->of_y = 5;
    core->tmp_rc->px2 = core->tmp_rc->pl_x / 8;
    core->tmp_rc->py2 = core->tmp_rc->pl_y / 8;
    core->tmp_rc->px2_add = (core->tmp_rc->pl_x + core->tmp_rc->of_x) / 8;
    core->tmp_rc->py2_add = (core->tmp_rc->pl_y + core->tmp_rc->of_y) / 8;
    core->tmp_rc->px2_sub = (core->tmp_rc->pl_x - core->tmp_rc->of_x) / 8;
    core->tmp_rc->py2_sub = (core->tmp_rc->pl_y - core->tmp_rc->of_y) / 8;
    if (move == UP)
        handle_up(core);
    else if (move == DOWN)
    {
        handle_down(core);
    }
    else if (move == LEFT)
        handle_left(core);
    else if (move == RIGHT)
        handle_right(core);
    core->redraw = true;
}
