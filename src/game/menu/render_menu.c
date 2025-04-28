/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:25:17 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/28 05:54:27 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rewrite_options(t_core *core, const int *y, int *i)
{
	t_menu_img	*menu;

	menu = core->menu_img;
	if (*i == 0)
		transparency(menu->bg, menu->play,
			(menu->bg->width / 2) - (menu->play->width / 2), y[*i]);
	else if (*i == 1)
		transparency(menu->bg, menu->options,
			(menu->bg->width / 2) - (menu->options->width / 2), y[*i]);
	else if (*i == 2)
		transparency(menu->bg, menu->maps,
			(menu->bg->width / 2) - (menu->maps->width / 2), y[*i]);
	else if (*i == 3)
		transparency(menu->bg, menu->quit,
			(menu->bg->width / 2) - (menu->quit->width / 2), y[*i]);
}

void	skulls_render(t_core *core, const int *y)
{
	int			x;
	int			offset;
	t_menu_img	*menu;

	menu = core->menu_img;
	offset = menu->skulls_left->width;
	x = (menu->bg->width / 2) - (menu->play->width / 2);
	transparency(core->menu_img->bg->img, core->menu_img->skulls_left->img,
		x - (offset + 200), y[core->menu_option]);
	//printf("RENDER : %p\n", core->menu_img->skulls->img);
	transparency(core->menu_img->bg->img, core->menu_img->skulls_right->img,
		x + (offset + 200), y[core->menu_option]);
	//printf("RENDER : %p\n", core->menu_img->skulls->img);
}

bool	render_menu(t_core *core)
{
	int			i;
	const int	y[] = {MENU_START_Y + (0 * MENU_SPACING),
		MENU_START_Y + (1 * MENU_SPACING),
		MENU_START_Y + (2 * MENU_SPACING),
		MENU_START_Y + (3 * MENU_SPACING)};

	i = -1;
	while (++i < 4)
	{
		// if (i == core->menu_option)
		// 	(void)i;
		// else
		rewrite_options(core, y, &i);
	}
	skulls_render(core, y);
	mlx_put_image_to_window(core->mlx, core->win,
		core->menu_img->bg->img, 0, 0);
	return (true);
}
