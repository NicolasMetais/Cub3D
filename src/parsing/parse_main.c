/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:16:42 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/02 19:17:42 by nmetais          ###   ########.fr       */
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
	core->textures = ft_calloc(1, sizeof(t_textures));
	if (!core->textures)
		return (false);
	if (!add_to_gc(&core->gc, core->textures, STRUCT, "textures"))
		return (false);
	targets[0] = &core->textures->north;
	targets[1] = &core->textures->south;
	targets[2] = &core->textures->west;
	targets[3] = &core->textures->east;
	targets[4] = &core->textures->floor_color;
	targets[5] = &core->textures->ceiling_color;
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
	{
		ft_putendl_fd("Error \n Wrong map extension (.cub)", 2);
		return (false);
	}
	if (!file_extract(core))
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
	return (true);
}
