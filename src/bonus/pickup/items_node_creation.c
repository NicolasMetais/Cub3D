/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_node_creation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:25:09 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/23 21:11:06 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	swap_adjacent(t_items **head, t_items *prev, t_items *a, t_items *b)
{
	a->next = b->next;
	b->next = a;
	if (prev)
		prev->next = b;
	else
		*head = b;
}

static bool	single_bubble_pass(t_items **head)
{
	t_items	*ptr;
	t_items	*prev;
	t_items	*next;
	bool	swapped;

	ptr = *head;
	prev = NULL;
	swapped = false;
	while (ptr && ptr->next)
	{
		if (ptr->item->dist < ptr->next->item->dist)
		{
			next = ptr->next;
			swap_adjacent(head, prev, ptr, next);
			swapped = true;
			prev = next;
		}
		else
		{
			prev = ptr;
			ptr = ptr->next;
		}
	}
	return (swapped);
}

void	sort_items_by_distance(t_items **head)
{
	if (!head || !*head || !(*head)->next)
		return ;
	while (single_bubble_pass(head))
		;
}

t_items	*create_item_node(t_core *core, t_foes *enemy, int random)
{
	t_items	*node;

	node = gc_malloc(&core->gc, sizeof(t_items), STRUCT, "items_list");
	if (!node)
		return (NULL);
	node->next = NULL;
	node->item = &core->item_list[random];
	node->item->mod_type = random;
	node->item->pos = enemy->pos;
	node->item->item_x = enemy->foe_x;
	node->item->item_y = enemy->foe_y;
	node->item->dist = enemy->dist;
	node->item->angle_to_item = enemy->angle_to_foe;
	node->item->rel_angle = enemy->rel_angle;
	node->item->state = DROP;
	return (node);
}

bool	create_item_chain(t_core *core, t_foes *enemy, int random)
{
	t_items	*node;
	t_items	*current;

	node = create_item_node(core, enemy, random);
	if (!node)
		return (false);
	if (!core->items)
		core->items = node;
	else
	{
		current = core->items;
		while (current->next)
			current = current->next;
		current->next = node;
	}
	return (true);
}
