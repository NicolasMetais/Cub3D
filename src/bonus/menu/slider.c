/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slider.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:39:58 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/15 00:13:22 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	slider_copy_pxl(t_img *slider_bar, t_img *tocopy, int px_start)
{
	int				x;
	int				y;
	unsigned int	pixel;
	int				count;

	pixel = 0;
	count = 0;
	y = 0;
	while (y < tocopy->height)
	{
		x = 0;
		while (x < tocopy->width)
		{
			pixel = get_img_pxl(tocopy, x, y);
			put_on_bg(slider_bar, y, px_start + x, pixel);
			x++;
		}
		y++;
	}
}

static void	slider_assembler(t_img *slider_bar, t_img *corner_left,
			t_img *corner_right, t_img *slider)
{
	int	i;
	int	px_start;

	i = -1;
	px_start = 0;
	fill_img_in_green(slider_bar);
	while (++i < SLIDER_SIZE + 2)
	{
		if (i == 0)
		{
			slider_copy_pxl(slider_bar, corner_left, px_start);
			px_start += corner_left->width;
		}
		else if (i > 0 && i < SLIDER_SIZE - 1)
		{
			slider_copy_pxl(slider_bar, slider, px_start);
			px_start += slider->width;
		}
		else if (i == SLIDER_SIZE - 1)
		{
			slider_copy_pxl(slider_bar, corner_right, px_start);
			px_start += corner_right->width;
		}
	}
}

bool	slider_constructor(t_core *core, int width)
{
	t_img		*corner_left;
	t_img		*corner_right;
	t_img		*slider;
	t_menu_img	*menu;
	int			height;

	menu = core->menu_img;
	corner_left = (t_img *)hashmap_get(&core->hashmap, "Slider_left");
	slider = (t_img *)hashmap_get(&core->hashmap, "Slider");
	corner_right = (t_img *)hashmap_get(&core->hashmap, "Slider_right");
	if (!corner_left || !corner_right || !slider)
		return (false);
	width = corner_left->width * 2 + slider->width * SLIDER_SIZE;
	height = slider->height;
	menu->slider_bar->img = mlx_new_image(core->mlx, width, height);
	if (!menu->slider_bar->img)
		return (false);
	menu->slider_bar->width = width;
	menu->slider_bar->height = height;
	menu->slider_bar->addr = mlx_get_data_addr(menu->slider_bar->img,
			&menu->slider_bar->bpp, &menu->slider_bar->line_len,
			&menu->slider_bar->endian);
	slider_assembler(menu->slider_bar, corner_left, corner_right, slider);
	hashmap_insert(&core->hashmap, "slider_bar", menu->slider_bar, core);
	return (true);
}
