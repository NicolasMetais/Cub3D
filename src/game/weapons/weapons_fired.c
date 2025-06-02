/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_fired.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:18:48 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/02 22:57:26 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	weapon_fired(t_core *core)
{
	int	ammo_index;

	ammo_index = core->player->weapon[core->player->current_weapon].ammo_type;
	if (core->player->ammo[ammo_index] > 0)
		core->player->ammo[ammo_index] -= 1;
}
