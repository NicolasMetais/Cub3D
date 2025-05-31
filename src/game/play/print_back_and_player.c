/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_layers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:48:11 by tvacher           #+#    #+#             */
/*   Updated: 2025/05/25 13:48:41 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_rays(t_core *core, int color)
{
	int	i;
	int	px_index;

	if (core->tmp_rc->r == core->tmp_rc->max_r / 2)
	{
		i = 0;
		color = 0xFF0000;
	}
	else
		i = (int)core->tmp_rc->dist3[core->tmp_rc->r] - 2;
	while (i < (int)core->tmp_rc->dist3[core->tmp_rc->r] + 2)
	{
		core->tmp_rc->px = core->tmp_rc->map_size / 2 + cos(core->tmp_rc->ra) * i;
		core->tmp_rc->py = core->tmp_rc->map_size / 2 + sin(core->tmp_rc->ra) * i;
		if (core->tmp_rc->px >= 0 && core->tmp_rc->py >= 0 && core->tmp_rc->px < 32 * 8 - 8)
		{
			px_index = core->tmp_rc->py * core->tmp_imgdata->size + core->tmp_rc->px * (core->tmp_imgdata->bpp / 8);
			core->tmp_imgdata->img_data[px_index + 0] = (color >> 0) & 0xFF;
			core->tmp_imgdata->img_data[px_index + 1] = (color >> 8) & 0xFF;
			core->tmp_imgdata->img_data[px_index + 2] = (color >> 16) & 0xFF;
			if (core->tmp_imgdata->bpp == 4)
				core->tmp_imgdata->img_data[px_index + 0] = 0xFF;
		}
		i++;
	}
}

void	draw_player_line(t_core *core, int color)
{
	int	i;
	int	px;
	int	py;
	int	px_index;

	i = 0;
	while (i < 8)
	{
		px = core->tmp_rc->map_size / 2 + cos(core->tmp_rc->pl_angle) * i;
		py = core->tmp_rc->map_size / 2 + sin(core->tmp_rc->pl_angle) * i;
		if (px >= 0 && py >= 0)
		{
			px_index = py * core->tmp_imgdata->size + px * (core->tmp_imgdata->bpp / 8);
			core->tmp_imgdata->img_data[px_index + 0] = (color >> 0) & 0xFF;
			core->tmp_imgdata->img_data[px_index + 1] = (color >> 8) & 0xFF;
			core->tmp_imgdata->img_data[px_index + 2] = (color >> 16) & 0xFF;
			if (core->tmp_imgdata->bpp == 4)
				core->tmp_imgdata->img_data[px_index + 0] = 0xFF;
		}
		i++;
	}
}

void	print_player(t_core *core, int color)
{
	int	x;
	int	y;
	int	px_index;

	y = core->tmp_rc->map_size / 2;
	while (y < core->tmp_rc->map_size / 2 + 4)
	{
		x = core->tmp_rc->map_size / 2;
		while (x < core->tmp_rc->map_size / 2 + 4)
		{
			px_index = y * core->tmp_imgdata->size + x * (core->tmp_imgdata->bpp / 8);
			core->tmp_imgdata->img_data[px_index + 0] = (color >> 0) & 0xFF;
			core->tmp_imgdata->img_data[px_index + 1] = (color >> 8) & 0xFF;
			core->tmp_imgdata->img_data[px_index + 2] = (color >> 16) & 0xFF;
			if (core->tmp_imgdata->bpp == 4)
				core->tmp_imgdata->img_data[px_index + 0] = 0xFF;
			x++;
		}
		y++;
	}
	draw_player_line(core, color);
}

//check color parsing for ceiling and floor
static void print_floor(t_core *core, int pixel_index)
{
	// core->tmp_imgdata->img_data[pixel_index + 0] = (core->colors->floor >> 0) & 0xFF;
	// core->tmp_imgdata->img_data[pixel_index + 1] = (core->colors->floor >> 8) & 0xFF;
	// core->tmp_imgdata->img_data[pixel_index + 2] = (core->colors->floor >> 16) & 0xFF;
	core->tmp_imgdata->img_data[pixel_index + 0] = 0xAA;
	core->tmp_imgdata->img_data[pixel_index + 1] = 0xAA;
	core->tmp_imgdata->img_data[pixel_index + 2] = 0xAA;
}

static void print_ceiling(t_core *core, int pixel_index, int i, int j)
{
	int	tex_index;
	int	offset;

	offset = (int)((core->tmp_rc->pl_angle) * S_LENGHT) / 16;
	tex_index = (j * core->textures->sky->line_len +  (offset + i) * (core->textures->sky->bpp / 8));
	core->tmp_imgdata->img_data[pixel_index + 0] = core->textures->sky->addr[(int)tex_index + 0];
	core->tmp_imgdata->img_data[pixel_index + 1] = core->textures->sky->addr[(int)tex_index + 1];
	core->tmp_imgdata->img_data[pixel_index + 2] = core->textures->sky->addr[(int)tex_index + 2];
	// core->tmp_imgdata->img_data[pixel_index + 0] = 0x00;
	// core->tmp_imgdata->img_data[pixel_index + 1] = 0x00;
	// core->tmp_imgdata->img_data[pixel_index + 2] = 0xFF;
}

void	print_background(t_core *core)
{
	int	i;
	int	j;
	int	pixel_index;

	j = 0;
	while (j < S_HEIGHT)
	{
		i = 0;
		while (i < S_LENGHT)
		{
			if (i > core->tmp_rc->map_size + 8 || j > core->tmp_rc->map_size + 8)
			{
				pixel_index = j * core->tmp_imgdata->size + i * (core->tmp_imgdata->bpp / 8);
				if (j > S_HEIGHT / 2)
					print_floor(core, pixel_index);
				else
					print_ceiling(core, pixel_index, i, j);
				if (core->tmp_imgdata->bpp == 4)
					core->tmp_imgdata->img_data[pixel_index + 0] = 0xFF;
			}
			i++;
		}
		j++;
	}
}
