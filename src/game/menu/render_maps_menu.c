/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_maps_menu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:34:35 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/13 21:44:46 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//TEMPORAIRE
void	skulls_render_tempo(t_core *core, const int *y, int frame)
{
	int			x;

	x = (core->menu_img->bg->width / 2) - 100;
	transparency(core->menu_img->bg, core->menu_img->skulls->sprites[frame],
		x - (core->menu_img->skulls->sprites[frame]->width + 10),
		y[core->menu_option]);
	mlx_put_image_to_window(core->mlx, core->win, core->menu_img->bg->img,
		0, 0);
}

static void	rewrite_options(t_core *core, const int *y, t_img *bg)
{
	t_img		*map_word;
	int			i;

	i = 0;
	while (i < core->maps_nb)
	{
		map_word = hashmap_get(&core->hashmap, core->menu_maps[i].name);
		transparency(bg, map_word, (bg->width / 4) + 300,
			MENU_START_Y + (i++ *MENU_SPACING));
	}
	skulls_render_tempo(core, y, core->menu_img->skulls->frame);
}

bool	render_maps_menu(t_core *core)
{
	core->state = MAPS_MENU;
	copy_img(core->menu_img->bg, core->menu_img->bg_clean);
	rewrite_options(core, core->y_pos, core->menu_img->bg);
	mlx_put_image_to_window(core->mlx, core->win, core->menu_img->bg->img,
		0, 0);
	return (true);
}
