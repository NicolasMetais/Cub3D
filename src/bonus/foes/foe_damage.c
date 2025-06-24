/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_damage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:40:38 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/24 18:14:43 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	damage_deal(t_core *core, t_foes *enemy)
{
	if (!IsSoundPlaying(core->sound_list.player_injured) && !core->godmod)
		PlaySound(core->sound_list.player_injured);
	if (core->player->armor > 0 && core->godmod == 0)
		core->player->armor -= enemy->damage;
	else if (core->godmod == 0)
		core->player->health -= enemy->damage;
	if (core->player->armor < 0)
		core->player->armor = 0;
}
