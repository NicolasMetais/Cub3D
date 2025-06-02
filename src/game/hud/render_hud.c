/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:11:40 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/02 12:54:32 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	render_hud(t_core *core)
{
	render_numbers(core);
	render_ammo(core);
	render_weapon_menu(core);
	render_head(core);
	mlx_put_image_to_window(core->mlx, core->win, core->hud_img->hud->img,
		0, 840);
	core->hud_redraw = false;
	return (true);
}
