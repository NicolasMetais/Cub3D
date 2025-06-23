/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:44:46 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/23 21:27:53 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_player_start(t_core *core)
{
	int	x;
	int	y;

	y = (int)core->spawn->x;
	x = (int)core->spawn->y;
	if (core->map[x][y] == 'N')
		return (3 * PI / 2);
	else if (core->map[x][y] == 'E')
		return (2 * PI);
	else if (core->map[x][y] == 'W')
		return (PI);
	else
		return (PI / 2);
}

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
	mlx_loop_hook(core->mlx, &routine, core);
	mlx_loop(core->mlx);
	return (true);
}
