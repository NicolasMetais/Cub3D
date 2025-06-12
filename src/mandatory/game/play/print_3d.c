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
	core->tmp_3d->pixel_index = core->tmp_3d->y * core->game_img->line_len + \
	core->tmp_3d->x * (core->game_img->bpp / 8);
	if (core->tmp_3d->y >= core->tmp_3d->line_s && core->tmp_3d->y <= \
	core->tmp_3d->line_e && core->tmp_rc->dist2[core->tmp_rc->r] > \
	core->tmp_rc->dist[core->tmp_rc->r] && (core->tmp_3d->y > \
	core->tmp_3d->draw_start && core->tmp_3d->y < core->tmp_3d->draw_end))
		print_3d_vertical(core);
	else if (core->tmp_3d->y >= core->tmp_3d->line_s && core->tmp_3d->y <= \
	core->tmp_3d->line_e && core->tmp_rc->dist[core->tmp_rc->r] > \
	core->tmp_rc->dist2[core->tmp_rc->r] && (core->tmp_3d->y > \
	core->tmp_3d->draw_start && core->tmp_3d->y < core->tmp_3d->draw_end))
		print_3d_horizontal(core);
}

void	get_draw_loop_data(t_core *core)
{
	core->tmp_3d->ty = (int)core->tmp_3d->tex_pos & \
	(core->textures->tmp_east->height - 1);
	core->tmp_3d->tex_pos += core->tmp_3d->step;
	if (core->tmp_3d->end > S_LENGHT)
		core->tmp_3d->end = S_LENGHT;
	core->tmp_3d->x = core->tmp_3d->start;
	if ((int)core->tmp_3d->ty >= core->textures->tmp_east->height)
		core->tmp_3d->ty = core->textures->tmp_east->height - 1;
}

void	get_draw_start_data(t_core *core)
{
	core->tmp_3d->start = (int)(core->tmp_rc->r * 1);
	core->tmp_3d->end = (int)((core->tmp_rc->r + 1) * 1);
	core->tmp_3d->tx = (int)(core->tmp_3d->offset / 8.0f * \
	core->textures->tmp_east->width);
	if (core->tmp_3d->tx < 0)
		core->tmp_3d->tx = 0;
	if (core->tmp_3d->tx >= core->textures->tmp_east->width)
		core->tmp_3d->tx = core->textures->tmp_east->width - 1;
	core->tmp_3d->draw_start = -core->tmp_3d->line_h / 2 + S_HEIGHT / 2;
	if (core->tmp_3d->draw_start < 0)
		core->tmp_3d->draw_start = 0;
	core->tmp_3d->draw_end = core->tmp_3d->line_h / 2 + S_HEIGHT / 2;
	if (core->tmp_3d->draw_end >= S_HEIGHT)
		core->tmp_3d->draw_end = S_HEIGHT - 1;
	core->tmp_3d->tex_pos = (core->tmp_3d->draw_start - S_HEIGHT / 2 + \
	core->tmp_3d->line_h / 2) * core->tmp_3d->step;
	core->tmp_3d->y = core->tmp_3d->draw_start;
}

void	get_3d_based_data(t_core *core)
{
	core->tmp_3d->ty_off = 0;
	core->tmp_3d->line_h = (8 * S_HEIGHT) / \
	core->tmp_rc->dist3[core->tmp_rc->r];
	core->tmp_3d->step = (float)core->textures->tmp_east->height / \
	(float)core->tmp_3d->line_h;
	core->tmp_3d->line_s = (S_HEIGHT - core->tmp_3d->line_h) / 2;
	core->tmp_3d->line_e = core->tmp_3d->line_s + core->tmp_3d->line_h;
	if (core->tmp_3d->line_h > S_HEIGHT)
	{
		core->tmp_3d->ty_off = (core->tmp_3d->line_h - S_HEIGHT) / 2;
		core->tmp_3d->line_e = S_HEIGHT;
	}
	core->tmp_3d->y = 0;
	core->tmp_3d->tx = 0;
	if (core->tmp_rc->was_vertical)
		core->tmp_3d->offset = fmodf(core->tmp_rc->ry, 8);
	else
		core->tmp_3d->offset = fmodf(core->tmp_rc->rx, 8);
	core->tmp_3d->offset = fmodf(core->tmp_3d->offset, 8.0f);
	if (core->tmp_3d->offset < 0)
		core->tmp_3d->offset += 8.0f;
}
