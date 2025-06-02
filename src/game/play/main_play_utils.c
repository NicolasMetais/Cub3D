/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_play_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:33:47 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/02 17:54:35 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	*set_img(t_core *core, char *xpm_path)
// {
// 	void	*img;

// 	img = mlx_xpm_file_to_image(core->mlx, xpm_path, \
// 					128, 128);
// 	if (!img)
// 		return ;
// 	return (img);
// }

void    init_map_textures(t_core *core)
{
    core->textures->path_sky = "/tmp_assets/SKY3.xpm";
    core->textures->sky = (t_img *)hashmap_get(&core->hashmap, "Sky");
    core->textures->tmp_north = (t_img *)hashmap_get(&core->hashmap, "Wall_north");
    core->textures->tmp_south = (t_img *)hashmap_get(&core->hashmap, "Wall_south");
    core->textures->tmp_east = (t_img *)hashmap_get(&core->hashmap, "Wall_east");
    core->textures->tmp_west = (t_img *)hashmap_get(&core->hashmap, "Wall_west");
}

void    rays_updates(t_core *core)
{
    core->tmp_rc->r++;
    core->tmp_rc->ra += RAD / (core->tmp_rc->max_r / core->fov);
    if (core->tmp_rc->ra < 0)
        core->tmp_rc->ra += 2 * PI;
    if (core->tmp_rc->ra > 2 * PI)
        core->tmp_rc->ra -= 2 * PI;   
}
