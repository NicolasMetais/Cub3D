/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 02:08:56 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/24 19:03:47 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_ult(char **str)
{
	int	i;

	if (!str || !str[0])
		return ;
	i = 0;
	while (str[i])
		i++;
	while (i-- > 0)
		free(str[i]);
	free(str);
	str = NULL;
}

void	cleanup_game(t_core *core)
{
	if (core->textures)
	{
		if (core->textures->img_north && core->textures->img_north->img)
			mlx_destroy_image(core->mlx, core->textures->img_north->img);
		if (core->textures->img_south && core->textures->img_south->img)
			mlx_destroy_image(core->mlx, core->textures->img_south->img);
		if (core->textures->img_east && core->textures->img_east->img)
			mlx_destroy_image(core->mlx, core->textures->img_east->img);
		if (core->textures->img_west && core->textures->img_west->img)
			mlx_destroy_image(core->mlx, core->textures->img_west->img);
		free_ult(core->textures->floor_colors);
		free_ult(core->textures->ceiling_colors);
	}
	if (core->game_img)
		mlx_destroy_image(core->mlx, core->game_img->img);
	if (core->mlx && core->win)
		mlx_destroy_window(core->mlx, core->win);
	if (core->mlx)
		mlx_destroy_display(core->mlx);
	free_gc(core->gc, NULL);
	exit(0);
}
