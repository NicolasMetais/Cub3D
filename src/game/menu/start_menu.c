/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 04:04:48 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/05 17:30:31 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//INIT Y POS
void	menu_init(t_core *core)
{
	core->y_pos[0] = MENU_START_Y + (0 * MENU_SPACING);
	core->y_pos[1] = MENU_START_Y + (1 * MENU_SPACING);
	core->y_pos[2] = MENU_START_Y + (2 * MENU_SPACING);
	core->y_pos[3] = MENU_START_Y + (3 * MENU_SPACING);
}

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
	menu_init(core);
	core->menu_img->skulls = create_skull_sprite(core);
	render_menu(core);
	mlx_hook(core->win, 6, (1L << 6), mouse_menu_hover, core);
	mlx_hook(core->win, 4, (1L << 2), mouse_menu_click, core);
	return (true);
}
