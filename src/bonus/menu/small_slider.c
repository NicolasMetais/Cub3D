/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_slider.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 23:31:08 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/15 17:50:12 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	slider_assembler(t_img *slider_small, t_img *corner_left,
			t_img *corner_right)
{
	int	i;
	int	px_start;

	i = -1;
	px_start = 0;
	fill_img_in_green(slider_small);
	while (++i < 2)
	{
		if (i == 0)
		{
			slider_copy_pxl(slider_small, corner_left, px_start);
			px_start += corner_left->width;
		}
		else if (1)
		{
			slider_copy_pxl(slider_small, corner_right, px_start);
			px_start += corner_right->width;
		}
	}
}

bool	small_slider_constructor(t_core *core)
{
	t_img		*corner_left;
	t_img		*corner_right;
	t_menu_img	*menu;
	int			width;

	menu = core->menu_img;
	corner_left = (t_img *)hashmap_get(&core->hashmap, "Slider_left");
	corner_right = (t_img *)hashmap_get(&core->hashmap, "Slider_right");
	width = corner_left->width * 2;
	menu->slider_small->img = mlx_new_image(core->mlx,
			width, corner_left->height);
	if (!menu->slider_small->img)
		return (false);
	menu->slider_small->width = width;
	menu->slider_small->height = corner_left->height;
	menu->slider_small->addr = mlx_get_data_addr(menu->slider_small->img,
			&menu->slider_small->bpp, &menu->slider_small->line_len,
			&menu->slider_small->endian);
	slider_assembler(menu->slider_small, corner_left, corner_right);
	hashmap_insert(&core->hashmap, "slider_small", menu->slider_small, core);
	return (true);
}
