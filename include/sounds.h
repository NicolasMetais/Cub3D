/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sounds.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:56:48 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/20 13:11:53 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOUNDS_H
# define SOUNDS_H

# include "raylib.h"
# include <stdbool.h>

typedef struct s_sounds
{
	Sound	barrel_exp;
	Sound	player_death;
	Sound	player_death2;
	Sound	player_bump;
	Sound	player_injured;
	Sound	pickup_item;
	Sound	pickup_wpn;
	Sound	cacodemon_atk;
	Sound	cacodemon_death;
	Sound	cacodemon_growl;
	Sound	demon_atk;
	Sound	demon_death;
	Sound	demon_growl;
	Sound	demon_injured;
	Sound	demon_nearby;
	Sound	imp_death;
	Sound	imp_death2;
	Sound	imp_growl1;
	Sound	imp_growl2;
	Sound	imp_nearby;
	Sound	zomb_death;
	Sound	zomb_death2;
	Sound	zomb_death3;
	Sound	zomb_growl1;
	Sound	zomb_growl2;
	Sound	zomb_growl3;
	Sound	zomb_nearby;
	Sound	zomb_pain;
	Sound	pistol;
	Sound	chainsaw;
	Sound	punch;
	Sound	shotgun;
	Sound	rocketlauncher;
	Sound	plasma;
	Sound	bfg;
}	t_sounds;

//play a sound at the right volumes
bool	play_sound(t_core *core, Sound sound);
//unload all sounds
void	unload_all_sound(t_core *core);


#endif