/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 04:04:48 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/29 04:53:50 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//I'm hiding this because it suck and i don't like it 
void	menu_init(t_core *core)
{
	core->y_pos[0] = MENU_START_Y + (0 * MENU_SPACING);
	core->y_pos[1] = MENU_START_Y + (1 * MENU_SPACING);
	core->y_pos[2] = MENU_START_Y + (2 * MENU_SPACING);
	core->y_pos[3] = MENU_START_Y + (3 * MENU_SPACING);
}

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
	if (!load_image(&skull->sprites[0], core->mlx,
			"menu/skull_sprite1.xpm", core))
		return (NULL);
	if (!load_image(&skull->sprites[1], core->mlx,
			"menu/skull_sprite2.xpm", core))
		return (NULL);
	skull->frame = 0;
	skull->timer = 0;
	skull->speed = 100;
	return (skull);
}

bool	start_menu(t_core *core)
{
	menu_init(core);
	core->menu_img->skulls = create_skull_sprite(core);
	mlx_hook(core->win, 6, (1L << 6), mouse_menu_hover, core);
	mlx_hook(core->win, 4, (1L << 2), mouse_menu_click, core);

	return (true);
}
