/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pause_options.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:49:55 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/15 18:15:21 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* static void	skulls_render_options(t_core *core, const int *y)
{
	int			x;
	t_sprite	*skulls;

	skulls = hashmap_get(&core->hashmap_sprites, "skulls");
	x = (core->menu_img->bg->width / 2) - 100;
	transparency(core->menu_img->bg, skulls->img_list->image,
		x - (skulls->img_list->image->width + 10),
		y[core->menu_option]);
	mlx_put_image_to_window(core->mlx, core->win, core->menu_img->bg->img,
		0, 0);
}

static void	update_slider(t_core *core, const int *y, t_img *bg)
{
	transparency(bg, core->menu_img->slider_bar, (bg->width / 2) - 70, y[0]);
	transparency(bg, core->menu_img->slider_bar, (bg->width / 2) - 70, y[0]);
	transparency(bg, core->menu_img->cursor, core->x, y[0] + 5);
} */

static void	on_off_sliders(t_core *core, const int *y, t_img *bg)
{
	t_img		*on;
	t_img		*off;

	on = (t_img *)hashmap_get(&core->hashmap, "Option_on");
	if (!on)
		return ;
	off = (t_img *)hashmap_get(&core->hashmap, "Option_off");
	if (!off)
		return ;
	if (core->cursor[3] == 1255)
		transparency(bg, off, 1230, y[3] - 60);
	else
		transparency(bg, on, 1230, y[3] - 60);
	if (core->cursor[4] == 1255)
		transparency(bg, off, 1230, y[4] - 60);
	else
		transparency(bg, on, 1230, y[4] - 60);
}

static void	rewrite_cheats(t_core *core, const int *y, t_img *bg)
{
	t_img		*godmod;
	t_img		*infinite;
	t_img		*ammos;

	godmod = (t_img *)hashmap_get(&core->hashmap, "Option_godmod");
	if (!godmod)
		return ;
	infinite = (t_img *)hashmap_get(&core->hashmap, "Option_infinite");
	if (!infinite)
		return ;
	ammos = (t_img *)hashmap_get(&core->hashmap, "Option_ammos");
	if (!ammos)
		return ;
	transparency(bg, godmod, 930, y[3] + 10);
	transparency(bg, infinite, 955, y[4] - 20);
	transparency(bg, ammos, 955, y[4] + 25);
	update_slider_cursor(core, &core->menu_img->sliders[3], y[3], bg);
	update_slider_cursor(core, &core->menu_img->sliders[4], y[4], bg);
	on_off_sliders(core, y, bg);
}

static void	rewrite_options(t_core *core, const int *y, t_img *bg)
{
	t_img		*fov;
	t_img		*speed;
	t_img		*sound;

	fov = (t_img *)hashmap_get(&core->hashmap, "Option_fov");
	if (!fov)
		return ;
	speed = (t_img *)hashmap_get(&core->hashmap, "Option_speed");
	if (!speed)
		return ;
	sound = (t_img *)hashmap_get(&core->hashmap, "Option_sound");
	if (!sound)
		return ;
	transparency(bg, fov, (bg->width / 5) - 200, y[0] + 10);
	update_slider_cursor(core, &core->menu_img->sliders[0], y[0], bg);
	percent_option_rendering(core, &core->menu_img->sliders[0], bg);
	transparency(bg, speed, (bg->width / 5) - 250, y[1] + 7);
	update_slider_cursor(core, &core->menu_img->sliders[1], y[1], bg);
	percent_option_rendering(core, &core->menu_img->sliders[1], bg);
	transparency(bg, sound, (bg->width / 5) - 250, y[2] + 7);
	update_slider_cursor(core, &core->menu_img->sliders[2], y[2], bg);
	percent_option_rendering(core, &core->menu_img->sliders[2], bg);
	rewrite_cheats(core, core->y_pos, bg);
}

bool	render_pause_options(t_core *core)
{
	t_img	*option;
	int		i;

	i = -1;
	while (++i < 3)
		core->y_pos[i] = 400 + (i * 140);
	core->y_pos[3] = 400 + (1 * 70);
	core->y_pos[4] = 400 + (2 * 110);
	core->state = PAUSE_OPTION;
	copy_img(core->hud_img->pause_buffer, core->hud_img->clean_pause_buffer);
	option = (t_img *)hashmap_get(&core->hashmap, "Option_title");
	if (!option)
		return (false);
	transparency(core->hud_img->pause_buffer, option, 640, 260);
	rewrite_options(core, core->y_pos, core->hud_img->pause_buffer);
	mlx_put_image_to_window(core->mlx, core->win,
		core->hud_img->pause_buffer->img, 0, 0);
	return (true);
}
