/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:44:46 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/27 16:58:20 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	launch_game(t_core *core)
{
	//init_tmp(core);
	core->redraw = true;
	get_rc_data(core);
	mlx_hook(core->win, 2, 1L << 0, &handle_keypress, core);
	//mlx_key_hook(core->win, handle_keypress, core);
	mlx_loop_hook(core->mlx, &routine, core);
	mlx_loop(core->mlx);
	return (true);
}
