/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_impacts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:41:23 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/13 16:02:09 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	setup_proj_impacts(t_core *core, t_pos pos, t_projectile_node *proj)
{
	if (!new_impact(core, pos.x, pos.y, proj->wpn_type))
		return (false);
	if (proj->prev)
		proj->prev->next = proj->next;
	else
		core->proj.proj_list = proj->next;
	if (proj->next)
		proj->next->prev = proj->prev;
	free(proj);
	return (true);
}

void	delete_impact(t_core *core,
			t_impact_node **current, t_impact_node **prev)
{
	t_impact_node	*tmp;

	if ((*current)->lifetime-- <= 0)
	{
		if ((*current)->frame++ < (*current)->sprite->nb - 1)
		{
			(*current)->activ_img = (*current)->activ_img->next;
			(*current)->lifetime = 15;
			*prev = *current;
			*current = (*current)->next;
			return ;
		}
		tmp = *current;
		if (!*prev)
			core->impact.impact_list = (*current)->next;
		else
			(*prev)->next = (*current)->next;
		*current = (*current)->next;
		free(tmp);
	}
	else
	{
		*prev = *current;
		*current = (*current)->next;
	}
}

void	draw_impact(t_core *core, t_impact_node *current)
{
	float	impact_size;

	impact_size = current->size;
	core->impact.factor = tanf(core->impact.angle)
		/ tanf(core->impact.fov_rad / 2.0f);
	core->impact.screen_x = (int)S_LENGHT / 2
		+ core->impact.factor * (S_LENGHT / 2);
	core->impact.size = (int)(S_HEIGHT * impact_size / core->impact.dist);
	if (core->impact.size > 0 && core->impact.screen_x >= 0
		&& core->impact.screen_x < S_LENGHT)
	{
		if (core->impact.dist
			- core->tmp_rc->dist3[core->impact.screen_x] <= 1.0f)
			transparency_scaled(core->game_img,
				current->activ_img->image,
				(t_pos){(core->impact.screen_x - core->impact.size / 2),
				(S_HEIGHT / 2) - (core->impact.size / 2)}, core->impact.size);
	}
}

void	setup_draw_impact(t_core *core, t_impact_node *current)
{
	core->impact.x = current->x - core->tmp_rc->pl_x;
	core->impact.y = current->y - core->tmp_rc->pl_y;
	core->impact.dist = sqrtf(core->impact.x * core->impact.x
			+ core->impact.y * core->impact.y);
	core->impact.angle = atan2(core->impact.y, core->impact.x)
		- core->tmp_rc->pl_angle;
	if (core->impact.angle < -PI)
		core->impact.angle += 2 * PI;
	if (core->impact.angle > PI)
		core->impact.angle -= 2 * PI;
	core->impact.dist = core->impact.dist * cosf(core->impact.angle);
	if (fabs(core->impact.angle) < (core->impact.fov_rad / 2.0f))
		draw_impact(core, current);
}

//sqrtf = square root
void	impacts(t_core *core)
{
	t_impact_node	*current;
	t_impact_node	*prev;

	core->impact.fov_rad = core->fov * (PI / 180.0);
	prev = NULL;
	current = core->impact.impact_list;
	while (current)
	{
		setup_draw_impact(core, current);
		delete_impact(core, &current, &prev);
	}
}
