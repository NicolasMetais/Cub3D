/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:25:17 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/05 18:43:23 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//REWRITE ALL MENU OPTIONS
static void	rewrite_options(t_core *core, const int *y, t_img *bg)
{
	t_img	*play;
	t_img	*options;
	t_img	*maps;
	t_img	*quit;

	play = hashmap_get(&core->hashmap, "Menu_play");
	options = hashmap_get(&core->hashmap, "Menu_options");
	maps = hashmap_get(&core->hashmap, "Menu_maps");
	quit = hashmap_get(&core->hashmap, "Menu_quit");
	transparency(bg, play, (bg->width / 2) - (play->width / 2), y[0]);
	transparency(bg, options, (bg->width / 2) - (options->width / 2), y[1]);
	transparency(bg, maps, (bg->width / 2) - (maps->width / 2), y[2]);
	transparency(bg, quit, (bg->width / 2) - (quit->width / 2), y[3]);
}

//PRINT SKULL AT THE RIGHT PLACE
void	skulls_render(t_core *core, const int *y, int frame)
{
	int			x;
	t_img		*selected;

	selected = NULL;
	if (core->menu_option == 0)
		selected = hashmap_get(&core->hashmap, "Menu_play");
	else if (core->menu_option == 1)
		selected = hashmap_get(&core->hashmap, "Menu_options");
	else if (core->menu_option == 2)
		selected = hashmap_get(&core->hashmap, "Menu_maps");
	else if (core->menu_option == 3)
		selected = hashmap_get(&core->hashmap, "Menu_quit");
	x = (core->menu_img->bg->width / 2) - (selected->width / 2);
	transparency(core->menu_img->bg, core->menu_img->skulls->sprites[frame],
		x - (core->menu_img->skulls->sprites[frame]->width + 10),
		y[core->menu_option]);
	transparency(core->menu_img->bg, core->menu_img->skulls->sprites[frame],
		x + (selected->width + 10), y[core->menu_option]);
	mlx_put_image_to_window(core->mlx, core->win, core->menu_img->bg->img,
		0, 0);
}

//TEMPORAIRE
void	skulls_render_tempo(t_core *core, const int *y, int frame)
{
	int			x;
	t_img		*selected;
	t_img		*submenu;

	submenu = hashmap_get(&core->hashmap, "Submenu_option");
	selected = NULL;
	if (core->menu_option == 0)
		selected = hashmap_get(&core->hashmap, "Menu_option1");
	else if (core->menu_option == 1)
		selected = hashmap_get(&core->hashmap, "Menu_option2");
	x = selected->width;
	transparency(core->menu_img->bg, core->menu_img->skulls->sprites[frame],
		x - (core->menu_img->skulls->sprites[frame]->width + 10),
		y[core->menu_option]);
	transparency(core->menu_img->bg, core->menu_img->skulls->sprites[frame],
		x + (selected->width + 10), y[core->menu_option]);
	mlx_put_image_to_window(core->mlx, core->win, core->menu_img->bg->img,
		0, 0);
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
	t_img		*bg;
	t_img		*bg_clean;

	bg_clean = hashmap_get(&core->hashmap, "Menu_bg_clean");
	bg = hashmap_get(&core->hashmap, "Menu_bg_activ");
	copy_img(bg, bg_clean);
	rewrite_options(core, core->y_pos, bg);
	skulls_render(core, core->y_pos, core->menu_img->skulls->frame);
	core->redraw = false;
	return (true);
}
