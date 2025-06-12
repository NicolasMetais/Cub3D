/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_options_menu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:19:51 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/08 18:57:37 by nmetais          ###   ########.fr       */
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
} */

void	update_slider(t_core *core, const int *y, t_img *bg)
{
	transparency(bg, core->menu_img->slider_bar, (bg->width / 2) - 70, y[0]);
	transparency(bg, core->menu_img->slider_bar, (bg->width / 2) - 70, y[0]);
	transparency(bg, core->menu_img->cursor, core->x, y[0] + 5);
}

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

bool	render_options_menu(t_core *core)
{
	t_img	*option;

	core->state = OPTIONS_MENU;
	option_menu_init(core);
	copy_img(core->menu_img->bg, core->menu_img->bg_clean);
	option = (t_img *)hashmap_get(&core->hashmap, "Option_title");
	if (!option)
		return (false);
	transparency(core->menu_img->bg, option, 545, 440);
	rewrite_options(core, core->y_pos, core->menu_img->bg);
	mlx_put_image_to_window(core->mlx, core->win, core->menu_img->bg->img,
		0, 0);
	return (true);
}
