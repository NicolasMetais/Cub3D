/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:47:38 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/06 15:12:51 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_click_game(t_core *core, int button)
{
	t_sprite	*anim;
	t_sprite	*fire;
	t_weapon	*weapon;

	if (button == 1)
	{
		weapon = &core->player->weapon[core->player->curr_wpn];
		if ((core->player->ammo[weapon->ammo_type] > 0 && !weapon->lock)
			|| core->player->curr_wpn <= 1)
		{
			anim = weapon->anim;
			fire = weapon->fire;
			weapon->lock = true;
			anim->activ = true;
			anim->started = true;
			gettimeofday(&anim->update, NULL);
			if (core->player->curr_wpn == 4 || core->player->curr_wpn == 6)
				core->player->firing = true;
			weapon_fired(core);
		}
	}
}
