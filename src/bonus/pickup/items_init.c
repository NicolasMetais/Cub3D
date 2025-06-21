/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:52:54 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/21 16:57:30 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	item_init_5(t_core *core)
{
	core->item_list[16].notif = "Notif_chainsaw";
	core->item_list[16].pic = hashmap_get(&core->hashmap, "CSAWA0");
	if (!core->item_list[16].pic)
		return (false);
	core->item_list[17].notif = "Notif_rocket";
	core->item_list[17].pic = hashmap_get(&core->hashmap, "LAUNA0");
	if (!core->item_list[17].pic)
		return (false);
	core->item_list[18].notif = "Notif_plasma";
	core->item_list[18].pic = hashmap_get(&core->hashmap, "PLASA0");
	if (!core->item_list[18].pic)
		return (false);
	core->item_list[19].notif = "Notif_bfg";
	core->item_list[19].pic = hashmap_get(&core->hashmap, "BFUGA0");
	if (!core->item_list[19].pic)
		return (false);
	return (true);
}

bool	item_init_4(t_core *core)
{
	core->item_list[12].notif = "Notif_cells";
	core->item_list[12].pic = hashmap_get(&core->hashmap, "CELLA0");
	if (!core->item_list[12].pic)
		return (false);
	core->item_list[13].notif = "Notif_cells";
	core->item_list[13].pic = hashmap_get(&core->hashmap, "CELPA0");
	if (!core->item_list[13].pic)
		return (false);
	core->item_list[14].notif = "Notif_shotgun";
	core->item_list[14].pic = hashmap_get(&core->hashmap, "SHOTA0");
	if (!core->item_list[14].pic)
		return (false);
	core->item_list[15].notif = "Notif_chaingun";
	core->item_list[15].pic = hashmap_get(&core->hashmap, "MGUNA0");
	if (!core->item_list[15].pic)
		return (false);
	if (!item_init_5(core))
		return (false);
	return (true);
}

bool	item_init_3(t_core *core)
{
	core->item_list[7].pic = hashmap_get(&core->hashmap, "AMMOA0");
	if (!core->item_list[7].pic)
		return (false);
	core->item_list[8].notif = "Notif_shells";
	core->item_list[8].pic = hashmap_get(&core->hashmap, "SHELA0");
	if (!core->item_list[8].pic)
		return (false);
	core->item_list[9].notif = "Notif_shells";
	core->item_list[9].pic = hashmap_get(&core->hashmap, "SBOXA0");
	if (!core->item_list[9].pic)
		return (false);
	core->item_list[10].notif = "Notif_rockets";
	core->item_list[10].pic = hashmap_get(&core->hashmap, "ROCKA0");
	if (!core->item_list[10].pic)
		return (false);
	core->item_list[11].notif = "Notif_rockets";
	core->item_list[11].pic = hashmap_get(&core->hashmap, "BROKA0");
	if (!core->item_list[11].pic)
		return (false);
	if (!item_init_4(core))
		return (false);
	return (true);
}

bool	item_init_2(t_core *core)
{
	core->item_list[2].pic = hashmap_get(&core->hashmap, "MEDIA0");
	if (!core->item_list[2].pic)
		return (false);
	core->item_list[3].notif = "Notif_armor";
	core->item_list[3].anim = hashmap_get(&core->hashmap_sprites, "armor");
	if (!core->item_list[3].anim)
		return (false);
	core->item_list[4].notif = "Notif_bigArmor";
	core->item_list[4].anim = hashmap_get(
			&core->hashmap_sprites, "security_armor");
	if (!core->item_list[4].anim)
		return (false);
	core->item_list[5].notif = "Notif_megarmor";
	core->item_list[5].anim = hashmap_get(&core->hashmap_sprites, "megarmor");
	if (!core->item_list[5].anim)
		return (false);
	core->item_list[6].notif = "Notif_bullets";
	core->item_list[6].pic = hashmap_get(&core->hashmap, "CLIPA0");
	if (!core->item_list[6].pic)
		return (false);
	core->item_list[7].notif = "Notif_bullets";
	if (!item_init_3(core))
		return (false);
	return (true);
}

bool	item_init(t_core *core)
{
	int	i;

	i = -1;
	while (++i < 20)
	{
		core->item_list[i].id = i;
		if (i > 13)
			core->item_list[i].type = WEAPON;
		else
			core->item_list[i].type = ITEM;
	}
	core->item_list[0].notif = "Notif_life";
	core->item_list[0].anim = hashmap_get(&core->hashmap_sprites, "health");
	if (!core->item_list[0].anim)
		return (false);
	core->item_list[1].notif = "Notif_stimpack";
	core->item_list[1].pic = hashmap_get(&core->hashmap, "STIMA0");
	if (!core->item_list[1].pic)
		return (false);
	core->item_list[2].notif = "Notif_medikit";
	if (!item_init_2(core))
		return (false);
	return (true);
}
