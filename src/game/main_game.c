/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:44:46 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/28 05:52:43 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	load_image(t_img **img, void *mlx, char *path, t_core *core)
{
	*img = gc_malloc(&core->gc, sizeof(t_img), STRUCT, "image du menu");
	if (!*img)
		return (false);
	(*img)->img = mlx_xpm_file_to_image(mlx, path, &(*img)->width,
			&(*img)->height);
	if (!(*img)->img)
		return (false);
	(*img)->addr = mlx_get_data_addr((*img)->img, &(*img)->bpp,
			&(*img)->line_len, &(*img)->endian);
	return (true);
}

bool	img_init(t_core *core)
{
	t_menu_img	*img;

	core->menu_img = gc_malloc(&core->gc, sizeof(t_menu_img),
			STRUCT, "menu img");
	if (!core->menu_img)
		return (false);
	img = core->menu_img;
	if (!load_image(&img->skulls_left, core->mlx, "menu/big_skull.xpm", core))
		return (false);
	if (!load_image(&img->skulls_right, core->mlx, "menu/big_skull.xpm", core))
		return (false);
	if (!load_image(&img->bg, core->mlx, "menu/bg.xpm", core))
		return (false);
	if (!load_image(&img->play, core->mlx, "menu/Play.xpm", core))
		return (false);
	if (!load_image(&img->options, core->mlx, "menu/Options.xpm", core))
		return (false);
	if (!load_image(&img->maps, core->mlx, "menu/Maps.xpm", core))
		return (false);
	if (!load_image(&img->quit, core->mlx, "menu/Death.xpm", core))
		return (false);
	if (!img->play || !img->options || !img->maps
		|| !img->quit || !img->bg)
		return (ft_putendl_fd("Error \n Menu images corrupted", 2), false);
	return (true);
}

bool	launch_game(t_core *core)
{
	if(!img_init(core))
		return (false);
	//print_allocated_vars(core->gc, NULL);
	mlx_key_hook(core->win, handle_keypress, core);
	mlx_loop_hook(core->mlx, routine, core);
	mlx_loop(core->mlx);
	return (true);
}
