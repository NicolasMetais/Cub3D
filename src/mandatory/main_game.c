/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:44:46 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/13 02:24:58 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//GAME LAUNCH
bool	launch_game(t_core *core)
{
	if (core->map_height > core->map_width)
		core->rc->map_size = core->map_height * 8;
	else
		core->rc->map_size = core->map_width * 8;
	if (!game_init(core))
		return (1);
	core->state = GAME;
	core->fov = 60;
	mlx_hook(core->win, 2, 1L << 0, &handle_keypress, core);
	mlx_hook(core->win, 3, 1L << 1, &handle_keyrelease, core);
	mlx_hook(core->win, 17, 1L << 17, &cross_handler, core);
	//mlx_hook(core->win, 6, (1L << 6), &mouse_direction, core);
	mlx_loop_hook(core->mlx, &routine, core);
	mlx_loop(core->mlx);
	return (true);
}
