/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:41:32 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/20 13:11:56 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	music_init_3(t_core *core)
{
	core->sound_list.demon_nearby = LoadSound(
			"sounds/enemies/demon_nearby.wav");
	core->sound_list.imp_death = LoadSound("sounds/enemies/imp_death.wav");
	core->sound_list.imp_death2 = LoadSound("sounds/enemies/imp_death2.wav");
	core->sound_list.imp_growl1 = LoadSound("sounds/enemies/imp_growl1.wav");
	core->sound_list.imp_growl2 = LoadSound("sounds/enemies/imp_growl2.wav");
	core->sound_list.imp_nearby = LoadSound("sounds/enemies/imp_nearby.wav");
	core->sound_list.zomb_death = LoadSound("sounds/enemies/zomb_death.wav");
	core->sound_list.zomb_death2 = LoadSound("sounds/enemies/zomb_death2.wav");
	core->sound_list.zomb_death3 = LoadSound("sounds/enemies/zomb_death3.wav");
	core->sound_list.zomb_growl1 = LoadSound("sounds/enemies/zomb_growl1.wav");
	core->sound_list.zomb_growl2 = LoadSound("sounds/enemies/zomb_growl2.wav");
	core->sound_list.zomb_growl3 = LoadSound("sounds/enemies/zomb_growl3.wav");
	core->sound_list.zomb_nearby = LoadSound("sounds/enemies/zomb_nearby.wav");
	core->sound_list.zomb_pain = LoadSound("sounds/enemies/zomb_pain.wav");
	core->sound_list.pistol = LoadSound("sounds/weapons/pistol_fire.wav");
	core->sound_list.chainsaw = LoadSound("sounds/weapons/chainsaw_fire.wav");
	core->sound_list.punch = LoadSound("sounds/weapons/punch.wav");
	core->sound_list.shotgun = LoadSound("sounds/weapons/shotgun_fire.wav");
	core->sound_list.rocketlauncher = LoadSound(
			"sounds/weapons/rocketLauncher_fire.wav");
	core->sound_list.plasma = LoadSound("sounds/weapons/plasma_fire.wav");
	core->sound_list.bfg = LoadSound("sounds/weapons/BFG_fire.wav");

}

void	music_init_2(t_core *core)
{
	core->music_list[21] = "sounds/musics/d_e3m4.ogg";
	core->music_list[22] = "sounds/musics/d_e3m5.ogg";
	core->music_list[23] = "sounds/musics/d_e3m6.ogg";
	core->music_list[24] = "sounds/musics/d_e3m7.ogg";
	core->music_list[25] = "sounds/musics/d_e3m8.ogg";
	core->music_list[26] = "sounds/musics/d_e3m9.ogg";
	core->music_list[27] = "sounds/musics/d_victor.ogg";
	core->sound_list.barrel_exp = LoadSound("sounds/player/barrel_exp.wav");
	core->sound_list.player_death = LoadSound("sounds/player/death.wav");
	core->sound_list.player_death2 = LoadSound("sounds/player/death2.wav");
	core->sound_list.player_bump = LoadSound("sounds/player/hit_wall.wav");
	core->sound_list.pickup_item = LoadSound("sounds/player/item_pickup.wav");
	core->sound_list.pickup_wpn = LoadSound("sounds/player/weapon_pickup.wav");
	core->sound_list.cacodemon_atk = LoadSound(
			"sounds/enemies/cacodemon_atk.wav");
	core->sound_list.cacodemon_death = LoadSound(
			"sounds/enemies/cacodemon_death.wav");
	core->sound_list.cacodemon_growl = LoadSound(
			"sounds/enemies/cacodemon_growl.wav");
	core->sound_list.demon_atk = LoadSound("sounds/enemies/demon_atk.wav");
	core->sound_list.demon_death = LoadSound("sounds/enemies/demon_death.wav");
	core->sound_list.demon_growl = LoadSound("sounds/enemies/demon_growl.wav");
	core->sound_list.demon_injured = LoadSound(
			"sounds/enemies/demon_injured.wav");
	music_init_3(core);
}

void	music_init(t_core *core)
{
	InitAudioDevice();
	SetTraceLogLevel(LOG_NONE);
	core->music_list[0] = "sounds/musics/d_e1m1.ogg";
	core->music_list[1] = "sounds/musics/d_e1m2.ogg";
	core->music_list[2] = "sounds/musics/d_e1m3.ogg";
	core->music_list[3] = "sounds/musics/d_e1m4.ogg";
	core->music_list[4] = "sounds/musics/d_e1m5.ogg";
	core->music_list[5] = "sounds/musics/d_e1m6.ogg";
	core->music_list[6] = "sounds/musics/d_e1m7.ogg";
	core->music_list[7] = "sounds/musics/d_e1m8.ogg";
	core->music_list[8] = "sounds/musics/d_e1m9.ogg";
	core->music_list[9] = "sounds/musics/d_e2m1.ogg";
	core->music_list[10] = "sounds/musics/d_e2m2.ogg";
	core->music_list[11] = "sounds/musics/d_e2m3.ogg";
	core->music_list[12] = "sounds/musics/d_e2m4.ogg";
	core->music_list[13] = "sounds/musics/d_e2m5.ogg";
	core->music_list[14] = "sounds/musics/d_e2m6.ogg";
	core->music_list[15] = "sounds/musics/d_e2m7.ogg";
	core->music_list[16] = "sounds/musics/d_e2m8.ogg";
	core->music_list[17] = "sounds/musics/d_e2m9.ogg";
	core->music_list[18] = "sounds/musics/d_e3m1.ogg";
	core->music_list[19] = "sounds/musics/d_e3m2.ogg";
	core->music_list[20] = "sounds/musics/d_e3m3.ogg";
	music_init_2(core);
}
