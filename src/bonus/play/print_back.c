/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:48:11 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/12 23:42:38 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//check color parsing for ceiling and floor
static void	print_floor(t_core *core, int pixel_index)
{
	// core->game_img->addr[pixel_index + 0] = (char)core->textures->floor_colors[2] & 0xFF;
	// core->game_img->addr[pixel_index + 1] = (char)core->textures->floor_colors[1] & 0xFF;
	// core->game_img->addr[pixel_index + 2] = (char)core->textures->floor_colors[0] & 0xFF;
	core->game_img->addr[pixel_index + 0] = (char)0;
	core->game_img->addr[pixel_index + 1] = (char)10;
	core->game_img->addr[pixel_index + 2] = (char)50;
}

static void	print_ceiling(t_core *core, int pixel_index, int i, int j)
{
	float	ang;
	float	tex_offset;
	int		tex_x;
	int		tex_index;

	ang = fmodf(core->rc->pl_angle, 2.0f * PI);
	if (ang < 0)
		ang += 2.0f * PI;
	tex_offset = (ang / (2.0f * PI)) * (float)core->textures->sky->width;
	tex_x = ((int)(tex_offset - i) % core->textures->sky->width + \
	core->textures->sky->width) % core->textures->sky->width;
	tex_index = j * core->textures->sky->line_len + tex_x * \
	(core->textures->sky->bpp / 8);
	core->game_img->addr[pixel_index + 0] = \
	core->textures->sky->addr[tex_index + 0];
	core->game_img->addr[pixel_index + 1] = \
	core->textures->sky->addr[tex_index + 1];
	core->game_img->addr[pixel_index + 2] = \
	core->textures->sky->addr[tex_index + 2];
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
		while (++i < S_LENGHT && j < S_HEIGHT - 160)
		{
			if (i > core->rc->map_size + 8 || \
			j > core->rc->map_size + 8)
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
		}
		j++;
	}
}
