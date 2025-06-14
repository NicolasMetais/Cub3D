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

void	print_open_doors(t_core *core)
{

	core->rc3d->tex_index = (int)core->rc3d->ty * \
	core->textures->open_doors->line_len + (int)core->rc3d->tx * \
	(core->textures->open_doors->bpp / 8);
	core->game_img->addr[core->rc3d->pixel_index + 0] = \
	core->textures->open_doors->addr[(int)core->rc3d->tex_index + 0];
	core->game_img->addr[core->rc3d->pixel_index + 1] = \
	core->textures->open_doors->addr[(int)core->rc3d->tex_index + 1];
	core->game_img->addr[core->rc3d->pixel_index + 2] = \
	core->textures->open_doors->addr[(int)core->rc3d->tex_index + 2];
}

void	print_doors(t_core *core)
{

	core->rc3d->tex_index = (int)core->rc3d->ty * \
	core->textures->door->line_len + (int)core->rc3d->tx * \
	(core->textures->door->bpp / 8);
	core->game_img->addr[core->rc3d->pixel_index + 0] = \
	core->textures->door->addr[(int)core->rc3d->tex_index + 0];
	core->game_img->addr[core->rc3d->pixel_index + 1] = \
	core->textures->door->addr[(int)core->rc3d->tex_index + 1];
	core->game_img->addr[core->rc3d->pixel_index + 2] = \
	core->textures->door->addr[(int)core->rc3d->tex_index + 2];
}

void	print_3d_vertical(t_core *core)
{
	if (core->rc->hit_wall == '1' || core->rc->hit_wall == '4' || core->rc->hit_wall == '5' || core->rc->hit_wall == '6' || core->rc->hit_wall == '7')
	{
		if (core->rc->ra > PI)
		{
			if (core->rc->hit_wall == '4')
				print_open_doors(core);
			else
			{
				core->rc3d->tex_index = (int)core->rc3d->ty * \
				core->textures->tmp_east->line_len + (int)core->rc3d->tx * \
				(core->textures->tmp_east->bpp / 8);
				core->game_img->addr[core->rc3d->pixel_index + 0] = \
				core->textures->tmp_east->addr[(int)core->rc3d->tex_index + 0];
				core->game_img->addr[core->rc3d->pixel_index + 1] = \
				core->textures->tmp_east->addr[(int)core->rc3d->tex_index + 1];
				core->game_img->addr[core->rc3d->pixel_index + 2] = \
				core->textures->tmp_east->addr[(int)core->rc3d->tex_index + 2];
			}
		}
		else
		{
			if (core->rc->hit_wall == '5')
				print_open_doors(core);
			else
			{
				core->rc3d->tex_index = (int)core->rc3d->ty * \
				core->textures->tmp_north->line_len + (int)core->rc3d->tx * \
				(core->textures->tmp_north->bpp / 8);
				core->game_img->addr[core->rc3d->pixel_index + 0] = \
				core->textures->tmp_north->addr[(int)core->rc3d->tex_index + 0];
				core->game_img->addr[core->rc3d->pixel_index + 1] = \
				core->textures->tmp_north->addr[(int)core->rc3d->tex_index + 1];
				core->game_img->addr[core->rc3d->pixel_index + 2] = \
				core->textures->tmp_north->addr[(int)core->rc3d->tex_index + 2];
			}
		}
	}
	else if (core->rc->hit_wall == '2')
		print_doors(core);
}

void	print_3d_horizontal(t_core *core)
{
	if (core->rc->hit_wall == '1' || core->rc->hit_wall == '4' || core->rc->hit_wall == '5' || core->rc->hit_wall == '6' || core->rc->hit_wall == '7')
	{
		if (core->rc->ra > PI / 2 && core->rc->ra < 3 * PI / 2)
		{
			if (core->rc->hit_wall == '7')
				print_open_doors(core);
			else
			{
				core->rc3d->tex_index = (int)core->rc3d->ty * \
				core->textures->tmp_west->line_len + (int)core->rc3d->tx * \
				(core->textures->tmp_west->bpp / 8);
				core->game_img->addr[core->rc3d->pixel_index + 0] = \
				core->textures->tmp_west->addr[(int)core->rc3d->tex_index + 0];
				core->game_img->addr[core->rc3d->pixel_index + 1] = \
				core->textures->tmp_west->addr[(int)core->rc3d->tex_index + 1];
				core->game_img->addr[core->rc3d->pixel_index + 2] = \
				core->textures->tmp_west->addr[(int)core->rc3d->tex_index + 2];
			}
		}
		else
		{
			if (core->rc->hit_wall == '6')
				print_open_doors(core);
			else
			{
				core->rc3d->tex_index = (int)core->rc3d->ty * \
				core->textures->tmp_south->line_len + (int)core->rc3d->tx * \
				(core->textures->tmp_south->bpp / 8);
				core->game_img->addr[core->rc3d->pixel_index + 0] = \
				core->textures->tmp_south->addr[(int)core->rc3d->tex_index + 0];
				core->game_img->addr[core->rc3d->pixel_index + 1] = \
				core->textures->tmp_south->addr[(int)core->rc3d->tex_index + 1];
				core->game_img->addr[core->rc3d->pixel_index + 2] = \
				core->textures->tmp_south->addr[(int)core->rc3d->tex_index + 2];
			}
		}
	}
	else if (core->rc->hit_wall == '2')
		print_doors(core);
}
