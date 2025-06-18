/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:41:32 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/18 01:51:45 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	music_init_2(t_core *core)
{
	core->music_list[21] = "sounds/d_e3m4.ogg";
	core->music_list[22] = "sounds/d_e3m5.ogg";
	core->music_list[23] = "sounds/d_e3m6.ogg";
	core->music_list[24] = "sounds/d_e3m7.ogg";
	core->music_list[25] = "sounds/d_e3m8.ogg";
	core->music_list[26] = "sounds/d_e3m9.ogg";
	core->music_list[27] = "sounds/d_victor.ogg";
}

void	music_init(t_core *core)
{
	InitAudioDevice();
	SetTraceLogLevel(LOG_NONE);
	core->music_list[0] = "sounds/d_e1m1.ogg";
	core->music_list[1] = "sounds/d_e1m2.ogg";
	core->music_list[2] = "sounds/d_e1m3.ogg";
	core->music_list[3] = "sounds/d_e1m4.ogg";
	core->music_list[4] = "sounds/d_e1m5.ogg";
	core->music_list[5] = "sounds/d_e1m6.ogg";
	core->music_list[6] = "sounds/d_e1m7.ogg";
	core->music_list[7] = "sounds/d_e1m8.ogg";
	core->music_list[8] = "sounds/d_e1m9.ogg";
	core->music_list[9] = "sounds/d_e2m1.ogg";
	core->music_list[10] = "sounds/d_e2m2.ogg";
	core->music_list[11] = "sounds/d_e2m3.ogg";
	core->music_list[12] = "sounds/d_e2m4.ogg";
	core->music_list[13] = "sounds/d_e2m5.ogg";
	core->music_list[14] = "sounds/d_e2m6.ogg";
	core->music_list[15] = "sounds/d_e2m7.ogg";
	core->music_list[16] = "sounds/d_e2m8.ogg";
	core->music_list[17] = "sounds/d_e2m9.ogg";
	core->music_list[18] = "sounds/d_e3m1.ogg";
	core->music_list[19] = "sounds/d_e3m2.ogg";
	core->music_list[20] = "sounds/d_e3m3.ogg";
	music_init_2(core);
}
