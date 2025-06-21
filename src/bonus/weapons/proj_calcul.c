/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_calcul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:54:38 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/21 16:55:42 by nmetais          ###   ########.fr       */
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

static bool	handle_projectile_movement(t_core *core, t_projectile_node *proj)
{
	t_pos	old;
	t_pos	new;
	t_pos	col;

	old = (t_pos){proj->x, proj->y};
	new = (t_pos){proj->x + cosf(proj->angle) * proj->speed,
		proj->y + sinf(proj->angle) * proj->speed};
	if (is_colliding(old, new, core, &col))
	{
		proj->x = col.x;
		proj->y = col.y;
		if (!setup_proj_impacts(core, col, proj))
			return (false);
	}
	else
	{
		proj->x = new.x;
		proj->y = new.y;
	}
	return (true);
}

bool	update_projectiles(t_core *core)
{
	t_projectile_node	*proj;

	proj = core->proj.proj_list;
	while (proj)
	{
		if (!handle_projectile_movement(core, proj))
			return (false);
		projectile_animation(proj);
		proj = proj->next;
	}
	return (true);
}
