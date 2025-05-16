/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_options_menu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:19:51 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/16 18:04:42 by nmetais          ###   ########.fr       */
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

void	slider_assembler(t_img *slider_bar, t_img *corner_left,
			t_img *corner_right, t_img *slider)
{
	int	i;
	int	px_start;

	i = -1;
	px_start = 0;
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
	corner_left = hashmap_get(&core->hashmap, "Slider_left");
	slider = hashmap_get(&core->hashmap, "Slider");
	corner_right = hashmap_get(&core->hashmap, "Slider_right");
	width = corner_left->width * 2 + slider->width * SLIDER_SIZE;
	height = slider->height;
	menu->slider_bar->img = mlx_new_image(core->mlx, width, height);
	if (!menu->slider_bar)
		return (false);
	menu->slider_bar->width = width;
	menu->slider_bar->height = height;
	menu->slider_bar->addr = mlx_get_data_addr(menu->slider_bar->img,
			&menu->slider_bar->bpp, &menu->slider_bar->line_len,
			&menu->slider_bar->endian);
	fill_img_in_green(&menu->slider_bar);
	slider_assembler(menu->slider_bar, corner_left, corner_right, slider);
	hashmap_insert(&core->hashmap, "slider_bar", menu->slider_bar, core);
	return (true);
}

void	skulls_render_options(t_core *core, const int *y, int frame)
{
	int			x;

	x = (core->menu_img->bg->width / 2) - 100;
	transparency(core->menu_img->bg, core->menu_img->skulls->sprites[frame],
		x - (core->menu_img->skulls->sprites[frame]->width + 10),
		y[core->menu_option]);
	mlx_put_image_to_window(core->mlx, core->win, core->menu_img->bg->img,
		0, 0);
}

void	update_slider(t_core *core, const int *y, t_img *bg)
{
	transparency(bg, core->menu_img->slider_bar, (bg->width / 2) - 70, y[0]);
	transparency(bg, core->menu_img->slider_bar, (bg->width / 2) - 70, y[0]);
	transparency(bg, core->menu_img->cursor, core->x, y[0] + 5);
}

static void	rewrite_options(t_core *core, const int *y, t_img *bg)
{
	t_img		*option1;

	option1 = hashmap_get(&core->hashmap, "Option_fov");
	transparency(bg, option1, (bg->width / 3), y[0] + 10);
	update_slider(core, y, bg);
	//skulls_render_options(core, y, core->menu_img->skulls->frame);
}

static void	option_menu_init(t_core *core)
{
	int	i;

	i = -1;
	while (++i < 1)
		core->y_pos[i] = 650 + (i * MENU_SPACING);
}

bool	render_options_menu(t_core *core)
{
	t_img	*option;

	core->state = OPTIONS_MENU;
	option_menu_init(core);
	copy_img(core->menu_img->bg, core->menu_img->bg_clean);
	option = hashmap_get(&core->hashmap, "Option_title");
	transparency(core->menu_img->bg, option, 545, 440);
	rewrite_options(core, core->y_pos, core->menu_img->bg);
	mlx_put_image_to_window(core->mlx, core->win, core->menu_img->bg->img,
		0, 0);
	return (true);
}
