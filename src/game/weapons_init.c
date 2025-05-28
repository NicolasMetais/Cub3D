/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:17:25 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/28 21:51:13 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	weapons_init_third(t_weapon weapon[9])
{
	weapon[6].name = "Rocket launcher";
	weapon[6].ammo_type = 3;
	weapon[6].cooldown = 0.566;
	weapon[6].fire_rate = 106;
	weapon[6].damage.min = 148;
	weapon[6].damage.max = 288;
	weapon[6].owned = false;
	weapon[7].name = "Plasma Rifle";
	weapon[7].ammo_type = 4;
	weapon[7].cooldown = 0.086;
	weapon[7].fire_rate = 700;
	weapon[7].damage.min = 5;
	weapon[7].damage.max = 40;
	weapon[7].owned = false;
	weapon[8].name = "BFG 9000";
	weapon[8].ammo_type = 4;
	weapon[8].cooldown = 1.07;
	weapon[8].fire_rate = 56;
	weapon[8].damage.min = 2060;
	weapon[8].damage.max = 4200;
	weapon[8].owned = false;
}

void	weapons_init_bis(t_weapon weapon[9])
{
	weapon[3].name = "Shotgun";
	weapon[3].ammo_type = 2;
	weapon[3].cooldown = 1.0;
	weapon[3].fire_rate = 58;
	weapon[3].damage.min = 35;
	weapon[3].damage.max = 105;
	weapon[3].owned = false;
	weapon[4].name = "Super Shotgun";
	weapon[4].ammo_type = 2;
	weapon[4].cooldown = 1.4;
	weapon[4].fire_rate = 42;
	weapon[4].damage.min = 105;
	weapon[4].damage.max = 315;
	weapon[4].owned = false;
	weapon[5].name = "Chaingun";
	weapon[5].ammo_type = 1;
	weapon[5].cooldown = 0.113;
	weapon[5].fire_rate = 530;
	weapon[5].damage.min = 5;
	weapon[5].damage.max = 15;
	weapon[5].owned = false;
	weapons_init_third(weapon);
}

void	weapons_init(t_weapon weapon[9])
{
	weapon[0].name = "Fists";
	weapon[0].ammo_type = 0;
	weapon[0].cooldown = 0.5;
	weapon[0].fire_rate = 120;
	weapon[0].damage.min = 2;
	weapon[0].damage.max = 20;
	weapon[0].owned = true;
	weapon[1].name = "Chainsaw";
	weapon[1].ammo_type = 0;
	weapon[1].cooldown = 0.125;
	weapon[1].fire_rate = 480;
	weapon[1].damage.min = 2;
	weapon[1].damage.max = 20;
	weapon[1].owned = false;
	weapon[2].name = "Pistol";
	weapon[2].ammo_type = 1;
	weapon[2].cooldown = 0.4;
	weapon[2].fire_rate = 150;
	weapon[2].damage.min = 5;
	weapon[2].damage.max = 15;
	weapon[2].owned = true;
	weapons_init_bis(weapon);
}
