/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_picks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:23:59 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/24 16:58:09 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drop_object(t_core *core, t_foes *enemy)
{
	int		random;

	srand(time(NULL));
	random = rand() % 20;
	if (!create_item_chain(core, enemy, random))
		return ;
}

void	handle_items8(t_core *core, t_item *item)
{
	if (item->mod_type == W_CHAI)
	{
		if (core->player->weapon[0].owned == false)
		{
			core->player->weapon[0].owned = true;
			core->player->weapon[1].owned = false;
		}
	}
}

void	handle_items7(t_core *core, t_item *item)
{
	if (item->mod_type == W_PLAS)
	{
		if (core->player->weapon[6].owned == true)
		{
			core->player->ammo[3] += 50;
			if (core->player->ammo[3] > 300)
				core->player->ammo[3] = 300;
		}
		else
			core->player->weapon[6].owned = true;
	}
	else if (item->mod_type == W_BFG)
	{
		if (core->player->weapon[7].owned == true)
		{
			core->player->ammo[3] += 50;
			if (core->player->ammo[3] > 300)
				core->player->ammo[3] = 300;
		}
		else
			core->player->weapon[7].owned = true;
	}
	handle_items8(core, item);
}

void	handle_items6(t_core *core, t_item *item)
{
	if (item->mod_type == W_MINI)
	{
		if (core->player->weapon[4].owned == true)
		{
			core->player->ammo[0] += 50;
			if (core->player->ammo[2] > 200)
				core->player->ammo[2] = 200;
		}
		else
			core->player->weapon[4].owned = true;
	}
	else if (item->mod_type == W_ROCK)
	{
		if (core->player->weapon[5].owned == true)
		{
			core->player->ammo[2] += 20;
			if (core->player->ammo[2] > 50)
				core->player->ammo[2] = 50;
		}
		else
			core->player->weapon[5].owned = true;
	}
	handle_items7(core, item);
}

void	handle_items5(t_core *core, t_item *item)
{
	if (item->mod_type == CELL_S)
	{
		core->player->ammo[3] += 20;
		if (core->player->ammo[3] > 300)
			core->player->ammo[3] = 300;
	}
	else if (item->mod_type == CELL_L)
	{
		core->player->ammo[3] += 60;
		if (core->player->ammo[3] > 300)
			core->player->ammo[3] = 300;
	}
	else if (item->mod_type == W_SHOT)
	{
		if (core->player->weapon[3].owned == true)
		{
			core->player->ammo[1] += 20;
			if (core->player->ammo[2] > 50)
				core->player->ammo[2] = 50;
		}
		else
			core->player->weapon[3].owned = true;
	}
	handle_items6(core, item);
}
