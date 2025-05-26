/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:16:42 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/26 18:38:25 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_prefix(char *prefix[7])
{
	prefix[0] = "NO";
	prefix[1] = "SO";
	prefix[2] = "WE";
	prefix[3] = "EA";
	prefix[4] = "F";
	prefix[5] = "C";
	prefix[6] = NULL;
}

bool	init_textures_targets(void *targets[6], t_tmp *stock)
{
	stock->tmp_textures = ft_calloc(1, sizeof(t_textures));
	if (!stock->tmp_textures)
		return (false);
	ft_memset(stock->tmp_textures, 0, sizeof(t_textures));
	stock->width = 0;
	stock->height = 0;
	targets[0] = &stock->tmp_textures->north;
	targets[1] = &stock->tmp_textures->south;
	targets[2] = &stock->tmp_textures->west;
	targets[3] = &stock->tmp_textures->east;
	targets[4] = &stock->tmp_textures->floor_color;
	targets[5] = &stock->tmp_textures->ceiling_color;
	return (true);
}

bool	file_checker(t_tmp *stock, char *file_name)
{
	if (ft_strncmp(file_name, "maps/", 5) != 0)
	{
		ft_putendl_fd("Error \n Maps should be in a Cub3d/maps/ folder", 2);
		return (false);
	}
	stock->tmp_loaded_map = ft_substr(file_name, 5, ft_strlen(file_name));
	if (!stock->tmp_loaded_map)
		return (false);
	return (true);
}

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
	{
		ft_free_tab(stock->tmp_map_content);
		stock->tmp_map_content = NULL;
	}
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
	stock->tmp_map_content = NULL;
	core->map_start = stock->map_start;
	core->map_height = stock->height;
	core->map_width = stock->width;
	core->spawn = stock->spawn;
	if (!add_to_gc(&core->gc, core->spawn, STRUCT, "spawn_pos"))
		return (false);
	stock->spawn = NULL;
	core->textures = stock->tmp_textures;
	if (!add_to_gc(&core->gc, core->textures, STRUCT, "textures_struct"))
		return (false);
	stock->tmp_textures = NULL;
	core->colors = stock->tmp_colors;
	if (!add_to_gc(&core->gc, core->colors, STRUCT, "colors_struct"))
		return (false);
	stock->tmp_colors = NULL;
	free(stock);
	return (true);
}

//Fonction Corps du parsing
bool	parsing_cub(t_core *core, char *av)
{
	char	*prefix[7];
	void	*targets[7];
	t_tmp	*stock;

	stock = malloc(sizeof(t_tmp));
	if (!stock)
		return (free_parsing(stock), false);
	ft_memset(stock, 0, sizeof(t_tmp));
	init_prefix(prefix);
	if (!init_textures_targets(targets, stock))
		return (free_parsing(stock), false);
	stock->map_name = av;
	if (!valid_extension(".cub", stock->map_name))
		return (free_parsing(stock), ft_putendl_fd("Error \n Wrong map extension (.cub)", 2), false);
	if (!file_checker(stock, stock->map_name))
		return (free_parsing(stock), false);
	if (!file_extract(stock->map_name, &stock->tmp_maps, core))
		return (free_parsing(stock), false);
	if (!check_flag_position(stock, prefix))
		return (free_parsing(stock), false);
	if (!parse_textures_colors(stock, prefix, targets, core))
		return (free_parsing(stock), false);
	if (!parse_textures_content(core, stock, targets))
		return (free_parsing(stock), false);
	if (!parse_map(stock))
		return (free_parsing(stock), false);
	if (!load_valid_datas(core, stock))
		return (false);
	return (true);
}
