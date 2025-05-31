/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:17:25 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/31 19:47:13 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	weapons_init_fourth(t_weapon weapon[9], t_core *core)
{
	weapon[7].name = "Plasma Rifle";
	weapon[7].ammo_type = 4;
	weapon[7].cooldown = 0.086;
	weapon[7].fire_rate = 700;
	weapon[7].damage.min = 5;
	weapon[7].damage.max = 40;
	weapon[7].owned = false;
	weapon[7].normal = hashmap_get(&core->hashmap, "PLSGA0");
	weapon[7].anim = hashmap_get(&core->hashmap_sprites, "plasmarifle");
	weapon[7].fire = hashmap_get(&core->hashmap_sprites, "plasmarifle_fire");
	weapon[8].name = "BFG 9000";
	weapon[8].ammo_type = 4;
	weapon[8].cooldown = 1.07;
	weapon[8].fire_rate = 56;
	weapon[8].damage.min = 2060;
	weapon[8].damage.max = 4200;
	weapon[8].owned = false;
	weapon[8].normal = hashmap_get(&core->hashmap, "BFGGA0");
	weapon[8].anim = hashmap_get(&core->hashmap_sprites, "BFG9000");
	weapon[8].fire = hashmap_get(&core->hashmap_sprites, "BFG9000_fire");
}

void	weapons_init_third(t_weapon weapon[9], t_core *core)
{
	weapon[5].name = "Chaingun";
	weapon[5].ammo_type = 1;
	weapon[5].cooldown = 0.113;
	weapon[5].fire_rate = 530;
	weapon[5].damage.min = 5;
	weapon[5].damage.max = 15;
	weapon[5].owned = false;
	weapon[5].normal = hashmap_get(&core->hashmap, "CHGGA0");
	weapon[5].anim = hashmap_get(&core->hashmap_sprites, "chaingun");
	weapon[5].fire = hashmap_get(&core->hashmap_sprites, "chaingun_fire");
	weapon[6].name = "Rocket launcher";
	weapon[6].ammo_type = 3;
	weapon[6].cooldown = 0.566;
	weapon[6].fire_rate = 106;
	weapon[6].damage.min = 148;
	weapon[6].damage.max = 288;
	weapon[6].owned = false;
	weapon[6].normal = hashmap_get(&core->hashmap, "MISGA0");
	weapon[6].anim = hashmap_get(&core->hashmap_sprites, "rocketlauncher");
	weapon[6].fire = hashmap_get(&core->hashmap_sprites, "rocketlauncher_fire");
	weapons_init_fourth(weapon, core);
}

void	weapons_init_bis(t_weapon weapon[9], t_core *core)
{
	weapon[2].name = "pistol";
	weapon[2].ammo_type = 1;
	weapon[2].cooldown = 0.4;
	weapon[2].fire_rate = 150;
	weapon[2].damage.min = 5;
	weapon[2].damage.max = 15;
	weapon[2].owned = true;
	weapon[2].normal = hashmap_get(&core->hashmap, "PISGA0");
	weapon[2].anim = hashmap_get(&core->hashmap_sprites, "pistol");
	weapon[2].fire = hashmap_get(&core->hashmap_sprites, "pistol_fire");
	weapon[2].lock = false;
	weapon[3].name = "Shotgun";
	weapon[3].ammo_type = 2;
	weapon[3].cooldown = 1.0;
	weapon[3].fire_rate = 58;
	weapon[3].damage.min = 35;
	weapon[3].damage.max = 105;
	weapon[3].owned = false;
	weapon[3].normal = hashmap_get(&core->hashmap, "SHTGA0");
	weapon[3].anim = hashmap_get(&core->hashmap_sprites, "shotgun");
	weapon[3].fire = hashmap_get(&core->hashmap_sprites, "shotgun_fire");
	weapons_init_third(weapon, core);
}

void	weapons_init(t_weapon weapon[9], t_core *core)
{
	weapon[0].name = "Chainsaw";
	weapon[0].ammo_type = 0;
	weapon[0].cooldown = 0.125;
	weapon[0].fire_rate = 480;
	weapon[0].damage.min = 2;
	weapon[0].damage.max = 20;
	weapon[0].owned = false;
	weapon[0].normal = hashmap_get(&core->hashmap, "SAWGA0");
	weapon[0].anim = hashmap_get(&core->hashmap_sprites, "saw");
	weapon[1].name = "Fists";
	weapon[1].ammo_type = 0;
	weapon[1].cooldown = 0.5;
	weapon[1].fire_rate = 120;
	weapon[1].damage.min = 2;
	weapon[1].damage.max = 20;
	weapon[1].owned = true;
	weapon[1].normal = hashmap_get(&core->hashmap, "PUNGA0");
	weapon[1].anim = hashmap_get(&core->hashmap_sprites, "fist");

	weapons_init_bis(weapon, core);
}
