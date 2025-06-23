/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_picks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:22:27 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/23 20:23:22 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_items4(t_core *core, t_item *item)
{
	if (item->mod_type == BULL_L)
	{
		core->player->ammo[1] += 20;
		if (core->player->ammo[1] > 50)
			core->player->ammo[1] = 50;
	}
	else if (item->mod_type == ROCK_S)
	{
		core->player->ammo[2] += 2;
		if (core->player->ammo[2] > 50)
			core->player->ammo[2] = 50;
	}
	else if (item->mod_type == ROCK_L)
	{
		core->player->ammo[2] += 10;
		if (core->player->ammo[2] > 50)
			core->player->ammo[2] = 50;
	}
	handle_items5(core, item);
}

void	handle_items3(t_core *core, t_item *item)
{
	if (item->mod_type == BULL_S)
	{
		core->player->ammo[0] += 10;
		if (core->player->ammo[0] > 200)
			core->player->ammo[0] = 200;
	}
	else if (item->mod_type == BULL_L)
	{
		core->player->ammo[0] += 50;
		if (core->player->ammo[0] > 200)
			core->player->ammo[0] = 200;
	}
	else if (item->mod_type == SHEL_S)
	{
		core->player->ammo[1] += 5;
		if (core->player->ammo[1] > 50)
			core->player->ammo[1] = 50;
	}
	handle_items4(core, item);
}

void	handle_items2(t_core *core, t_item *item)
{
	if (item->mod_type == ARMO_S)
	{
		core->player->armor += 10;
		if (core->player->armor > 100)
			core->player->armor = 100;
	}
	else if (item->mod_type == ARMO_M)
	{
		core->player->armor += 25;
		if (core->player->armor > 100)
			core->player->armor = 100;
	}
	else if (item->mod_type == ARMO_L)
	{
		core->player->armor += 50;
		if (core->player->armor > 100)
			core->player->armor = 100;
	}
	handle_items3(core, item);
}

void	handle_items(t_core *core, t_item *item)
{
	if (item->mod_type == LIFE_S)
	{
		core->player->health += 10;
		if (core->player->health > 100)
			core->player->health = 100;
	}
	else if (item->mod_type == LIFE_M)
	{
		core->player->health += 25;
		if (core->player->health > 100)
			core->player->health = 100;
	}
	else if (item->mod_type == LIFE_L)
	{
		core->player->health += 50;
		if (core->player->health > 100)
			core->player->health = 100;
	}
	handle_items2(core, item);
}

void	update_items_player(t_core *core)
{
	t_items	*items;

	items = core->items;
	while (items)
	{
		if (items->item->state == DROP)
		{
			if (items->item->dist < 6)
			{
				handle_items(core, items->item);
				items->item->state = TAKEN;
			}
		}
		items = items->next;
	}
}
