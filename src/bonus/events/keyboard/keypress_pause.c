/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_pause.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:08:30 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/13 02:16:45 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	change_color(int color, float ratio)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = (int)(r * ratio);
	g = (int)(g * ratio);
	b = (int)(b * ratio);
	return ((r << 16) | (g << 8) | b);
}

void	d4rk_img(t_img *img, float ratio)
{
	int	x;
	int	y;
	int	color;
	int	new_color;

	y = -1;
	while (y++ < img->height)
	{
		x = -1;
		while (x++ < img->width)
		{
			color = get_img_pxl(img, x, y);
			new_color = change_color(color, ratio);
			put_on_bg(img, y, x, new_color);
		}
	}
}

bool	create_pause_bg(t_core *core)
{
	copy_img(core->hud_img->clean_pause_buffer, core->game_img);
	transparency(core->hud_img->clean_pause_buffer, core->hud_img->hud,
		0, 840);
	transparency(core->hud_img->clean_pause_buffer, core->hud_img->ammo1,
		1380, 865);
	transparency(core->hud_img->clean_pause_buffer, core->hud_img->ammo2,
		1380, 895);
	transparency(core->hud_img->clean_pause_buffer, core->hud_img->ammo3,
		1380, 925);
	transparency(core->hud_img->clean_pause_buffer, core->hud_img->ammo4,
		1380, 955);
	d4rk_img(core->hud_img->clean_pause_buffer, 0.2);
	core->menu_option = 0;
	core->state = PAUSE;
	return (true);
}

void	enter_pause_handler(int key, t_core *core)
{
	if (key == XK_Return)
	{
		if (core->menu_option == 0)
		{
			core->menu_option = 0;
			core->state = GAME;
		}
		if (core->menu_option == 1)
		{
			core->menu_option = 0;
			render_pause_options(core);
		}
		if (core->menu_option == 2)
			cleanup_game(core);
	}
}

//PAUSE MENU
void	pause_menu_keypress(int key, t_core *core)
{
	if (!core->enter)
	{
		core->enter = 1;
		return ;
	}
	if (key == XK_Up)
	{
		if (core->menu_option > 0)
			core->menu_option--;
		else
			core->menu_option = 2;
		render_pause_menu(core);
	}
	else if (key == XK_Down)
	{
		if (core->menu_option < 2)
			core->menu_option++;
		else
			core->menu_option = 0;
		render_pause_menu(core);
	}
	enter_pause_handler(key, core);
}
