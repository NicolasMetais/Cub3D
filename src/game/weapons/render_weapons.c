/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_weapons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:05:18 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/02 13:08:13 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	render_weapon(t_core *core)
{
	int			offset_y;
	int			offset_x;
	t_weapon	weapon;

	weapon = core->player->weapon[core->player->current_weapon];
	fill_img_in_green(core->weapon_buffer);
	if (!core->player->weapon[core->player->current_weapon].lock)
	{
		offset_x = (core->weapon_buffer->width - weapon.normal->width) / 2;
		offset_y = core->weapon_buffer->height - weapon.normal->height;
		transparency(core->weapon_buffer, weapon.normal, offset_x + core->player->bob_x, offset_y + core->player->bob_y);
	}
	else
	{
		offset_x = (core->weapon_buffer->width
				- weapon.anim->img_list->image->width) / 2;
		offset_y = core->weapon_buffer->height
			- weapon.anim->img_list->image->height;
		transparency(core->weapon_buffer, weapon.anim->img_list->image,
			offset_x, offset_y);
	}
	transparency(core->game_img, core->weapon_buffer,
		(core->game_img->width - core->weapon_buffer->width) / 2,
		core->game_img->height - (core->weapon_buffer->height + 150));
	return (true);
}

