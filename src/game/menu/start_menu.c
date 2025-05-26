/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 04:04:48 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/15 13:02:43 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//INIT SKULLS SPRITES
t_sprite	*create_skull_sprite(t_core *core)
{
	t_sprite	*skull;

	skull = gc_malloc(&core->gc, sizeof(t_sprite), STRUCT, "skull sprite");
	if (!skull)
		return (NULL);
	skull->nb = 2;
	skull->sprites = gc_malloc(&core->gc, sizeof(t_img *) * skull->nb,
			STRUCT, "skull sprite");
	if (!skull->sprites)
		return (NULL);
	skull->sprites[0] = hashmap_get(&core->hashmap, "Skull1");
	skull->sprites[1] = hashmap_get(&core->hashmap, "Skull2");
	skull->frame = 0;
	skull->timer = 0;
	skull->speed = 2000;
	return (skull);
}

//Core menu function
bool	start_menu(t_core *core)
{
	t_img	*logo;

	logo = hashmap_get(&core->hashmap, "Logo");
	core->menu_img->skulls = create_skull_sprite(core);
	transparency(core->menu_img->bg_clean, logo, 544, 260);
	render_menu(core);
	return (true);
}
