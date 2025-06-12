/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:48:11 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/12 23:49:58 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//check color parsing for ceiling and floor
static void	print_floor(t_core *core, int pixel_index)
{
	if (core->colors->ceiling)
		printf("%d\n", 100);
	// core->game_img->addr[pixel_index + 0] = core->colors->floor->data[0];
	// core->game_img->addr[pixel_index + 1] = core->colors->floor->data[1];
	// core->game_img->addr[pixel_index + 2] = core->colors->floor->data[2];
	core->game_img->addr[pixel_index + 0] = 0xAA;
	core->game_img->addr[pixel_index + 1] = 0xAA;
	core->game_img->addr[pixel_index + 2] = 0xAA;
}

static void	print_ceiling(t_core *core, int pixel_index, int i, int j)
{
	int	tex_index;
	int	offset;

	offset = (int)((core->tmp_rc->pl_angle) * S_LENGHT) / 16;
	tex_index = (j * core->textures->sky->line_len + (offset + i) * \
	(core->textures->sky->bpp / 8));
	core->game_img->addr[pixel_index + 0] = \
	core->textures->sky->addr[(int)tex_index + 0];
	core->game_img->addr[pixel_index + 1] = \
	core->textures->sky->addr[(int)tex_index + 1];
	core->game_img->addr[pixel_index + 2] = \
	core->textures->sky->addr[(int)tex_index + 2];
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
				print_ceiling(core, pixel_index, i, j);
			if (core->game_img->bpp == 4)
				core->game_img->addr[pixel_index + 0] = 0xFF;
		}
		j++;
	}
}
