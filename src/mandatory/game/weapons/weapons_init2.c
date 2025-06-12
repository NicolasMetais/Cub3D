/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_init2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:15:56 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/12 20:38:04 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


bool	weapons_init_five(t_weapon weapon[9], t_core *core)
{
	weapon[6].normal = hashmap_get(&core->hashmap, "PLSGA0");
	if (!weapon[6].normal)
		return (false);
	weapon[6].anim = hashmap_get(&core->hashmap_sprites, "plasmarifle");
	if (!weapon[6].anim)
		return (false);
	weapon[6].fire = hashmap_get(&core->hashmap_sprites, "plasmarifle_fire");
	if (!weapon[6].fire)
		return (false);
	weapon[7].ammo_type = 3;
	weapon[7].damage.min = 2060;
	weapon[7].damage.max = 4200;
	weapon[7].owned = true;
	weapon[7].normal = hashmap_get(&core->hashmap, "BFGGA0");
	if (!weapon[7].normal)
		return (false);
	weapon[7].anim = hashmap_get(&core->hashmap_sprites, "BFG9000");
	if (!weapon[7].anim)
		return (false);
	weapon[7].fire = hashmap_get(&core->hashmap_sprites, "BFG9000_fire");
	if (!weapon[7].fire)
		return (false);
	return (true);
}
