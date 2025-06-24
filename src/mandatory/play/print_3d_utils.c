/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3d_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:13:43 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/23 22:54:37 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_wall(t_core *core, t_img *wall)
{
	core->rc3d->tex_index = (int)core->rc3d->ty * \
	wall->line_len + (int)core->rc3d->tx * \
	(wall->bpp / 8);
	core->game_img->addr[core->rc3d->pixel_index + 0] = \
	wall->addr[(int)core->rc3d->tex_index + 0];
	core->game_img->addr[core->rc3d->pixel_index + 1] = \
	wall->addr[(int)core->rc3d->tex_index + 1];
	core->game_img->addr[core->rc3d->pixel_index + 2] = \
	wall->addr[(int)core->rc3d->tex_index + 2];
}

void	print_3d_vertical(t_core *core)
{
	if (core->rc->hit_wall == '1')
	{
		if (core->rc->ra > PI)
		{
			print_wall(core, core->textures->img_north);
		}
		else
		{
			print_wall(core, core->textures->img_south);
		}
	}
}

void	print_3d_horizontal(t_core *core)
{
	if (core->rc->hit_wall == '1')
	{
		if (core->rc->ra > PI / 2 && core->rc->ra < 3 * PI / 2)
		{
			print_wall(core, core->textures->img_west);
		}
		else
		{
			print_wall(core, core->textures->img_east);
		}
	}
}
