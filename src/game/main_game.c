/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:44:46 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/05 05:37:23 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//INIT IMAGES
bool	img_init(t_core *core)
{
	core->fonts = gc_malloc(&core->gc, sizeof(t_fonts), STRUCT, "fonts");
	if (!core->fonts)
		return (false);
	init_chars_nodes(core);
	core->menu_img = gc_malloc(&core->gc, sizeof(t_menu_img),
			STRUCT, "menu img");
	if (!core->menu_img)
		return (false);
	if (!extract_img_data(core))
		return (false);
	core->menu_img->bg = hashmap_get(&core->hashmap, "Menu_bg_activ");
	core->menu_img->bg_clean = hashmap_get(&core->hashmap, "Menu_bg_clean");
	return (true);
}

//GAME LAUNCH
bool	launch_game(t_core *core)
{
	if (!img_init(core))
		return (false);
	start_menu(core);
	mlx_key_hook(core->win, handle_keypress, core);
	mlx_loop_hook(core->mlx, routine, core);
	mlx_loop(core->mlx);
	return (true);
}
