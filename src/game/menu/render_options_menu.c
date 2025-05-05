/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_options_menu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:19:51 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/05 18:42:01 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rewrite_options(t_core *core)
{
	t_menu_img	*menu;
	const int	y_pos[2] = {
		MENU_START_Y + (0 * MENU_SPACING),
		MENU_START_Y + (1 * MENU_SPACING)
	};
	t_img		*option1;
	t_img		*option2;

	menu = core->menu_img;
	option1 = hashmap_get(&core->hashmap, "Menu_option1");
	option2 = hashmap_get(&core->hashmap, "Menu_option2");
	transparency(menu->bg, option1, (menu->bg->width / 4), y_pos[0]);
	transparency(menu->bg, option2, (menu->bg->width / 4), y_pos[1]);
	skulls_render_tempo(core, y_pos, core->menu_img->skulls->frame);
}

bool	render_options_menu(t_core *core)
{
	t_img	*option_win;

	core->state = OPTIONS_MENU;
	//core->menu_option = 0;
	option_win = hashmap_get(&core->hashmap, "Submenu_option");
	transparency(core->menu_img->bg, option_win, 300, 150);
	rewrite_options(core);
	mlx_put_image_to_window(core->mlx, core->win, core->menu_img->bg->img,
		0, 0);
	return (true);
}
