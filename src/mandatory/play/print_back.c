/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:48:11 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/23 22:36:09 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_floor(t_core *core, int pixel_index)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(core->textures->floor_colors[0]);
	g = ft_atoi(core->textures->floor_colors[1]);
	b = ft_atoi(core->textures->floor_colors[2]);
	core->game_img->addr[pixel_index + 0] = (b & 0xFF << 16);
	core->game_img->addr[pixel_index + 1] = (g & 0xFF << 8);
	core->game_img->addr[pixel_index + 2] = (r & 0xFF << 0);
}

static void	print_ceiling(t_core *core, int pixel_index)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(core->textures->ceiling_colors[0]);
	g = ft_atoi(core->textures->ceiling_colors[1]);
	b = ft_atoi(core->textures->ceiling_colors[2]);
	core->game_img->addr[pixel_index + 0] = (b & 0xFF << 16);
	core->game_img->addr[pixel_index + 1] = (g & 0xFF << 8);
	core->game_img->addr[pixel_index + 2] = (r & 0xFF << 0);
}

void	print_background(t_core *core)
{
	int	i;
	int	j;
	int	pixel_index;

	j = 0;
	while (j < S_HEIGHT)
	{
		i = -1;
		while (++i < S_LENGHT)
		{
			pixel_index = j * core->game_img->line_len + i * \
			(core->game_img->bpp / 8);
			if (j > S_HEIGHT / 2)
				print_floor(core, pixel_index);
			else
				print_ceiling(core, pixel_index);
			if (core->game_img->bpp == 4)
				core->game_img->addr[pixel_index + 0] = 0xFF;
		}
		j++;
	}
}
