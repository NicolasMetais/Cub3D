/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 04:04:48 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/30 00:02:22 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//INIT SKULLS SPRITES
t_sprite	*create_skull_sprite(t_core *core)
{
	t_sprite	*skulls;

	skulls = hashmap_get(&core->hashmap_sprites, "skulls");
	skulls->timer = 0;
	skulls->speed = 2000;
	return (skulls);
}

//Core menu function
bool	start_menu(t_core *core)
{
	t_img	*logo;

	logo = (t_img *)hashmap_get(&core->hashmap, "Logo");
	core->menu_img->skulls = create_skull_sprite(core);
	transparency(core->menu_img->bg_clean, logo, 544, 260);
	render_menu(core);
	return (true);
}
