/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:33:49 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/12 21:13:04 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_3d(t_core *core)
{
	get_3d_based_data(core);
	get_draw_start_data(core);
	while (core->rc3d->y < core->rc3d->draw_end)
	{
		get_draw_loop_data(core);
		while (core->rc3d->x < core->rc3d->end && \
		(core->rc3d->x > core->rc->map_size + 8 || \
		core->rc3d->y > core->rc->map_size + 8) && \
		core->rc3d->y < S_HEIGHT - 160)
		{
			print_3d_render(core);
			core->rc3d->x++;
		}
		core->rc3d->y++;
	}
}

bool	start_game(t_core *core)
{
	t_sprite	*sprite;
	t_weapon	*wpn;

	wpn = &core->player->weapon[core->player->curr_wpn];
	print_background(core);
	draw_minimap_game(core);
	get_raycast_data(core);
	impacts(core);
	render_projectiles(core);
	print_player(core, 0xFFFF00);
	sprite = core->player->weapon[core->player->curr_wpn].anim;
	if (core->player->weapon[core->player->curr_wpn].lock)
	{
	if (core->player->firing)
		update_loaded_animation(wpn, sprite, true, core);
	else
		update_loaded_animation(wpn, sprite, false, core);
	if (!sprite->activ)
		wpn->lock = false;
	}
	fill_img_in_green(core->weapon_buffer);
	if (!update_projectiles(core))
		return (false);
	render_weapon(core);
	mlx_put_image_to_window(core->mlx, core->win, core->game_img->img, 0, 0);
	render_hud(core);
	render_head(core);
	return (true);
}
