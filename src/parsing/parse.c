/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:16:42 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/22 21:00:48 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Fonction Corps du parsing
bool	parsing_cub(t_core *core, char *av)
{
	core->map_name = av;
	if (!valid_extension(".cub", core->map_name))
	{
		ft_putendl_fd("Error \n Wrong map extension (.cub)", 2);
		return (false);
	}
	if (!file_extract(core))
		return (false);
	if (!check_map_validity(core))
		return (false);
	if (!parse_textures_colors(core))
		return (false);
	return (true);
}
