/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_animations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:27:57 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/23 21:12:28 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_animation(t_item *item)
{
	if (item->mod_type == ARMO_S || \
		item->mod_type == ARMO_M || \
		item->mod_type == ARMO_L || \
		item->mod_type == LIFE_S)
		return (true);
	return (false);
}

static void	anim_loop_items(t_core *core, t_items *items)
{
	struct timeval	current;
	long			elapsed;

	(void)core;
	gettimeofday(&current, NULL);
	elapsed = (current.tv_sec - items->item->anim->update.tv_sec) * 1000
		+ (current.tv_usec - items->item->anim->update.tv_usec) / 1000;
	items->item->activ_img = items->item->anim->img_list;
	if (elapsed > items->item->anim->speed)
	{
		if (items->item->anim->img_list && items->item->anim->img_list->next)
		{
			items->item->anim->img_list = items->item->anim->img_list->next;
			items->item->activ_img = items->item->anim->img_list;
		}
		items->item->anim->update = current;
	}
}

void	anim_items(t_core *core)
{
	t_items		*items;

	if (!core->items)
		return ;
	items = core->items;
	while (items)
	{
		if (items->item->state == DROP && is_animation(items->item))
		{
			if (!items || !items->item->anim)
				return ;
			anim_loop_items(core, items);
		}
		items = items->next;
	}
}
