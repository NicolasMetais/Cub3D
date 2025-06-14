/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_mecanics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:27:18 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/13 16:02:19 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	shoot_pistol(t_core *core, float angle)
{
	t_pos	pos;
	float	fire;

	fire = 0.0;
	while (fire < 9999)
	{
		pos.x = core->rc->pl_x + cos(angle) * (fire - 0.1);
		pos.y = core->rc->pl_y + sin(angle) * (fire - 0.1);
		if (iswall(pos, core))
		{
			if (!new_impact(core, pos.x, pos.y, 2))
				return (false);
			break ;
		}
		fire += 0.1;
	}
	return (true);
}

bool	shoot_projectile(t_core *core, float angle)
{
	t_pos	pos;

	pos.x = core->rc->pl_x + cos(angle) * 3;
	pos.y = core->rc->pl_y + sin(angle) * 3;
	if (!new_proj(core, pos.x, pos.y, angle))
		return (false);
	return (true);
}

bool	shoot_shotgun(t_core *core)
{
	int		i;
	double	spread;
	double	step;
	double	starting_angle;
	double	angle;

	spread = 10 * (PI / 180.0);
	step = spread / (7 - 1);
	starting_angle = core->rc->pl_angle - (spread / 2.0);
	i = -1;
	while (++i < 7)
	{
		angle = starting_angle + i * step;
		shoot_pistol(core, angle);
	}
	return (true);
}
