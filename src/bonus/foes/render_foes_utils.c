/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_foes_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:16:07 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/23 21:05:54 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	seen_colision(t_core *core, int x, int y)
{
	if (core->map[x][y] == '1' || \
		core->map[x][y] == '2' || \
		core->map[x][y] == '4' || \
		core->map[x][y] == '5' || \
		core->map[x][y] == '6' || \
		core->map[x][y] == '7')
		return (true);
	else
		return (false);
}

static void	swap_adjacent(t_foes **head, t_foes *prev, t_foes *a, t_foes *b)
{
	a->next = b->next;
	b->next = a;
	if (prev)
		prev->next = b;
	else
		*head = b;
}

static bool	single_bubble_pass(t_foes **head)
{
	t_foes	*ptr;
	t_foes	*prev;
	t_foes	*next;
	bool	swapped;

	ptr = *head;
	prev = NULL;
	swapped = false;
	while (ptr && ptr->next)
	{
		if (ptr->dist < ptr->next->dist)
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

void	sort_enemies_by_distance(t_foes **head)
{
	if (!head || !*head || !(*head)->next)
		return ;
	while (single_bubble_pass(head))
		;
}
