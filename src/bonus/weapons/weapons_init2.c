/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_init2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:15:56 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/21 17:05:33 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	animation_options_init(t_weapon weapon[9], t_core *core)
{
	int				i;
	int				j;
	const t_pos		offsets[] = {
	{55, 120},
	{80, 150},
	{60, 125},
	{75, 120},
	{0, 120},
	{178, 128},
	{145, 120}};

	setup_animation_exceptions(weapon);
	i = 1;
	j = 0;
	while (++i < 8)
	{
		if (!rebuild_fire_anim(&weapon[i].anim->img_list,
				weapon[i].fire, offsets[j], core))
			return (false);
		j++;
	}
	return (true);
}

bool	weapons_init_six(t_weapon weapon[9], t_core *core)
{
	weapon[7].fire = hashmap_get(&core->hashmap_sprites, "BFG9000_fire");
	if (!weapon[7].fire)
		return (false);
	weapon[0].firing = core->sound_list.chainsaw;
	weapon[1].firing = core->sound_list.punch;
	weapon[2].firing = core->sound_list.pistol;
	weapon[3].firing = core->sound_list.shotgun;
	weapon[4].firing = core->sound_list.pistol;
	weapon[5].firing = core->sound_list.rocketlauncher;
	weapon[6].firing = core->sound_list.plasma;
	weapon[7].firing = core->sound_list.bfg;
	if (!animation_options_init(weapon, core))
		return (false);
	weapon[4].loop_loaded = weapon[4].anim->img_list->next;
	weapon[6].loop_loaded = weapon[6].anim->img_list->next;
	return (true);
}

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
	weapon[7].name = "BFG 9000";
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
	if (!weapons_init_six(weapon, core))
		return (false);
	return (true);
}
