/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:45:42 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/29 18:44:19 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	map_selector(t_core *core)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin("maps/", core->menu_maps[core->menu_option].name);
	if (!tmp)
		return (false);
	tmp2 = ft_strjoin(tmp, ".cub");
	if (!tmp2)
		return (false);
	free(tmp);
	if (!(ft_strcmp(core->menu_maps[core->menu_option].name,
				core->loaded_map - 4) == 0) && !parsing_cub(core, tmp2))
	{
		ft_putendl_fd("loading failed", 2);
		return (free(tmp2), true);
	}
	hashmap_delete(&core->hashmap, "loaded_name", core, destroy_single_img);
	load_word_image(&core->menu_img->loaded_map, core,
		core->menu_maps[core->menu_option].name, "regular");
	hashmap_insert(&core->hashmap, "loaded_name",
		(void *)core->menu_img->loaded_map, core);
	core->loaded_map = core->menu_maps[core->menu_option].name;
	core->menu_maps[core->menu_option].parsed = true;
	return (free(tmp2), true);
}

void	extend_menu_handler(t_core *core, int key)
{
	if (key == XK_BackSpace)
	{
		core->state = START_MENU;
		core->menu_option = 2;
		render_menu(core);
	}
	if (key == XK_Return)
	{
		if (core->menu_option < core->maps_nb)
			if (!map_selector(core))
				return ;
	}
}

void	maps_menu_keypress(int key, t_core *core)
{
	if (!core->enter)
	{
		core->enter = 1;
		return ;
	}
	if (key == XK_Up)
	{
		if (core->menu_option > 0)
		{
			core->menu_option--;
			if (core->menu_option < core->scroll_offset)
				core->scroll_offset--;
		}
		render_maps_menu(core);
	}
	else if (key == XK_Down)
	{
		if (core->menu_option < core->maps_nb - 1)
		{
			core->menu_option++;
			if (core->menu_option >= core->scroll_offset + VISIBLE)
				core->scroll_offset++;
		}
		render_maps_menu(core);
	}
	extend_menu_handler(core, key);
}
