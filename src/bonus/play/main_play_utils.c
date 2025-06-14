/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_play_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:33:47 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/12 20:18:58 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_door(t_core *core)
{
	if (core->rc->dist3[S_LENGHT / 2] < 24 && \
		(core->rc->front_wall == '2' || core->rc->front_wall == '4' \
		|| core->rc->front_wall == '5' || core->rc->front_wall == '6' \
		|| core->rc->front_wall == '7'))
	{
		if (core->map[core->rc->front_y][core->rc->front_x] == '2')
		{
			core->map[core->rc->front_y][core->rc->front_x] = '3';
			if (core->map[core->rc->front_y - 1][core->rc->front_x] != '0')
				core->map[core->rc->front_y - 1][core->rc->front_x] = '4';
			if (core->map[core->rc->front_y + 1][core->rc->front_x] != '0')
				core->map[core->rc->front_y + 1][core->rc->front_x] = '5';
			if (core->map[core->rc->front_y][core->rc->front_x + 1] != '0')
				core->map[core->rc->front_y][core->rc->front_x + 1] = '6';
			if (core->map[core->rc->front_y][core->rc->front_x - 1] != '0')
				core->map[core->rc->front_y][core->rc->front_x - 1] = '7';
		}
		else if (core->rc->dist3[S_LENGHT / 2] > 9)
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
	}
}

bool	init_map_textures(t_core *core)
{
	core->textures->path_sky = "/tmp_assets/SKY3.xpm";
	core->textures->path_door = "/tmp_assets/DOOR2_4.xpm";
	core->textures->path_open_door = "/tmp_assets/OPEN_DOOR2_4.xpm";
	core->textures->open_doors = (t_img *)hashmap_get(&core->hashmap, "Open_Door");
	core->textures->door = (t_img *)hashmap_get(&core->hashmap, "Door");
	core->textures->sky = (t_img *)hashmap_get(&core->hashmap, "Sky");
	core->textures->tmp_north = (t_img *)hashmap_get(&core->hashmap, \
	"Wall_north");
	core->textures->tmp_south = (t_img *)hashmap_get(&core->hashmap, \
	"Wall_south");
	core->textures->tmp_east = (t_img *)hashmap_get(&core->hashmap, \
	"Wall_east");
	core->textures->tmp_west = (t_img *)hashmap_get(&core->hashmap, \
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
