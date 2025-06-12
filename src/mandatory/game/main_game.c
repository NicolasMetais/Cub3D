/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:44:46 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/30 16:54:54 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sliders_default_values(t_core *core)
{
	int	slider_min;
	int	slider_max;

	core->fov_ratio = (float)(FOV_DEFAULT - FOV_MIN) / (FOV_MAX - FOV_MIN);
	slider_min = core->menu_img->bg->width / 2 - 70;
	slider_max = slider_min + core->menu_img->slider_bar->width
		- core->menu_img->cursor->width;
	core->x = slider_min + ((slider_max - slider_min) * core->fov_ratio);
}

bool	img_init(t_core *core)
{
	int		width;
	char	*name;

	width = 0;
	core->menu_img->cursor = (t_img *)hashmap_get(&core->hashmap, "Slider_cursor");
	core->menu_img->bg =(t_img *) hashmap_get(&core->hashmap, "Menu_bg_activ");
	core->menu_img->bg_clean = (t_img *)hashmap_get(&core->hashmap, "Menu_bg_clean");
	name = ft_substr(core->loaded_map, 0, ft_strlen(core->loaded_map) - 4);
	if (!name)
		return (false);
	load_word_image(&core->menu_img->loaded_map, core, name, "regular");
	hashmap_insert(&core->hashmap, "loaded_name", (void *)core->menu_img->loaded_map, core);
	free(name);
	core->menu_img->minimap->img = mlx_new_image(core->mlx, 180, 180);
	if (!core->menu_img->minimap->img)
		return (false);
	core->menu_img->minimap->addr = mlx_get_data_addr(
			core->menu_img->minimap->img,
			&core->menu_img->minimap->bpp,
			&core->menu_img->minimap->line_len,
			&core->menu_img->minimap->endian);
	core->menu_img->minimap->width = 180;
	core->menu_img->minimap->height = 180;
	hashmap_insert(&core->hashmap, "minimap", (void *)core->menu_img->minimap, core);
	if (!slider_constructor(core, width))
		return (false);
	sliders_default_values(core);
	return (true);
}


//INIT IMAGES
bool	menus_init(t_core *core)
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
	core->menu_img->slider_bar = gc_malloc(&core->gc, sizeof(t_img),
			STRUCT, "slider_bar");
	if (!core->menu_img->slider_bar)
		return (false);
	core->menu_img->minimap = gc_malloc(&core->gc, sizeof(t_img),
			STRUCT, "minimap");
	if (!core->menu_img->minimap)
		return (false);
	img_init(core);
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
				(void *)new, core))
			return (false);
	}
	return (true);
}

//GAME LAUNCH
bool	launch_game(t_core *core)
{
	if (!menus_init(core))
		return (false);
	if (!extract_maps_names(core))
		return (false);
	if (!create_maps_words(core))
		return (false);
	if (core->map_height > core->map_width)
		core->tmp_rc->map_size = core->map_height * 8;
	else
		core->tmp_rc->map_size = core->map_width * 8;
	core->state = GAME;
	if (!game_init(core))
		return (1);
	core->fov = 60;
	//start_menu(core);
	mlx_hook(core->win, 2, 1L << 0, &handle_keypress, core);
	mlx_hook(core->win, 3, 1L << 1, &handle_keyrelease, core);
	// mlx_hook(core->win, 6, (1L << 6), mouse_menu_hover, core);
	// mlx_hook(core->win, 4, (1L << 2), mouse_menu_click, core);
	// mlx_hook(core->win, 5, (1L << 3), mouse_menu_release, core);
	//init_tmp(core);
	//core->redraw = true;
	//mlx_key_hook(core->win, handle_keypress, core);
	mlx_loop_hook(core->mlx, &routine, core);
	mlx_loop(core->mlx);
	return (true);
}
