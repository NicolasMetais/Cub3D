/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:25:17 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/01 21:42:31 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//REWRITE ALL MENU OPTIONS
static void	rewrite_options(t_core *core, const int *y, int i)
{
	t_menu_img	*menu;

	menu = core->menu_img;
	if (i == 0)
		transparency(menu->bg, menu->play,
			(menu->bg->width / 2) - (menu->play->width / 2), y[i]);
	if (i == 1)
		transparency(menu->bg, menu->options,
			(menu->bg->width / 2) - (menu->options->width / 2), y[i]);
	else if (i == 2)
		transparency(menu->bg, menu->maps,
			(menu->bg->width / 2) - (menu->maps->width / 2), y[i]);
	else if (i == 3)
		transparency(menu->bg, menu->quit,
			(menu->bg->width / 2) - (menu->quit->width / 2), y[i]);
}

//PRINT SKULL AT THE RIGHT PLACE
void	skulls_render(t_core *core, const int *y, int frame)
{
	int			x;
	t_menu_img	*menu;
	t_img		*selected;

	selected = NULL;
	menu = core->menu_img;
	if (core->menu_option == 0)
		selected = menu->play;
	else if (core->menu_option == 1)
		selected = menu->options;
	else if (core->menu_option == 2)
		selected = menu->maps;
	else if (core->menu_option == 3)
		selected = menu->quit;
	x = (menu->bg->width / 2) - (selected->width / 2);
	transparency(menu->bg, menu->skulls->sprites[frame],
		x - (menu->skulls->sprites[frame]->width + 10), y[core->menu_option]);
	transparency(menu->bg, menu->skulls->sprites[frame],
		x + (selected->width + 10), y[core->menu_option]);
	mlx_put_image_to_window(core->mlx, core->win,
		core->menu_img->bg->img, 0, 0);
}

//LOAD A NEW BG IMAGE AT EVERY RENDER CALL
bool	load_bg_image(t_img **img, void *mlx, char *path, t_core *core)
{
	*img = gc_malloc(&core->gc, sizeof(t_img), STRUCT, "bg_img");
	if (!*img)
		return (false);
	(*img)->img = mlx_xpm_file_to_image(mlx, path, &(*img)->width,
			&(*img)->height);
	if (!(*img)->img)
		return (ft_putendl_fd("Error \n Menu images corrupted", 2), false);
	(*img)->addr = mlx_get_data_addr((*img)->img, &(*img)->bpp,
			&(*img)->line_len, &(*img)->endian);
	return (true);
}

//MENU RENDERING EVERYTIME I DO A MOVEMENT IN THE MENU
bool	render_menu(t_core *core)
{
	int			i;

	i = -1;
	if (core->menu_img->bg->img)
		mlx_destroy_image(core->mlx, core->menu_img->bg->img);
	free_gc(core->gc, "bg_img");
	if (!load_bg_image(&core->menu_img->bg, core->mlx, "menu/bg.xpm", core))
		return (false);
	while (++i < 4)
		rewrite_options(core, core->y_pos, i);
	skulls_render(core, core->y_pos, core->menu_img->skulls->frame);
	core->redraw = false;
	return (true);
}
