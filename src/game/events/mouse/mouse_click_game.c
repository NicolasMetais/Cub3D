/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:47:38 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/01 16:07:22 by nmetais          ###   ########.fr       */
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
		weapon = &core->player->weapon[core->player->current_weapon];
		if (!weapon->lock)
		{
			anim = weapon->anim;
			fire = weapon->fire;
			weapon->lock = true;
			anim->activ = true;
			anim->started = true;
			gettimeofday(&anim->update, NULL);
			if (fire)
			{
				fire->activ = true;
				fire->started = true;
				gettimeofday(&fire->update, NULL);
			}
			weapon->fired = true;
			weapon->freeze = true;
			gettimeofday(&weapon->freeze_start, NULL);
		}
	}
}
