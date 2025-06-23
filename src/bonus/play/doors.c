/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:25:15 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/23 20:43:18 by tvacher          ###   ########.fr       */
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
