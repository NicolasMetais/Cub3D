/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:03:55 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/02 01:11:54 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_img(t_core *core)
{
	if (core->menu_img->bg->img)
		mlx_destroy_image(core->mlx, core->menu_img->bg->img);
	if (core->menu_img->options->img)
		mlx_destroy_image(core->mlx, core->menu_img->options->img);
	if (core->menu_img->options->img)
		mlx_destroy_image(core->mlx, core->menu_img->play->img);
	if (core->menu_img->maps->img)
		mlx_destroy_image(core->mlx, core->menu_img->maps->img);
	if (core->menu_img->quit->img)
		mlx_destroy_image(core->mlx, core->menu_img->quit->img);
	if (core->menu_img->skulls->sprites[0]->img)
		mlx_destroy_image(core->mlx, core->menu_img->skulls->sprites[0]->img);
	if (core->menu_img->skulls->sprites[1]->img)
		mlx_destroy_image(core->mlx, core->menu_img->skulls->sprites[1]->img);
	if (core->menu_img->option1->img)
		mlx_destroy_image(core->mlx, core->menu_img->option1->img);
	if (core->menu_img->option2->img)
		mlx_destroy_image(core->mlx, core->menu_img->option2->img);
	if (core->fonts->big_img->img)
		mlx_destroy_image(core->mlx, core->fonts->big_img->img);
	if (core->fonts->regular_img->img)
		mlx_destroy_image(core->mlx, core->fonts->regular_img->img);
	if (core->fonts->small_img->img)
		mlx_destroy_image(core->mlx, core->fonts->small_img->img);
	if (core->menu_img->option_win->img)
		mlx_destroy_image(core->mlx, core->menu_img->option_win->img);
}
