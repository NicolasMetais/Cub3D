/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:03:55 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/28 05:43:05 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_img(t_core *core)
{
	if (core->menu_img->bg->img)
		mlx_destroy_image(core->mlx, core->menu_img->bg->img);
	if (core->menu_img->play->img)
		mlx_destroy_image(core->mlx, core->menu_img->play->img);
	if (core->menu_img->options->img)
		mlx_destroy_image(core->mlx, core->menu_img->options->img);
	if (core->menu_img->maps->img)
		mlx_destroy_image(core->mlx, core->menu_img->maps->img);
	if (core->menu_img->quit->img)
		mlx_destroy_image(core->mlx, core->menu_img->quit->img);
	if (core->menu_img->skulls_left->img)
		mlx_destroy_image(core->mlx, core->menu_img->skulls_left->img);
	if (core->menu_img->skulls_right->img)
		mlx_destroy_image(core->mlx, core->menu_img->skulls_right->img);
}
