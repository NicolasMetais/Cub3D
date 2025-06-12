/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:12:36 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/07 18:12:47 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	horizontal_cast(t_core *core)
{
	int	i;

	i = 0;
	core->tmp_rc->atan = -1 / tan(core->tmp_rc->ra);
	if (core->tmp_rc->ra > PI)
	{
		core->tmp_rc->ry = (((int)core->tmp_rc->pl_y >> 3) << 3) -0.0001;
		core->tmp_rc->rx = (core->tmp_rc->pl_y - core->tmp_rc->ry) * core->tmp_rc->atan + core->tmp_rc->pl_x;
		core->tmp_rc->y = -8;
		core->tmp_rc->x = -core->tmp_rc->y * core->tmp_rc->atan;
	}
	if (core->tmp_rc->ra < PI)
	{
		core->tmp_rc->ry = (((int)core->tmp_rc->pl_y >> 3) << 3) + 8;
		core->tmp_rc->rx = (core->tmp_rc->pl_y - core->tmp_rc->ry) * core->tmp_rc->atan + core->tmp_rc->pl_x;
		core->tmp_rc->y = 8;
		core->tmp_rc->x = -core->tmp_rc->y * core->tmp_rc->atan;
	}
	if (core->tmp_rc->ra == 0 || core->tmp_rc->ra == PI)
	{
		core->tmp_rc->rx = core->tmp_rc->pl_x;
		core->tmp_rc->ry = core->tmp_rc->pl_y;
		i = core->map_height;
	}
	loop_tiles_height(core, i);
}

void	vertical_cast(t_core *core)
{
	int	i;

	i = 0;
	core->tmp_rc->ntan = -tan(core->tmp_rc->ra);
	if (core->tmp_rc->ra > PI / 2 && core->tmp_rc->ra < 3 * PI / 2)
	{
		core->tmp_rc->rx = (((int)core->tmp_rc->pl_x >> 3) << 3) - 0.0001;
		core->tmp_rc->ry = (core->tmp_rc->pl_x - core->tmp_rc->rx) * core->tmp_rc->ntan + core->tmp_rc->pl_y;
		core->tmp_rc->x = -8;
		core->tmp_rc->y = -core->tmp_rc->x * core->tmp_rc->ntan;
	}
	if (core->tmp_rc->ra < PI / 2 || core->tmp_rc->ra > 3 * PI / 2)
	{
		core->tmp_rc->rx = (((int)core->tmp_rc->pl_x >> 3) << 3) + 8;
		core->tmp_rc->ry = (core->tmp_rc->pl_x - core->tmp_rc->rx) * core->tmp_rc->ntan + core->tmp_rc->pl_y;
		core->tmp_rc->x = 8;
		core->tmp_rc->y = -core->tmp_rc->x * core->tmp_rc->ntan;
	}
	if (core->tmp_rc->ra == 0 || core->tmp_rc->ra == PI)
	{
		core->tmp_rc->rx = core->tmp_rc->pl_x;
		core->tmp_rc->ry = core->tmp_rc->pl_y;
		i = core->map_width;
	}
	loop_tiles_width(core, i);
}

static void get_good_dist(t_core *core)
{
	if (core->tmp_rc->dist[core->tmp_rc->r] > core->tmp_rc->dist2[core->tmp_rc->r])
	{
		core->tmp_rc->rx = core->tmp_rc->vx;
		core->tmp_rc->ry = core->tmp_rc->vy;
		core->tmp_rc->dist3[core->tmp_rc->r] = core->tmp_rc->dist2[core->tmp_rc->r];
		core->tmp_rc->was_vertical = 1;
	}
	else
	{
		core->tmp_rc->rx = core->tmp_rc->hx;
		core->tmp_rc->ry = core->tmp_rc->hy;
		core->tmp_rc->dist3[core->tmp_rc->r] = core->tmp_rc->dist[core->tmp_rc->r];
		core->tmp_rc->was_vertical = 0;
	}
}

void	get_raycast_data(t_core *core)
{
	core->tmp_rc->ra = core->tmp_rc->pl_angle - RAD * ((core->fov) / 2);
	if (core->tmp_rc->ra < 0)
		core->tmp_rc->ra += 2 * PI;
	if (core->tmp_rc->ra > 2 * PI)
		core->tmp_rc->ra -= 2 * PI;
	core->tmp_rc->r = 0;
	while (core->tmp_rc->r < core->tmp_rc->max_r)
	{
		horizontal_cast(core);
		core->tmp_rc->dist[core->tmp_rc->r] = sqrt((core->tmp_rc->rx - core->tmp_rc->pl_x) * (core->tmp_rc->rx - core->tmp_rc->pl_x) + \
		(core->tmp_rc->ry - core->tmp_rc->pl_y) * (core->tmp_rc->ry - core->tmp_rc->pl_y));
		vertical_cast(core);
		core->tmp_rc->dist2[core->tmp_rc->r] = sqrt((core->tmp_rc->rx - core->tmp_rc->pl_x) * (core->tmp_rc->rx - core->tmp_rc->pl_x) + \
		(core->tmp_rc->ry - core->tmp_rc->pl_y) * (core->tmp_rc->ry - core->tmp_rc->pl_y));
		get_good_dist(core);
		//print_rays(core, 0xFFFF00);
		core->tmp_rc->ca = core->tmp_rc->ra - core->tmp_rc->pl_angle;
		if (core->tmp_rc->ca < -PI)
			core->tmp_rc->ca += 2 * PI;
		if (core->tmp_rc->ca > PI)
			core->tmp_rc->ca -= 2 * PI;
		core->tmp_rc->dist3[core->tmp_rc->r] = core->tmp_rc->dist3[core->tmp_rc->r] * (cos(core->tmp_rc->ca)); 
		draw_3d(core);
		rays_updates(core);
	}
}

void	get_rc_data(t_core *core)
{
	core->tmp_3d = malloc(sizeof(t_tmp_3d));
	if (!core->tmp_3d)
		return ;
	core->tmp_rc = malloc(sizeof(*core->tmp_rc));
	if (!core->tmp_rc)
		return ;
	core->tmp_rc->pl_x = core->spawn->x * 8;
	core->tmp_rc->pl_y = core->spawn->y * 8;
	core->tmp_rc->pl_angle = 2 * PI;
	core->tmp_rc->pldelt_x = cos(core->tmp_rc->pl_angle);
	core->tmp_rc->pldelt_y = sin(core->tmp_rc->pl_angle);
	core->tmp_rc->res = 16;
	core->tmp_rc->max_r = S_LENGHT;
	core->tmp_rc->dist = gc_malloc(&core->gc, sizeof(float) * core->tmp_rc->max_r, FLOAT, "dist");
	core->tmp_rc->dist2 = gc_malloc(&core->gc, sizeof(float) * core->tmp_rc->max_r, FLOAT, "dist2");
	core->tmp_rc->dist3 = gc_malloc(&core->gc, sizeof(float) * core->tmp_rc->max_r, FLOAT, "dist3");
	if (!core->tmp_rc->dist || !core->tmp_rc->dist2 || !core->tmp_rc->dist3)
		return ;
}
