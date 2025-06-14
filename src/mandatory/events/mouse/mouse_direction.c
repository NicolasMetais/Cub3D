/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:34:06 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/13 01:13:47 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_scroll_game(t_core *core, int x, int y)
{
	int	offset;

	mlx_mouse_get_pos(core->mlx, core->win, &x, &y);
	if (x > 0 && x < core->scroll_ingame)
		offset = -1;
	else if (x > core->scroll_ingame && x < S_LENGHT)
		offset = 1;
	else
		offset = 0;
	if (x < 100)
		mlx_mouse_move(core->mlx, core->win, S_LENGHT -100, S_HEIGHT / 2);
	if (x > S_LENGHT - 100)
		mlx_mouse_move(core->mlx, core->win, 100, S_HEIGHT / 2);
	core->rc->pl_angle += 0.03 * offset;
	if (core->rc->pl_angle > 2 * PI)
		core->rc->pl_angle -= 2 * PI;
	core->rc->pldelt_x = cos(core->rc->pl_angle);
	core->rc->pldelt_y = sin(core->rc->pl_angle);
	core->scroll_ingame = x;
}

int	mouse_direction(int x, int y, void *param)
{
	t_core		*core;

	core = (t_core *)param;
	mlx_mouse_hide(core->mlx, core->win);
	mouse_scroll_game(core, x, y);
	return (0);
}
