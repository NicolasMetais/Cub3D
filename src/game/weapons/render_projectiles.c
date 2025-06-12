/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_projectiles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:28:02 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/12 18:47:13 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	projectile_animation(t_projectile_node *proj)
{
	struct timeval	current;
	long			elapsed;

	gettimeofday(&current, NULL);
	elapsed = (current.tv_sec - proj->timer.tv_sec) * 1000
		+ (current.tv_usec - proj->timer.tv_usec) / 1000;
	if (elapsed > 250)
	{
		if (proj->activ_img->next)
			proj->activ_img = proj->activ_img->next;
		else
			proj->activ_img = proj->sprite->img_list;
		proj->timer = current;
	}
}

bool	update_projectiles(t_core *core)
{
	t_projectile_node	*proj;
	t_projectile_node	*prev;
	t_projectile_node	*next;
	t_pos				pos;

	prev = NULL;
	proj = core->proj.proj_list;
	while (proj)
	{
		next = proj->next;
		proj->x += cosf(proj->angle) * proj->speed;
		proj->y += sinf(proj->angle) * proj->speed;
		pos.x = proj->x + proj->dir_x;
		pos.y = proj->y + proj->dir_y;
		if (is_colliding(pos, core))
		{
			if (!setup_proj_impacts(core, pos, proj))
				return (false);
		}
		projectile_animation(proj);
		proj = next;
	}
	return (true);
}

void	draw_projectile(t_core *core, t_projectile_node *proj, float angle_diff)
{
	float	dist;
	float	corr;
	float	size;
	t_pos	pos;

	dist = sqrtf(core->proj.dx * core->proj.dx + core->proj.dy * core->proj.dy);
	corr = dist * cosf(angle_diff);
	size = (int)((4 * (S_HEIGHT / (2.0f
						* tanf(core->proj.fov_rad / 2.0f)))) / corr);
	pos.x = (int)((angle_diff / core->proj.fov_rad + 0.5f)
			* S_LENGHT) - size / 2;
	pos.y = S_HEIGHT / 2 - size / 2;
	transparency_scaled(core->game_img, proj->activ_img->image,
		pos, size);
}

void	calculation_proj(t_core *core, t_projectile_node *proj)
{
	float	angle_diff;

	core->proj.fov_rad = core->fov * (PI / 180.0);
	core->proj.dx = proj->x - core->tmp_rc->pl_x;
	core->proj.dy = proj->y - core->tmp_rc->pl_y;
	core->proj.angle = atan2(core->proj.dy, core->proj.dx);
	angle_diff = core->proj.angle - core->tmp_rc->pl_angle;
	if (angle_diff < -PI)
		angle_diff += 2 * PI;
	if (angle_diff > PI)
		angle_diff -= 2 * PI;
	if (fabs(angle_diff) < core->proj.fov_rad / 2.0)
		draw_projectile(core, proj, angle_diff);
}

void	render_projectiles(t_core *core)
{
	t_projectile_node	*proj;
	t_projectile_node	*prev;

	prev = NULL;
	proj = core->proj.proj_list;
	while (proj)
	{
		calculation_proj(core, proj);
		proj = proj->next;
	}
}
