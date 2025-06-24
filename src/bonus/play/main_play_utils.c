/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_play_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:33:47 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/24 19:31:44 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	open_door(t_core *core)
{
	core->map[core->rc->front_y][core->rc->front_x] = '3';
	if (core->map[core->rc->front_y - 1][core->rc->front_x] != '0' \
		&& core->map[core->rc->front_y - 1][core->rc->front_x] != 'F')
		core->map[core->rc->front_y - 1][core->rc->front_x] = '4';
	if (core->map[core->rc->front_y + 1][core->rc->front_x] != '0' \
		&& core->map[core->rc->front_y + 1][core->rc->front_x] != 'F')
		core->map[core->rc->front_y + 1][core->rc->front_x] = '5';
	if (core->map[core->rc->front_y][core->rc->front_x + 1] != '0' \
		&& core->map[core->rc->front_y][core->rc->front_x + 1] != 'F')
		core->map[core->rc->front_y][core->rc->front_x + 1] = '6';
	if (core->map[core->rc->front_y][core->rc->front_x - 1] != '0' \
		&& core->map[core->rc->front_y][core->rc->front_x - 1] != 'F')
		core->map[core->rc->front_y][core->rc->front_x - 1] = '7';
}

static void	close_door(t_core *core)
{
	if (core->map[core->rc->front_y][core->rc->front_x] == '4')
		core->map[core->rc->front_y + 1][core->rc->front_x] = '2';
	if (core->map[core->rc->front_y][core->rc->front_x] == '5')
		core->map[core->rc->front_y - 1][core->rc->front_x] = '2';
	if (core->map[core->rc->front_y][core->rc->front_x] == '6')
		core->map[core->rc->front_y][core->rc->front_x - 1] = '2';
	if (core->map[core->rc->front_y][core->rc->front_x] == '7')
		core->map[core->rc->front_y][core->rc->front_x + 1] = '2';
}

void	handle_door(t_core *core)
{
	if (core->rc->dist3[S_LENGHT / 2] < 24 && \
		(core->rc->front_wall == '2' || core->rc->front_wall == '4' \
		|| core->rc->front_wall == '5' || core->rc->front_wall == '6' \
		|| core->rc->front_wall == '7'))
	{
		if (core->map[core->rc->front_y][core->rc->front_x] == '2')
			open_door(core);
		else if (core->rc->dist3[S_LENGHT / 2] > 9)
			close_door(core);
	}
}

bool	init_map_textures(t_core *core)
{
	core->textures->floor_colors = ft_split(core->textures->floor_color, ',');
	if (!core->textures->floor_colors)
		return (false);
	core->textures->open_doors = (t_img *)hashmap_get(&core->hashmap, \
	"Open_Door");
	core->textures->door = (t_img *)hashmap_get(&core->hashmap, "Door");
	core->textures->sky = (t_img *)hashmap_get(&core->hashmap, "Sky");
	if (!core->textures->open_doors || !core->textures->door || core->textures->sky)
		return (false);
	if (!load_image(&core->textures->img_north, \
		core->textures->north, core, "1"))
		return (false);
	if (!load_image(&core->textures->img_south, \
		core->textures->south, core, "1"))
		return (false);
	if (!load_image(&core->textures->img_east, core->textures->east, core, "1"))
		return (false);
	if (!load_image(&core->textures->img_west, core->textures->west, core, "1"))
		return (false);
	hashmap_insert(&core->hashmap, "North", core->textures->img_north, core);
	hashmap_insert(&core->hashmap, "South", core->textures->img_south, core);
	hashmap_insert(&core->hashmap, "East", core->textures->img_east, core);
	hashmap_insert(&core->hashmap, "West", core->textures->img_west, core);
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
