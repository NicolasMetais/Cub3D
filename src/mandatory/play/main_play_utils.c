/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_play_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:33:47 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/13 00:16:10 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_map_textures(t_core *core)
{
	core->textures->sky = gc_malloc(&core->gc, sizeof(t_img), STRUCT, "textu");
	if (!core->textures->sky)
		return (false);
	if (!load_image(&core->textures->sky, "tmp_assets/SKY3.xpm", core, "4"))
		return (false);
	core->textures->img_north = gc_malloc(&core->gc,
			sizeof(t_img), STRUCT, "textu");
	if (!core->textures->img_north)
		return (false);
	if (!load_img(&core->textures->img_north, "tmp_assets/MWALL3_1.xpm", core))
		return (false);
	core->textures->img_south = gc_malloc(&core->gc,
			sizeof(t_img), STRUCT, "textu");
	if (!core->textures->img_south)
		return (false);
	if (!load_img(&core->textures->img_south, "tmp_assets/MWALL4_1.xpm", core))
		return (false);
	core->textures->img_east = gc_malloc(&core->gc,
			sizeof(t_img), STRUCT, "textu");
	if (!core->textures->img_east)
		return (false);
	if (!load_img(&core->textures->img_east, "tmp_assets/MWALL4_2.xpm", core))
		return (false);
	core->textures->img_west = gc_malloc(&core->gc,
			sizeof(t_img), STRUCT, "textu");
	if (!core->textures->img_west)
		return (false);
	if (!load_img(&core->textures->img_west, "tmp_assets/MWALL5_1.xpm", core))
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
