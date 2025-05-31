/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:47:38 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/31 20:51:40 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_click_game(t_core *core, int button)
{
	t_sprite	*sprite;

	if (button == 1)
	{
		if (!core->player->weapon[core->player->current_weapon].lock)
		{
			sprite = core->player->weapon[core->player->current_weapon].anim;
			core->player->weapon[core->player->current_weapon].lock = true;
			sprite->activ = true;
			sprite->started = true;
			gettimeofday(&sprite->update, NULL);
		}

	}
}
