/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:12:36 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/21 20:07:46 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	horizontal_cast(t_core *core)
{
	int	i;

	i = 0;
	core->rc->atan = -1 / tan(core->rc->ra);
	if (core->rc->ra > PI)
	{
		core->rc->ry = (((int)core->rc->pl_y >> 3) << 3) - 0.0001;
		core->rc->rx = (core->rc->pl_y - core->rc->ry) \
		* core->rc->atan + core->rc->pl_x;
		core->rc->y = -8;
		core->rc->x = -core->rc->y * core->rc->atan;
	}
	if (core->rc->ra < PI)
	{
		core->rc->ry = (((int)core->rc->pl_y >> 3) << 3) + 8;
		core->rc->rx = (core->rc->pl_y - core->rc->ry) \
		* core->rc->atan + core->rc->pl_x;
		core->rc->y = 8;
		core->rc->x = -core->rc->y * core->rc->atan;
	}
	if (core->rc->ra == 0 || core->rc->ra == PI)
	{
		core->rc->rx = core->rc->pl_x;
		core->rc->ry = core->rc->pl_y;
		i = core->map_height;
	}
	loop_tiles_height(core, i);
}

void	vertical_cast(t_core *core)
{
	int	i;

	i = 0;
	core->rc->ntan = -tan(core->rc->ra);
	if (core->rc->ra > PI / 2 && core->rc->ra < 3 * PI / 2)
	{
		core->rc->rx = (((int)core->rc->pl_x >> 3) << 3) - 0.0001;
		core->rc->ry = (core->rc->pl_x - core->rc->rx) \
		* core->rc->ntan + core->rc->pl_y;
		core->rc->x = -8;
		core->rc->y = -core->rc->x * core->rc->ntan;
	}
	if (core->rc->ra < PI / 2 || core->rc->ra > 3 * PI / 2)
	{
		core->rc->rx = (((int)core->rc->pl_x >> 3) << 3) + 8;
		core->rc->ry = (core->rc->pl_x - core->rc->rx) \
		* core->rc->ntan + core->rc->pl_y;
		core->rc->x = 8;
		core->rc->y = -core->rc->x * core->rc->ntan;
	}
	if (core->rc->ra == 0 || core->rc->ra == PI)
	{
		core->rc->rx = core->rc->pl_x;
		core->rc->ry = core->rc->pl_y;
		i = core->map_width;
	}
	loop_tiles_width(core, i);
}

static void	get_good_dist(t_core *core)
{
	if (core->rc->dist[core->rc->r] > core->rc->dist2[core->rc->r])
	{
		core->rc->rx = core->rc->vx;
		core->rc->ry = core->rc->vy;
		core->rc->dist3[core->rc->r] = core->rc->dist2[core->rc->r];
		core->rc->was_vertical = 1;
		core->rc->hit_wall = core->rc->v_wall;
	}
	else
	{
		core->rc->rx = core->rc->hx;
		core->rc->ry = core->rc->hy;
		core->rc->dist3[core->rc->r] = core->rc->dist[core->rc->r];
		core->rc->was_vertical = 0;
		core->rc->hit_wall = core->rc->h_wall;
	}
	if (core->rc->r == core->rc->max_r / 2)
	{
		core->rc->front_wall = core->rc->hit_wall;
		core->rc->front_x = (int)core->rc->rx / 8;
		core->rc->front_y = (int)core->rc->ry / 8;
	}
}

void	get_raycast_data(t_core *core)
{
	core->rc->ra = core->rc->pl_angle - RAD * ((core->fov) / 2);
	if (core->rc->ra < 0)
		core->rc->ra += 2 * PI;
	if (core->rc->ra > 2 * PI)
		core->rc->ra -= 2 * PI;
	core->rc->r = 0;
	while (core->rc->r < core->rc->max_r)
	{
		horizontal_cast(core);
		core->rc->dist[core->rc->r] = sqrt((core->rc->rx - core->rc->pl_x) \
		* (core->rc->rx - core->rc->pl_x) + \
		(core->rc->ry - core->rc->pl_y) * (core->rc->ry - core->rc->pl_y));
		vertical_cast(core);
		core->rc->dist2[core->rc->r] = sqrt((core->rc->rx - core->rc->pl_x) \
		* (core->rc->rx - core->rc->pl_x) + \
		(core->rc->ry - core->rc->pl_y) * (core->rc->ry - core->rc->pl_y));
		get_good_dist(core);
		print_rays(core, 0xFFFF00);
		core->rc->ca = core->rc->ra - core->rc->pl_angle;
		if (core->rc->ca < -PI)
			core->rc->ca += 2 * PI;
		if (core->rc->ca > PI)
			core->rc->ca -= 2 * PI;
		core->rc->dist3[core->rc->r] = core->rc->dist3[core->rc->r] \
		* (cos(core->rc->ca));
		draw_3d(core);
		rays_updates(core);
	}
}

bool	rc_init(t_core *core)
{
	core->rc3d = gc_malloc(&core->gc, sizeof(t_rc3d), STRUCT, "struct 3d");
	if (!core->rc3d)
		return (false);
	core->rc = gc_malloc(&core->gc, sizeof(t_rc), STRUCT, "struct rc");
	if (!core->rc)
		return (false);
	core->rc->pl_x = core->spawn->x * 8 + 4;
	core->rc->pl_y = core->spawn->y * 8 + 4;
	core->rc->pl_angle = get_player_start(core);
	core->rc->pldelt_x = cos(core->rc->pl_angle);
	core->rc->pldelt_y = sin(core->rc->pl_angle);
	core->rc->res = 16;
	core->rc->max_r = S_LENGHT;
	core->rc->dist = gc_malloc(&core->gc, sizeof(float) \
	* core->rc->max_r, FLOAT, "dist");
	core->rc->dist2 = gc_malloc(&core->gc, sizeof(float) \
	* core->rc->max_r, FLOAT, "dist2");
	core->rc->dist3 = gc_malloc(&core->gc, sizeof(float) \
	* core->rc->max_r, FLOAT, "dist3");
	if (!core->rc->dist || !core->rc->dist2 || !core->rc->dist3)
		return (false);
	return (true);
}
