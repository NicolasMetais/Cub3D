/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:16:42 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/14 13:17:03 by nmetais          ###   ########.fr       */
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

bool	init_textures_targets(void *targets[6], t_core *core)
{
	if (!core->textures)
	{
		core->textures = ft_calloc(1, sizeof(t_textures));
		if (!core->textures)
			return (false);
		if (!add_to_gc(&core->gc, core->textures, STRUCT, "textures_struct"))
			return (false);
	}
	else
	{
		free_gc(core->gc, "map");
		free_gc(core->gc, "textures");
	}
	targets[0] = &core->textures->north;
	targets[1] = &core->textures->south;
	targets[2] = &core->textures->west;
	targets[3] = &core->textures->east;
	targets[4] = &core->textures->floor_color;
	targets[5] = &core->textures->ceiling_color;
	return (true);
}

bool	file_checker(t_core *core, char *file_name)
{
	if (ft_strncmp(file_name, "maps/", 5) != 0)
	{
		ft_putendl_fd("Error \n Maps should be in a Cub3d/maps/ folder", 2);
		return (false);
	}
	if (core->loaded_map)
		free_gc(core->gc, "loaded_map");
	core->loaded_map = ft_substr(file_name, 5, ft_strlen(file_name));
	add_to_gc(&core->gc, core->loaded_map, STRING, "loaded_map");
	return (true);
}

//Fonction Corps du parsing
bool	parsing_cub(t_core *core, char *av)
{
	char	*prefix[7];
	void	*targets[7];

	init_prefix(prefix);
	if (!init_textures_targets(targets, core))
		return (false);
	core->map_name = av;
	if (!valid_extension(".cub", core->map_name))
		return (ft_putendl_fd("Error \n Wrong map extension (.cub)", 2), false);
	if (!file_checker(core, core->map_name))
		return (false);
	if (!file_extract(core->map_name, &core->map))
		return (false);
	if (!add_to_gc(&core->gc, core->map, TAB_STRING, "map"))
		return (false);
	if (!check_flag_position(core, prefix))
		return (false);
	if (!parse_textures_colors(core, prefix, targets))
		return (false);
	if (!parse_textures_content(core, targets))
		return (false);
	if (!parse_map(core))
		return (false);
	printf("parsed\n");
	return (true);
}
