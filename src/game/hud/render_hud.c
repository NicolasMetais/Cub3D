/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:11:40 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/02 22:45:44 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	render_hud(t_core *core)
{
	if (core->hud_img->new_weapon_render)
		render_weapon_menu(core);
	render_head(core);
	mlx_put_image_to_window(core->mlx, core->win, core->hud_img->hud->img,
		0, 840);
	if (!render_numbers(core))
		return (false);
	render_ammo(core);
	core->hud_redraw = false;
	return (true);
}
