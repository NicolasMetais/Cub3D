/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:16:08 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/24 13:38:17 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	not_drop_yet(t_player *player, int r)
{
	if (r == 14 && player->weapon[3].owned == true)
		return (false);
	else if (r == 15 && player->weapon[4].owned == true)
		return (false);
	else if (r == 17 && player->weapon[5].owned == true)
		return (false);
	else if (r == 18 && player->weapon[6].owned == true)
		return (false);
	else if (r == 19 && player->weapon[7].owned == true)
		return (false);
	else if (r == 16 && player->weapon[0].owned == true)
		return (false);
	return (true);
}

static void	get_render(t_core *core, t_items *items, t_pos start)
{
	if (items->item->dist < core->rc->dist3[items->screen_x] \
	&& items->item->state == DROP && !is_animation(items->item))
		transparency_scaled(core->game_img, items->item->pic, \
	start, items->sprite_size);
	else if (items->item->dist < core->rc->dist3[items->screen_x] \
	&& items->item->state == DROP)
		transparency_scaled(core->game_img, \
	items->item->activ_img->image, start, items->sprite_size);
}

static void	get_item_start_info(t_core *core, t_items *items)
{
	while (items)
	{
		items->item->dx = items->item->item_x - core->rc->pl_x;
		items->item->dy = items->item->item_y - core->rc->pl_y;
		items->item->dist = sqrt(items->item->dx * \
		items->item->dx + items->item->dy * items->item->dy);
		items = items->next;
	}
	anim_items(core);
	sort_items_by_distance(&core->items);
}

static void	update_item_angle(t_core *core, t_items *items)
{
	items->item->angle_to_item = atan2(items->item->dy, items->item->dx);
	if (items->item->angle_to_item < -PI)
		items->item->angle_to_item += 2 * PI;
	if (items->item->angle_to_item > PI)
		items->item->angle_to_item -= 2 * PI;
	items->item->rel_angle = items->item->angle_to_item - core->rc->pl_angle;
	if (items->item->rel_angle < -PI)
		items->item->rel_angle += 2 * PI;
	if (items->item->rel_angle > PI)
		items->item->rel_angle -= 2 * PI;
	items->item->dist -= cos(items->item->rel_angle);
}

void	render_items(t_core *core)
{
	t_pos	start;
	t_items	*items;

	items = core->items;
	get_item_start_info(core, items);
	items = core->items;
	while (items)
	{
		update_item_angle(core, items);
		items->screen_x = (items->item->rel_angle / \
		(core->fov * RAD)) * S_LENGHT + (S_LENGHT / 2);
		items->sprite_size = (int)(S_HEIGHT / items->item->dist) * 3;
		start.x = items->screen_x - items->sprite_size / 2;
		start.y = (S_HEIGHT / 2) - (items->sprite_size / 2) \
		+ items->sprite_size;
		if (items->screen_x >= 0 && items->screen_x < S_LENGHT)
			get_render(core, items, start);
		items = items->next;
	}
	update_items_player(core);
}
