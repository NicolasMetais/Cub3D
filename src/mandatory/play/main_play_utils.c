/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_play_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:33:47 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/24 18:56:47 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_map_textures(t_core *core)
{
	core->textures->floor_colors = ft_split(core->textures->floor_color, ',');
	core->textures->ceiling_colors = \
	ft_split(core->textures->ceiling_color, ',');
	if (!core->textures->floor_colors)
		return (false);
	if (!load_img(&core->textures->img_north, \
		core->textures->north, core))
		return (false);
	if (!load_img(&core->textures->img_south, \
		core->textures->south, core))
		return (false);
	if (!load_img(&core->textures->img_east, core->textures->east, core))
		return (false);
	if (!load_img(&core->textures->img_west, core->textures->west, core))
		return (false);
	return (true);
}

void	rays_updates(t_core *core)
{
	core->rc->r++;
	core->rc->ra += RAD / (core->rc->max_r / core->fov);
	if (core->rc->ra < 0)
		core->rc->ra += 2 * PI;
	if (core->rc->ra > 2 * PI)
		core->rc->ra -= 2 * PI;
}
