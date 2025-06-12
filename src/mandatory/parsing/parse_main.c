/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:16:42 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/26 19:01:51 by nmetais          ###   ########.fr       */
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

bool	parsing_cub_2(t_core *core, t_tmp *stock, void *targets[7],
		char *prefix[7])
{
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
		return (free_parsing(stock),
			ft_putendl_fd("Error \n Wrong map extension (.cub)", 2), false);
	if (!file_checker(stock, stock->map_name))
		return (free_parsing(stock), false);
	if (!file_extract(stock->map_name, &stock->tmp_maps, core))
		return (free_parsing(stock), false);
	if (!check_flag_position(stock, prefix))
		return (free_parsing(stock), false);
	if (!parsing_cub_2(core, stock, targets, prefix))
		return (false);
	return (true);
}
