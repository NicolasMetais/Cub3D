/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_weapons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:05:18 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/31 14:46:38 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	render_weapon(t_core *core)
{

	if (!core->player->weapon[core->player->current_weapon].lock)
	{
		transparency(core->game_img, core->player->weapon[core->player->current_weapon].normal,((S_LENGHT - core->player->weapon[core->player->current_weapon].normal->width) / 2) + core->player->bob_x, (S_HEIGHT - 150 - core->player->weapon[core->player->current_weapon].normal->height) + core->player->bob_y);
	}
	else
		transparency(core->game_img, core->player->weapon[core->player->current_weapon].fire->img_list->image, ((S_LENGHT - core->player->weapon[core->player->current_weapon].fire->img_list->image->width) / 2) + core->player->bob_x, (S_HEIGHT - 150 - core->player->weapon[core->player->current_weapon].fire->img_list->image->height) + core->player->bob_y);
	return (true);
}

