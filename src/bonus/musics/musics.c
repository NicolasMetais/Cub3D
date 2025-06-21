/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   musics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:34:41 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/20 14:53:28 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	unload_more_sound(t_core *core)
{
	UnloadSound(core->sound_list.zomb_pain);
	UnloadSound(core->sound_list.zomb_growl1);
	UnloadSound(core->sound_list.zomb_growl2);
	UnloadSound(core->sound_list.zomb_growl3);
	UnloadSound(core->sound_list.zomb_nearby);
	UnloadSound(core->sound_list.pistol);
	UnloadSound(core->sound_list.chainsaw);
	UnloadSound(core->sound_list.shotgun);
	UnloadSound(core->sound_list.punch);
	UnloadSound(core->sound_list.rocketlauncher);
	UnloadSound(core->sound_list.plasma);
	UnloadSound(core->sound_list.bfg);
}

void	unload_all_sound(t_core *core)
{
	UnloadMusicStream(core->bg_music);
	UnloadSound(core->sound_list.barrel_exp);
	UnloadSound(core->sound_list.player_death);
	UnloadSound(core->sound_list.player_death2);
	UnloadSound(core->sound_list.player_bump);
	UnloadSound(core->sound_list.player_injured);
	UnloadSound(core->sound_list.pickup_item);
	UnloadSound(core->sound_list.pickup_wpn);
	UnloadSound(core->sound_list.cacodemon_atk);
	UnloadSound(core->sound_list.cacodemon_death);
	UnloadSound(core->sound_list.cacodemon_growl);
	UnloadSound(core->sound_list.demon_atk);
	UnloadSound(core->sound_list.demon_death);
	UnloadSound(core->sound_list.demon_growl);
	UnloadSound(core->sound_list.demon_injured);
	UnloadSound(core->sound_list.demon_nearby);
	UnloadSound(core->sound_list.imp_death);
	UnloadSound(core->sound_list.imp_death2);
	UnloadSound(core->sound_list.imp_growl1);
	UnloadSound(core->sound_list.imp_growl2);
	UnloadSound(core->sound_list.imp_nearby);
	UnloadSound(core->sound_list.zomb_death);
	UnloadSound(core->sound_list.zomb_death2);
	UnloadSound(core->sound_list.zomb_death3);
	unload_more_sound(core);
}

bool	play_random_music(t_core *core)
{
	int	i;

	srand(time(NULL));
	i = rand() % 28;
	SetMusicVolume(core->bg_music, (float)core->sound / 100.0f);
	core->bg_music = LoadMusicStream(core->music_list[i]);
	core->bg_music.looping = false;
	if (!core->bg_music.stream.buffer)
		return (false);
	PlayMusicStream(core->bg_music);
	return (true);
}

bool	play_sound(t_core *core, Sound sound)
{
	SetSoundVolume(sound, (float)core->sound / 100.0f);
	PlaySound(sound);
	return (true);
}
