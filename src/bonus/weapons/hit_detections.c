/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_detections.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:51:43 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/24 17:45:04 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_colliding(t_pos start, t_pos end, t_core *core, t_pos *collision)
{
	float	dist;
	int		steps;
	t_pos	d;
	t_pos	norm;
	int		i;

	dist = hypotf(end.x - start.x, end.y - start.y);
	steps = (int)(dist / 0.1f);
	d.x = (end.x - start.x) / steps;
	d.y = (end.y - start.y) / steps;
	i = 1;
	while (i <= steps)
	{
		norm.x = start.x + d.x * i;
		norm.y = start.y + d.y * i;
		if (iswall(norm, core))
		{
			if (collision)
				*collision = norm;
			return (true);
		}
		i++;
	}
	return (false);
}

bool	iswall(t_pos pos, t_core *core)
{
	int	pos_x;
	int	pos_y;

	pos_x = pos.x / 8;
	pos_y = pos.y / 8;
	if (pos_x < 0 || pos_y < 0 || pos_x >= core->map_width
		|| pos_y >= core->map_height)
		return (true);
	if (core->map[(int)pos_y][(int)pos_x] == '1'
		|| core->map[(int)pos_y][(int)pos_x] == ' '
		|| core->map[(int)pos_y][(int)pos_x] == '2'
		|| core->map[(int)pos_y][(int)pos_x] == '4'
		|| core->map[(int)pos_y][(int)pos_x] == '5'
		|| core->map[(int)pos_y][(int)pos_x] == '6'
		|| core->map[(int)pos_y][(int)pos_x] == '7'
		|| is_enemy(core, pos.x, pos.y))
	{
		return (true);
	}
	return (false);
}
