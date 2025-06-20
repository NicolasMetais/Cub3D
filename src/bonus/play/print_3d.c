/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:13:16 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/07 18:13:29 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_3d_render(t_core *core)
{
	core->rc3d->pixel_index = core->rc3d->y * core->game_img->line_len + \
	core->rc3d->x * (core->game_img->bpp / 8);
	if (core->rc3d->y >= core->rc3d->line_s && core->rc3d->y <= \
	core->rc3d->line_e && core->rc->dist2[core->rc->r] > \
	core->rc->dist[core->rc->r] && (core->rc3d->y > \
	core->rc3d->draw_start && core->rc3d->y < core->rc3d->draw_end))
		print_3d_vertical(core);
	else if (core->rc3d->y >= core->rc3d->line_s && core->rc3d->y <= \
	core->rc3d->line_e && core->rc->dist[core->rc->r] > \
	core->rc->dist2[core->rc->r] && (core->rc3d->y > \
	core->rc3d->draw_start && core->rc3d->y < core->rc3d->draw_end))
		print_3d_horizontal(core);
}

void	get_draw_loop_data(t_core *core)
{
	core->rc3d->ty = (int)core->rc3d->tex_pos & \
	(core->textures->img_east->height - 1);
	core->rc3d->tex_pos += core->rc3d->step;
	if (core->rc3d->end > S_LENGHT)
		core->rc3d->end = S_LENGHT;
	core->rc3d->x = core->rc3d->start;
	if ((int)core->rc3d->ty >= core->textures->img_east->height)
		core->rc3d->ty = core->textures->img_east->height - 1;
}

void	get_draw_start_data(t_core *core)
{
	core->rc3d->start = (int)(core->rc->r * 1);
	core->rc3d->end = (int)((core->rc->r + 1) * 1);
	core->rc3d->tx = (int)(core->rc3d->offset / 8.0f * \
	core->textures->img_east->width);
	if (core->rc3d->tx < 0)
		core->rc3d->tx = 0;
	if (core->rc3d->tx >= core->textures->img_east->width)
		core->rc3d->tx = core->textures->img_east->width - 1;
	core->rc3d->draw_start = -core->rc3d->line_h / 2 + S_HEIGHT / 2;
	if (core->rc3d->draw_start < 0)
		core->rc3d->draw_start = 0;
	core->rc3d->draw_end = core->rc3d->line_h / 2 + S_HEIGHT / 2;
	if (core->rc3d->draw_end >= S_HEIGHT)
		core->rc3d->draw_end = S_HEIGHT - 1;
	core->rc3d->tex_pos = (core->rc3d->draw_start - S_HEIGHT / 2 + \
	core->rc3d->line_h / 2) * core->rc3d->step;
	core->rc3d->y = core->rc3d->draw_start;
}

void	get_3d_based_data(t_core *core)
{
	core->rc3d->ty_off = 0;
	core->rc3d->line_h = (8 * S_HEIGHT) / \
	core->rc->dist3[core->rc->r];
	core->rc3d->step = (float)core->textures->img_east->height / \
	(float)core->rc3d->line_h;
	core->rc3d->line_s = (S_HEIGHT - core->rc3d->line_h) / 2;
	core->rc3d->line_e = core->rc3d->line_s + core->rc3d->line_h;
	if (core->rc3d->line_h > S_HEIGHT)
	{
		core->rc3d->ty_off = (core->rc3d->line_h - S_HEIGHT) / 2;
		core->rc3d->line_e = S_HEIGHT;
	}
	core->rc3d->y = 0;
	core->rc3d->tx = 0;
	if (core->rc->was_vertical)
		core->rc3d->offset = fmodf(core->rc->ry, 8);
	else
		core->rc3d->offset = fmodf(core->rc->rx, 8);
	core->rc3d->offset = fmodf(core->rc3d->offset, 8.0f);
	if (core->rc3d->offset < 0)
		core->rc3d->offset += 8.0f;
}
