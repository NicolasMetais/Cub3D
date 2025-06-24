/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_foes_utils_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:18:07 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/24 14:54:36 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	randomized_spawns(t_core *core)
{
	int	x;
	int	y;
	int	i;
	int	foes;

	x = 0;
	i = 0;
	srand(time(NULL));
	foes = foes_to_create(core);
	while (x < core->map_height)
	{
		y = 0;
		while (y < core->map_width)
		{
			if (core->map[x][y] == '0' && ((rand() % 32) == 1))
			{
				core->map[x][y] = 'F';
				i++;
				if (i == foes)
					return ;
			}
			y++;
		}
		x++;
	}
}

t_sprite	*copy_sprite(t_core *core, t_sprite *src, int i)
{
	t_sprite	*new_sprite;

	if (!src)
		return (NULL);
	new_sprite = gc_malloc(&core->gc, \
	sizeof(t_sprite), STRUCT, "new_sprite_foe");
	if (!new_sprite)
		return (NULL);
	new_sprite->nb = src->nb;
	new_sprite->speed = src->speed;
	new_sprite->timer = 0;
	new_sprite->img_list = gc_malloc(&core->gc, \
	sizeof(t_node_img), STRUCT, "copy_sprite_foe");
	if (!new_sprite->img_list)
		return (NULL);
	new_sprite->nb = i;
	new_sprite->img_list = src->img_list;
	return (new_sprite);
}

bool	can_see_player(t_core *core, float ex, float ey)
{
	float	dx;
	float	dy;
	float	dist;
	int		i;

	dx = core->rc->pl_y - ex;
	dy = core->rc->pl_x - ey;
	dist = sqrtf(dx * dx + dy * dy);
	i = 0;
	while (i < (int)dist)
	{
		if (seen_colision(core, (int)(ex / 8), (int)(ey / 8)))
			return (false);
		ex += dx / dist;
		ey += dy / dist;
		i++;
	}
	return (true);
}
