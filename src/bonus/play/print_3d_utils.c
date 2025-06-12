/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3d_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:13:43 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/07 18:13:53 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_doors(t_core *core)
{
	core->tmp_3d->tex_index = (int)core->tmp_3d->ty * \
	core->textures->door->line_len + (int)core->tmp_3d->tx * \
	(core->textures->door->bpp / 8);
	core->game_img->addr[core->tmp_3d->pixel_index + 0] = \
	core->textures->door->addr[(int)core->tmp_3d->tex_index + 0];
	core->game_img->addr[core->tmp_3d->pixel_index + 1] = \
	core->textures->door->addr[(int)core->tmp_3d->tex_index + 1];
	core->game_img->addr[core->tmp_3d->pixel_index + 2] = \
	core->textures->door->addr[(int)core->tmp_3d->tex_index + 2];
}

void	print_3d_vertical(t_core *core)
{
	if (core->tmp_rc->hit_wall == '1')
	{
		if (core->tmp_rc->ra > PI)
		{
			core->tmp_3d->tex_index = (int)core->tmp_3d->ty * \
			core->textures->tmp_east->line_len + (int)core->tmp_3d->tx * \
			(core->textures->tmp_east->bpp / 8);
			core->game_img->addr[core->tmp_3d->pixel_index + 0] = \
			core->textures->tmp_east->addr[(int)core->tmp_3d->tex_index + 0];
			core->game_img->addr[core->tmp_3d->pixel_index + 1] = \
			core->textures->tmp_east->addr[(int)core->tmp_3d->tex_index + 1];
			core->game_img->addr[core->tmp_3d->pixel_index + 2] = \
			core->textures->tmp_east->addr[(int)core->tmp_3d->tex_index + 2];
		}
		else
		{
			core->tmp_3d->tex_index = (int)core->tmp_3d->ty * \
			core->textures->tmp_north->line_len + (int)core->tmp_3d->tx * \
			(core->textures->tmp_north->bpp / 8);
			core->game_img->addr[core->tmp_3d->pixel_index + 0] = \
			core->textures->tmp_north->addr[(int)core->tmp_3d->tex_index + 0];
			core->game_img->addr[core->tmp_3d->pixel_index + 1] = \
			core->textures->tmp_north->addr[(int)core->tmp_3d->tex_index + 1];
			core->game_img->addr[core->tmp_3d->pixel_index + 2] = \
			core->textures->tmp_north->addr[(int)core->tmp_3d->tex_index + 2];
		}
	}
	else if (core->tmp_rc->hit_wall == '2')
		print_doors(core);
	if (core->tmp_rc->open_door == 1)
		anim_door(core);
}

void	print_3d_horizontal(t_core *core)
{
	if (core->tmp_rc->hit_wall == '1')
	{
		if (core->tmp_rc->ra > PI / 2 && core->tmp_rc->ra < 3 * PI / 2)
		{
			core->tmp_3d->tex_index = (int)core->tmp_3d->ty * \
			core->textures->tmp_west->line_len + (int)core->tmp_3d->tx * \
			(core->textures->tmp_west->bpp / 8);
			core->game_img->addr[core->tmp_3d->pixel_index + 0] = \
			core->textures->tmp_west->addr[(int)core->tmp_3d->tex_index + 0];
			core->game_img->addr[core->tmp_3d->pixel_index + 1] = \
			core->textures->tmp_west->addr[(int)core->tmp_3d->tex_index + 1];
			core->game_img->addr[core->tmp_3d->pixel_index + 2] = \
			core->textures->tmp_west->addr[(int)core->tmp_3d->tex_index + 2];
		}
		else
		{
			core->tmp_3d->tex_index = (int)core->tmp_3d->ty * \
			core->textures->tmp_south->line_len + (int)core->tmp_3d->tx * \
			(core->textures->tmp_south->bpp / 8);
			core->game_img->addr[core->tmp_3d->pixel_index + 0] = \
			core->textures->tmp_south->addr[(int)core->tmp_3d->tex_index + 0];
			core->game_img->addr[core->tmp_3d->pixel_index + 1] = \
			core->textures->tmp_south->addr[(int)core->tmp_3d->tex_index + 1];
			core->game_img->addr[core->tmp_3d->pixel_index + 2] = \
			core->textures->tmp_south->addr[(int)core->tmp_3d->tex_index + 2];
		}
	}
	else if (core->tmp_rc->hit_wall == '2')
		print_doors(core);
	if (core->tmp_rc->open_door == 1)
		anim_door(core);
}
