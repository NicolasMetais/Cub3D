/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:06:19 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/24 19:21:15 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	foes_to_create(t_core *core)
{
	int	x;
	int	y;
	int	res;

	x = 0;
	res = 0;
	while (x < core->map_height)
	{
		y = 0;
		while (y < core->map_width)
		{
			if (core->map[x][y] == '0')
				res++;
			y++;
		}
		x++;
	}
	if (res / 40 > 300)
		return (300);
	return (res / 40);
}

t_foes	*create_foe_node(t_core *core, int i, int x, int y)
{
	t_foes	*node;

	node = gc_malloc(&core->gc, sizeof(t_foes), STRUCT, "foes_list");
	if (!node)
		return (NULL);
	ft_memset(node, 0, sizeof(t_foes));
	node->type = i;
	node->id = i;
	node->death = 0;
	node->attack = 0;
	node->pos = gc_malloc(&core->gc, sizeof(t_pos), STRUCT, "foe pos");
	if (!node->pos)
		return (NULL);
	node->pos->y = x;
	node->pos->x = y;
	node->foe_x = node->pos->x * 8 + 4;
	node->foe_y = node->pos->y * 8 + 4;
	node->angle = 2 * PI;
	node->foedelt_x = cos(node->angle);
	node->foedelt_y = sin(node->angle);
	init_foe_img(core, node);
	node->next = NULL;
	return (node);
}

bool	create_foes(t_core *core, int i, int x, int y)
{
	t_foes	*node;
	t_foes	*current;

	node = create_foe_node(core, i, x, y);
	if (!node)
		return (false);
	if (!core->foes)
		core->foes = node;
	else
	{
		current = core->foes;
		while (current->next)
			current = current->next;
		current->next = node;
	}
	return (true);
}

bool	get_number_of_foes(t_core *core)
{
	int	x;
	int	y;
	int	res;

	x = 0;
	srand(time(NULL));
	while (x < core->map_height)
	{
		y = 0;
		while (y < core->map_width)
		{
			if (core->map[x][y] == 'F' && core->valid_map_tiles[x][y] == 'V')
			{
				res = rand() % 7;
				if (!create_foes(core, res, x, y))
					return (false);
			}
			y++;
		}
		x++;
	}
	return (true);
}

bool	init_foes(t_core *core)
{
	randomized_spawns(core);
	get_number_of_foes(core);
	return (true);
}
