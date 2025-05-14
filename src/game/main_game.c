/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:44:46 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/14 14:50:20 by nmetais          ###   ########.fr       */
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

bool	create_maps_words(t_core *core)
{
	int		i;
	t_img	*new;

	new = NULL;
	i = 0;
	while (i < core->maps_nb)
	{
		if (!load_word_image(&new, core, core->menu_maps[i].name, "regular"))
			return (false);
		if (!hashmap_insert(&core->hashmap, core->menu_maps[i++].name,
				new, core))
			return (false);
	}
	return (true);
}

//GAME LAUNCH
bool	launch_game(t_core *core)
{
	if (!img_init(core))
		return (false);
	if (!extract_maps_names(core))
		return (false);
	if (!create_maps_words(core))
		return (false);
	start_menu(core);
	mlx_key_hook(core->win, handle_keypress, core);
	mlx_hook(core->win, 6, (1L << 6), mouse_menu_hover, core);
	mlx_hook(core->win, 4, (1L << 2), mouse_menu_click, core);
	mlx_loop_hook(core->mlx, routine, core);
	mlx_loop(core->mlx);
	return (true);
}
