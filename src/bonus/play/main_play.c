/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:33:49 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/21 20:07:39 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_player_start(t_core *core)
{
	int	x;
	int	y;

	y = (int)core->spawn->x;
	x = (int)core->spawn->y;
	if (core->map[x][y] == 'N')
		return (3 * PI / 2);
	else if (core->map[x][y] == 'E')
		return (2 * PI);
	else if (core->map[x][y] == 'W')
		return (PI);
	else
		return (PI / 2);
}

static void	renderings(t_core *core)
{
	print_background(core);
	draw_minimap_game(core);
	get_raycast_data(core);
	render_foes(core);
	impacts(core);
	render_projectiles(core);
	print_player(core, 0xFFFF00);
}

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
	renderings(core);
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
	render_notifs(core);
	if (core->player->health <= 0)
		core->state = GAME_OVER;
	return (true);
}
