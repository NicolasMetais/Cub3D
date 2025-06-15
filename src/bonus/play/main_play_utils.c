/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_play_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:33:47 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/15 17:50:17 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_door_data(t_core *core)
{
	core->open_door->ty_off = 0;
	core->open_door->line_h = (8 * S_HEIGHT) / \
	core->tmp_rc->door_dist[core->tmp_rc->r];
	core->open_door->step = (float)core->textures->tmp_east->height / \
	(float)core->open_door->line_h;
	core->open_door->line_s = (S_HEIGHT - core->open_door->line_h) / 2;
	core->open_door->line_e = core->open_door->line_s + core->open_door->line_h;
	if (core->open_door->line_h > S_HEIGHT)
	{
		core->open_door->ty_off = (core->open_door->line_h - S_HEIGHT) / 2;
		core->open_door->line_e = S_HEIGHT;
	}
	core->open_door->y = 0;
	core->open_door->tx = 0;
	if (core->tmp_rc->was_vertical)
		core->open_door->offset = fmodf(core->tmp_rc->door_y, 8);
	else
		core->open_door->offset = fmodf(core->tmp_rc->door_x, 8);
	core->open_door->offset = fmodf(core->open_door->offset, 8.0f);
	if (core->open_door->offset < 0)
		core->open_door->offset += 8.0f;
}

void	draw_opening_door(t_core *core, int i)
{
	int		offset;
	float	ratio;

	ratio = (float)i / (float)12;
	offset = core->textures->door->height * ratio;
	core->door_anim->corrected_ty = core->tmp_3d->ty + offset;
	if (core->door_anim->corrected_ty >= core->textures->door->height)
		return;
	core->open_door->tex_index = ((int)core->door_anim->corrected_ty * \
	(core->textures->door->line_len ) + (int)core->open_door->tx * \
	(core->textures->door->bpp / 8));
	core->game_img->addr[core->open_door->pixel_index + 0] = \
	core->textures->door->addr[(int)core->open_door->tex_index + 0];
	core->game_img->addr[core->open_door->pixel_index + 1] = \
	core->textures->door->addr[(int)core->open_door->tex_index + 1];
	core->game_img->addr[core->open_door->pixel_index + 2] = \
	core->textures->door->addr[(int)core->open_door->tex_index + 2];
}

void	anim_door(t_core *core)
{
	struct timeval	current;

	if (!core->door_anim->active)
		return;
	get_door_data(core);
	if (core->door_anim->frame < 12)
	{
		gettimeofday(&current, NULL);
		core->door_anim->elapsed = ((current.tv_sec) * 1000 + (current.tv_usec) / 1000) - core->door_anim->start;
		if (core->door_anim->elapsed >= 50)
		{
			draw_opening_door(core, core->door_anim->frame);
			core->door_anim->frame++;
			gettimeofday(&current, NULL);
			core->door_anim->start = ((current.tv_sec) * 1000 + (current.tv_usec) / 1000);
		}
	}
	else
	{
		core->map[core->door_anim->map_y][core->door_anim->map_x] = '0';
		core->door_anim->active = 0;
		core->tmp_rc->open_door = 0;
	}
}

void	handle_door(t_core *core)
{
	struct timeval	current;

	if (core->tmp_rc->dist3[S_LENGHT / 2] < 16 && \
		core->tmp_rc->front_wall == '2')
	{
		if (core->map[core->tmp_rc->front_y][core->tmp_rc->front_x] == '2')
			core->map[core->tmp_rc->front_y][core->tmp_rc->front_x] = '3';
		core->door_anim->map_x = (int)core->tmp_rc->front_x ;
		core->door_anim->map_y = (int)core->tmp_rc->front_y;
		core->door_anim->frame = 0;
		core->door_anim->active = 1;
		gettimeofday(&current, NULL);
		core->door_anim->start = (current.tv_sec) * 1000 + (current.tv_usec) / 1000;
	}
}

bool	init_map_textures(t_core *core)
{
	core->door_anim = ft_calloc(1, sizeof(t_door_anim));
	core->open_door = ft_calloc(1, sizeof(t_open_door));
	core->textures->path_sky = "/tmp_assets/SKY3.xpm";
	core->textures->path_door = "/tmp_assets/DOOR2_4.xpm";
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
	core->tmp_rc->r++;
	core->tmp_rc->ra += RAD / (core->tmp_rc->max_r / core->fov);
	if (core->tmp_rc->ra < 0)
		core->tmp_rc->ra += 2 * PI;
	if (core->tmp_rc->ra > 2 * PI)
		core->tmp_rc->ra -= 2 * PI;
}
