/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:17:25 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/20 13:48:59 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	weapons_init_fourth(t_weapon weapon[9], t_core *core)
{
	weapon[4].fire = hashmap_get(&core->hashmap_sprites, "chaingun_fire");
	if (!weapon[4].fire)
		return (false);
	weapon[4].firing = core->sound_list.pistol;
	weapon[5].name = "Rocket launcher";
	weapon[5].ammo_type = 2;
	weapon[5].damage.min = 148;
	weapon[5].damage.max = 288;
	weapon[5].owned = true;
	weapon[5].normal = hashmap_get(&core->hashmap, "MISGA0");
	if (!weapon[5].normal)
		return (false);
	weapon[5].anim = hashmap_get(&core->hashmap_sprites, "rocketlauncher");
	if (!weapon[5].anim)
		return (false);
	weapon[5].fire = hashmap_get(&core->hashmap_sprites, "rocketlauncher_fire");
	if (!weapon[5].fire)
		return (false);
	weapon[5].firing = core->sound_list.rocketlauncher;
	weapon[6].name = "Plasma Rifle";
	weapon[6].ammo_type = 3;
	weapon[6].damage.min = 5;
	weapon[6].damage.max = 40;
	weapon[6].owned = true;
	if (!weapons_init_five(weapon, core))
		return (false);
	return (true);
}

bool	weapons_init_third(t_weapon weapon[9], t_core *core)
{
	weapon[3].normal = hashmap_get(&core->hashmap, "SHTGA0");
	if (!weapon[3].normal)
		return (false);
	weapon[3].anim = hashmap_get(&core->hashmap_sprites, "shotgun");
	if (!weapon[3].anim)
		return (false);
	weapon[3].fire = hashmap_get(&core->hashmap_sprites, "shotgun_fire");
	if (!weapon[3].fire)
		return (false);
	weapon[3].firing = core->sound_list.shotgun;
	weapon[4].name = "Chaingun";
	weapon[4].ammo_type = 0;
	weapon[4].damage.min = 5;
	weapon[4].damage.max = 15;
	weapon[4].owned = true;
	weapon[4].normal = hashmap_get(&core->hashmap, "CHGGA0");
	if (!weapon[4].normal)
		return (false);
	weapon[4].anim = hashmap_get(&core->hashmap_sprites, "chaingun");
	if (!weapon[4].anim)
		return (false);
	if (!weapons_init_fourth(weapon, core))
		return (false);
	return (true);
}

bool	weapons_init_bis(t_weapon weapon[9], t_core *core)
{
	weapon[2].name = "pistol";
	weapon[2].ammo_type = 0;
	weapon[2].damage.min = 5;
	weapon[2].damage.max = 15;
	weapon[2].owned = true;
	weapon[2].normal = hashmap_get(&core->hashmap, "PISGA0");
	if (!weapon[2].normal)
		return (false);
	weapon[2].anim = hashmap_get(&core->hashmap_sprites, "pistol");
	if (!weapon[2].anim)
		return (false);
	weapon[2].fire = hashmap_get(&core->hashmap_sprites, "pistol_fire");
	if (!weapon[2].fire)
		return (false);
	weapon[2].lock = false;
	weapon[2].firing = core->sound_list.pistol;
	weapon[3].name = "Shotgun";
	weapon[3].ammo_type = 1;
	weapon[3].damage.min = 35;
	weapon[3].damage.max = 105;
	weapon[3].owned = true;
	if (!weapons_init_third(weapon, core))
		return (false);
	return (true);
}

bool	weapons_init(t_weapon weapon[9], t_core *core)
{
	weapon[0].name = "Chainsaw";
	weapon[0].ammo_type = 5;
	weapon[0].damage.min = 2;
	weapon[0].damage.max = 20;
	weapon[0].owned = false;
	weapon[0].normal = hashmap_get(&core->hashmap, "SAWGA0");
	if (!weapon[0].normal)
		return (false);
	weapon[0].anim = hashmap_get(&core->hashmap_sprites, "saw");
	if (!weapon[0].anim)
		return (false);
	weapon[0].firing = core->sound_list.chainsaw;
	weapon[1].name = "Fists";
	weapon[1].ammo_type = 5;
	weapon[1].damage.min = 2;
	weapon[1].damage.max = 20;
	weapon[1].owned = true;
	weapon[1].normal = hashmap_get(&core->hashmap, "PUNGA0");
	if (!weapon[1].normal)
		return (false);
	weapon[1].anim = hashmap_get(&core->hashmap_sprites, "fist");
	if (!weapon[1].anim)
		return (false);
	weapon[1].firing = core->sound_list.punch;
	if (!weapons_init_bis(weapon, core))
		return (false);
	return (true);
}
