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

static void handle_up(t_core *core)
{
    // if (core->tmp_rc->pldelt_x < 0)
    //     core->tmp_rc->of_x = -20;
    // else
    //     core->tmp_rc->of_x = 20;
    // if (core->tmp_rc->pldelt_y < 0)
    //     core->tmp_rc->of_y = -20;
    // else
    //     core->tmp_rc->of_y = 20;
    // core->tmp_rc->px2 = core->tmp_rc->pl_x / 32;
    // core->tmp_rc->py2 = core->tmp_rc->pl_y / 32;
    // core->tmp_rc->px2_add = (core->tmp_rc->pl_x + core->tmp_rc->of_x) / 32;
    // core->tmp_rc->py2_add = (core->tmp_rc->pl_y + core->tmp_rc->of_y) / 32;
    // core->tmp_rc->px2_sub = (core->tmp_rc->pl_x - core->tmp_rc->of_x) / 32;
    // core->tmp_rc->py2_sub = (core->tmp_rc->pl_y - core->tmp_rc->of_y) / 32;
    // if (map[core->tmp_rc->py2 * core->tmp_rc->])
    core->tmp_rc->pl_y += core->tmp_rc->pldelt_y;
    core->tmp_rc->pl_x += core->tmp_rc->pldelt_x;
}

void    move_player(t_core *core, t_move move)
{
    if (move == UP)
        handle_up(core);
    else if (move == DOWN)
    {
        core->tmp_rc->pl_y -= core->tmp_rc->pldelt_y;
        core->tmp_rc->pl_x -= core->tmp_rc->pldelt_x;
    }
    else if (move == LEFT)
        handle_left(core);
    else if (move == RIGHT)
        handle_right(core);
    core->redraw = true;
}
