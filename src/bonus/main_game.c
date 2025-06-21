/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:44:46 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/21 16:24:06 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	img_init(t_core *core)
{
	int		width;
	char	*name;

	width = 0;
	core->active_slider = -1;
	core->menu_img->cursor = hashmap_get(&core->hashmap, "Slider_cursor");
	core->menu_img->bg = hashmap_get(&core->hashmap, "Menu_bg_activ");
	core->menu_img->bg_clean = hashmap_get(&core->hashmap, "Menu_bg_clean");
	if (!core->menu_img->cursor || !core->menu_img->bg
		|| !core->menu_img->bg_clean)
		return (false);
	name = ft_substr(core->loaded_map, 0, ft_strlen(core->loaded_map) - 4);
	if (!name)
		return (false);
	load_word_image(&core->menu_img->loaded_map, core, name, "regular");
	hashmap_insert(&core->hashmap, "loaded_name",
		core->menu_img->loaded_map, core);
	free(name);
	core->menu_img->minimap = load_buffer(core->menu_img->minimap,
			180, 180, core);
	if (!core->menu_img->minimap)
		return (false);
	if (!sliders_init(core, width))
		return (false);
	return (true);
}

//INIT IMAGES
bool	menus_init(t_core *core)
{
	core->fontss = gc_malloc(&core->gc, sizeof(t_fonts), STRUCT, "fonts");
	if (!core->fontss)
		return (false);
	init_chars_nodes(core);
	core->menu_img = gc_malloc(&core->gc, sizeof(t_menu_img),
			STRUCT, "menu img");
	if (!core->menu_img)
		return (false);
	if (!extract_img_data(core))
		return (false);
	core->menu_img->slider_bar = gc_malloc(&core->gc, sizeof(t_img),
			STRUCT, "slider_bar");
	if (!core->menu_img->slider_bar)
		return (false);
	core->menu_img->slider_small = gc_malloc(&core->gc, sizeof(t_img),
			STRUCT, "slider_small");
	if (!core->menu_img->slider_small)
		return (false);
	core->menu_img->minimap = gc_malloc(&core->gc, sizeof(t_img),
			STRUCT, "minimap");
	if (!core->menu_img->minimap)
		return (false);
	if (!img_init(core))
		return (false);
	return (true);
}

bool	create_maps_words(t_core *core)
{
	int		i;
	t_img	*new;

	new = NULL;
	i = 0;
	core->speed = PLAYER_SPEED;
	core->sound = SOUND;
	core->cursor[0] = 482;
	core->cursor[1] = 347;
	core->cursor[2] = 482;
	core->cursor[3] = 1255;
	core->cursor[4] = 1255;
	while (i < core->maps_nb)
	{
		if (!load_word_image(&new, core, core->menu_maps[i].name, "regular"))
			return (false);
		if (!hashmap_insert(&core->hashmap, core->menu_maps[i++].name,
				(void *)new, core))
			return (false);
	}
	return (true);
}

//GAME LAUNCH
bool	launch_game(t_core *core)
{
	music_init(core);
	play_random_music(core);
	if (!menus_init(core))
		return (false);
	if (!extract_maps_names(core))
		return (false);
	if (!create_maps_words(core))
		return (false);
	core->fov = 90;
	core->win = mlx_new_window(core->mlx, S_LENGHT, S_HEIGHT, "Cub3D");
	if (!core->win)
		return (false);
	start_menu(core);
	mlx_hook(core->win, 2, 1L << 0, &handle_keypress, core);
	mlx_hook(core->win, 3, 1L << 1, &handle_keyrelease, core);
	mlx_hook(core->win, 6, (1L << 6), mouse_menu_hover, core);
	mlx_hook(core->win, 4, (1L << 2), mouse_menu_click, core);
	mlx_hook(core->win, 5, (1L << 3), mouse_menu_release, core);
	mlx_hook(core->win, 17, 1L << 17, &cross_handler, core);
	mlx_loop_hook(core->mlx, &routine, core);
	mlx_loop(core->mlx);
	return (true);
}
