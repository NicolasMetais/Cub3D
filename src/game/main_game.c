/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:44:46 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/02 04:11:55 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//INIT IMAGES
bool	img_init(t_core *core)
{
	t_menu_img			*img;
	t_fonts				*fonts;


	core->fonts = gc_malloc(&core->gc, sizeof(t_fonts), STRUCT, "fonts");
	if (!core->fonts)
		return (false);
	init_chars_nodes(core);
	core->menu_img = gc_malloc(&core->gc, sizeof(t_menu_img),
			STRUCT, "menu img");
	if (!core->menu_img)
		return (false);
	img = core->menu_img;
	fonts = core->fonts;
	if (!init_menu_img(core))
		return (false);
	if (!init_words_img(core))
		return (false);
	return (true);
}

//GAME LAUNCH
bool	launch_game(t_core *core)
{
	if (!img_init(core))
		return (false);
	start_menu(core);
	mlx_key_hook(core->win, handle_keypress, core);
	mlx_loop_hook(core->mlx, routine, core);
	mlx_loop(core->mlx);
	return (true);
}
