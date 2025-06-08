/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:25:17 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/08 19:11:09 by nmetais          ###   ########.fr       */
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

	play = (t_img *)hashmap_get(&core->hashmap, "Menu_play");
	options = (t_img *)hashmap_get(&core->hashmap, "Menu_options");
	maps = (t_img *)hashmap_get(&core->hashmap, "Menu_maps");
	quit = (t_img *)hashmap_get(&core->hashmap, "Menu_quit");
	if (!play || !options || !maps ||!quit)
		return ;
	transparency(bg, play, (bg->width / 2) - 100, y[0]);
	transparency(bg, options, (bg->width / 2) - 100, y[1]);
	transparency(bg, maps, (bg->width / 2) - 100, y[2]);
	transparency(bg, quit, (bg->width / 2) - 100, y[3]);
}

//PRINT SKULL AT THE RIGHT PLACE
void	skulls_render(t_core *core, const int *y)
{
	int			x;
	t_sprite	*skulls;

	x = (core->menu_img->bg->width / 2) - 100;
	if (core->state == MAPS_MENU)
	{
		skulls = hashmap_get(&core->hashmap_sprites, "skulls");
		if (!skulls)
			return ;
		transparency(core->menu_img->bg, skulls->img_list->image,
			x - (skulls->img_list->image->width + 10),
			y[core->menu_option - core->scroll_offset]);
	}
	else if (core->state == START_MENU)
	{
		skulls = hashmap_get(&core->hashmap_sprites, "skulls");
		if (!skulls)
			return ;
		transparency(core->menu_img->bg, skulls->img_list->image,
			x - (skulls->img_list->image->width + 10),
			y[core->menu_option]);
	}
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

//INIT Y POS
static void	start_menu_init(t_core *core)
{
	int	i;

	i = -1;
	while (++i < 4)
		core->y_pos[i] = 540 + (i * MENU_SPACING);
}

//MENU RENDERING EVERYTIME I DO A MOVEMENT IN THE MENU
bool	render_menu(t_core *core)
{
	start_menu_init(core);
	copy_img(core->menu_img->bg, core->menu_img->bg_clean);
	rewrite_options(core, core->y_pos, core->menu_img->bg);
	skulls_render(core, core->y_pos);
	loaded_map(core->menu_img->bg, core);
	core->redraw = false;
	return (true);
}
