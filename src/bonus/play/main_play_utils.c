/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_play_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:33:47 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/20 13:59:00 by nmetais          ###   ########.fr       */
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
//check ft_split allocation
bool	init_map_textures(t_core *core)
{
	// core->textures->floor_colors = ft_split(core->textures->floor_color, ',');
	core->textures->path_sky = "/tmp_assets/SKY/SKY3.xpm";
	core->textures->path_door = "/tmp_assets/WALL/DOOR2_4.xpm";
	core->textures->path_open_door = "/tmp_assets/WALL/OPEN_DOOR2_4.xpm";
	core->textures->open_doors = (t_img *)hashmap_get(&core->hashmap, \
	"Open_Door");
	core->textures->door = (t_img *)hashmap_get(&core->hashmap, "Door");
	core->textures->sky = (t_img *)hashmap_get(&core->hashmap, "Sky");
	core->textures->img_north = (t_img *)hashmap_get(&core->hashmap, \
	"Wall_north");
	core->textures->img_south = (t_img *)hashmap_get(&core->hashmap, \
	"Wall_south");
	core->textures->img_east = (t_img *)hashmap_get(&core->hashmap, \
	"Wall_east");
	core->textures->img_west = (t_img *)hashmap_get(&core->hashmap, \
	"Wall_west");
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
