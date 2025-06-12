/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pause_menu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:00:31 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/08 18:58:17 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rewrite_options(t_core *core, const int *y, t_img *bg)
{
	t_img	*conti;
	t_img	*options;
	t_img	*quit;

	conti = (t_img *)hashmap_get(&core->hashmap, "Pause_continue");
	options = (t_img *)hashmap_get(&core->hashmap, "Menu_options");
	quit = (t_img *)hashmap_get(&core->hashmap, "Menu_quit");
	if (!conti || !options || !quit)
		return ;
	transparency(bg, conti, (bg->width / 2) - 100, y[0]);
	transparency(bg, options, (bg->width / 2) - 100, y[1]);
	transparency(bg, quit, (bg->width / 2) - 100, y[2]);
}

//INIT Y POS
static void	start_menu_init(t_core *core)
{
	int	i;

	i = -1;
	while (++i < 4)
		core->y_pos[i] = 400 + (i * MENU_SPACING);
}

void	skulls_render_pause(t_core *core, const int *y)
{
	int			x;
	t_sprite	*skulls;

	x = (core->hud_img->pause_buffer->width / 2) - 100;
	skulls = hashmap_get(&core->hashmap_sprites, "skulls");
	if (!skulls)
		return ;
	transparency(core->hud_img->pause_buffer, skulls->img_list->image,
		x - (skulls->img_list->image->width + 10),
		y[core->menu_option]);
	mlx_put_image_to_window(core->mlx, core->win,
		core->hud_img->pause_buffer->img, 0, 0);
}

//MENU RENDERING EVERYTIME I DO A MOVEMENT IN THE MENU
bool	render_pause_menu(t_core *core)
{
	t_img	*pause;

	start_menu_init(core);
	copy_img(core->hud_img->pause_buffer, core->hud_img->clean_pause_buffer);
	pause = (t_img *)hashmap_get(&core->hashmap, "Pause_menu");
	if (!pause)
		return (false);
	transparency(core->hud_img->pause_buffer, pause, 640, 260);
	rewrite_options(core, core->y_pos, core->hud_img->pause_buffer);
	skulls_render_pause(core, core->y_pos);
	core->redraw = false;
	return (true);
}
