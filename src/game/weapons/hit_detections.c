/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_detections.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:51:43 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/06 11:57:19 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_colliding(t_pos pos, t_core *core)
{
	int		dx;
	int		dy;
	t_pos	test;

	dy = -1;
	while (dy++ <= 1)
	{
		dx = -1;
		while (dx++ <= 1)
		{
			test.x = pos.x + dx;
			test.y = pos.y + dy;
			if (iswall(test, core))
				return (true);
		}
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
		|| core->map[(int)pos_y][(int)pos_x] == ' ')
	{
		return (true);
	}
	return (false);
}
