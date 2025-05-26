/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_maps_menu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:34:35 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/15 13:17:12 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//TEMPORAIRE
void	skulls_render_maps(t_core *core, const int *y, int frame)
{
	int			x;
	int			index_y;

	x = (core->menu_img->bg->width / 2) - 100;
	index_y = core->menu_option - core->scroll_offset;
	if (index_y >= 0 && index_y < VISIBLE)
	{
		transparency(core->menu_img->bg, core->menu_img->skulls->sprites[frame],
			x - (core->menu_img->skulls->sprites[frame]->width + 10),
			y[index_y]);
	}
}

static void	rewrite_options(t_core *core, const int *y, t_img *bg)
{
	t_img		*map_word;
	int			i;
	int			index;

	i = 0;
	while (i < VISIBLE)
	{
		index = i + core->scroll_offset;
		if (index >= core->maps_nb)
			break ;
		map_word = hashmap_get(&core->hashmap, core->menu_maps[index].name);
		transparency(bg, map_word, (bg->width / 4) + 300,
			590 + (i++ *MENU_SPACING));
	}
	skulls_render_maps(core, y, core->menu_img->skulls->frame);
}

static void	maps_menu_init(t_core *core)
{
	int	i;

	i = -1;
	while (++i < 4)
		core->y_pos[i] = 590 + (i * MENU_SPACING);
}

bool	render_maps_menu(t_core *core)
{
	t_img	*select;

	core->state = MAPS_MENU;
	maps_menu_init(core);
	copy_img(core->menu_img->bg, core->menu_img->bg_clean);
	select = hashmap_get(&core->hashmap, "Map_selection");
	transparency(core->menu_img->bg, select, 370, 440);
	rewrite_options(core, core->y_pos, core->menu_img->bg);
	mlx_put_image_to_window(core->mlx, core->win, core->menu_img->bg->img,
		0, 0);
	return (true);
}
