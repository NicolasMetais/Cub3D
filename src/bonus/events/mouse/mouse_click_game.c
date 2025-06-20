/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:47:38 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/18 20:34:12 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_scroll_game(t_core *core, int x, int y)
{
	int	offset;

	mlx_mouse_get_pos(core->mlx, core->win, &x, &y);
	if (x > 0 && x < core->scroll_ingame)
		offset = -1;
	else if (x > core->scroll_ingame && x < S_LENGHT)
		offset = 1;
	else
		offset = 0;
	if (x < 100)
		mlx_mouse_move(core->mlx, core->win, S_LENGHT -100, S_HEIGHT / 2);
	if (x > S_LENGHT - 100)
		mlx_mouse_move(core->mlx, core->win, 100, S_HEIGHT / 2);
	core->tmp_rc->pl_angle += 0.05 * offset;
	if (core->tmp_rc->pl_angle > 2 * PI)
		core->tmp_rc->pl_angle -= 2 * PI;
	if (core->tmp_rc->pl_angle < 0)
		core->tmp_rc->pl_angle += 2 * PI;
	core->tmp_rc->pldelt_x = cos(core->tmp_rc->pl_angle);
	core->tmp_rc->pldelt_y = sin(core->tmp_rc->pl_angle);
	core->scroll_ingame = x;
}

void	mouse_click_game(t_core *core, int button)
{
	t_sprite	*anim;
	t_sprite	*fire;
	t_weapon	*weapon;

	if (button == 1)
	{
		weapon = &core->player->weapon[core->player->curr_wpn];
		if (core->player->curr_wpn == 0 || core->player->curr_wpn == 1)
			play_sound(core,
				core->player->weapon[core->player->curr_wpn].firing);
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
