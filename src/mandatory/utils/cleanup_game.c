/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 02:08:56 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/17 20:55:12 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup_game(t_core *core)
{
	mlx_destroy_image(core->mlx, core->textures->sky->img);
	mlx_destroy_image(core->mlx, core->textures->img_north->img);
	mlx_destroy_image(core->mlx, core->textures->img_south->img);
	mlx_destroy_image(core->mlx, core->textures->img_east->img);
	mlx_destroy_image(core->mlx, core->textures->img_west->img);
	mlx_destroy_image(core->mlx, core->game_img->img);
	if (core->mlx && core->win)
		mlx_destroy_window(core->mlx, core->win);
	if (core->mlx)
		mlx_destroy_display(core->mlx);
	free_gc(core->gc, NULL);
	exit(0);
}
