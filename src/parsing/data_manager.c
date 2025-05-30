/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:56:58 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/26 19:02:40 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_parsing(t_tmp *stock)
{
	if (stock->tmp_textures)
	{
		free(stock->tmp_textures->north);
		free(stock->tmp_textures->south);
		free(stock->tmp_textures->west);
		free(stock->tmp_textures->east);
		free(stock->tmp_textures->floor_color);
		free(stock->tmp_textures->ceiling_color);
		free(stock->tmp_textures);
	}
	if (stock->tmp_colors)
	{
		free(stock->tmp_colors->floor);
		free(stock->tmp_colors->ceiling);
		free(stock->tmp_colors);
	}
	if (stock->spawn)
		free(stock->spawn);
	if (stock->tmp_map_content)
		ft_free_tab(stock->tmp_map_content);
	if (stock->tmp_loaded_map)
		free(stock->tmp_loaded_map);
	free(stock);
}

bool	load_valid_datas(t_core *core, t_tmp *stock)
{
	core->map_name = stock->map_name;
	core->loaded_map = stock->tmp_loaded_map;
	if (!add_to_gc(&core->gc, core->loaded_map, STRING, "loaded_map"))
		return (false);
	stock->tmp_loaded_map = NULL;
	stock->tmp_maps = NULL;
	core->map = stock->tmp_map_content;
	if (!add_to_gc(&core->gc, core->map, TAB_STRING, "map"))
		return (false);
	core->map_start = stock->map_start;
	core->map_height = stock->height;
	core->map_width = stock->width;
	core->spawn = stock->spawn;
	if (!add_to_gc(&core->gc, core->spawn, STRUCT, "spawn_pos"))
		return (false);
	core->textures = stock->tmp_textures;
	if (!add_to_gc(&core->gc, core->textures, STRUCT, "textures_struct"))
		return (false);
	core->colors = stock->tmp_colors;
	if (!add_to_gc(&core->gc, core->colors, STRUCT, "colors_struct"))
		return (false);
	free(stock);
	return (true);
}
