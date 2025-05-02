/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_options_menu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:19:51 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/30 21:27:35 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rewrite_options(t_core *core, int i)
{
	t_menu_img	*menu;
	const int	y_pos[2] = {
		MENU_START_Y + (0 * MENU_SPACING),
		MENU_START_Y + (1 * MENU_SPACING)
	};

	menu = core->menu_img;
	if (i == 0)
		transparency(menu->bg, menu->option1,
			(menu->bg->width / 4), y_pos[i]);
	else if (i == 1)
		transparency(menu->bg,  menu->option2,
			(menu->bg->width / 4) , y_pos[i]);
}

bool	render_options_menu(t_core *core)
{
	int	i;

	i = -1;
	transparency(core->menu_img->bg, core->menu_img->option_win, 300, 120);
	while (++i < 4)
		rewrite_options(core, i);
	mlx_put_image_to_window(core->mlx, core->win, core->menu_img->bg->img,
		0, 0);
	return (true);
}
