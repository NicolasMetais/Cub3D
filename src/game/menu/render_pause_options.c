/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pause_options.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:49:55 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/12 18:51:10 by nmetais          ###   ########.fr       */
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

static void	rewrite_options(t_core *core, const int *y, t_img *bg)
{
	t_img		*option1;
	char		*percent;

	option1 = (t_img *)hashmap_get(&core->hashmap, "Option_fov");
	if (!option1)
		return ;
	transparency(bg, option1, (bg->width / 3), y[0] + 10);
	update_slider(core, y, bg);
	percent = ft_itoa(core->fov);
	if (!percent)
		return ;
	if (!render_percent(core, percent, 790, bg))
		return ;
}

static void	option_menu_init(t_core *core)
{
	int	i;

	i = -1;
	while (++i < 1)
		core->y_pos[i] = 650 + (i * MENU_SPACING);
}

bool	render_pause_options(t_core *core)
{
	t_img	*option;

	core->state = PAUSE_OPTION;
	option_menu_init(core);
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
