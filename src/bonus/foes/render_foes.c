/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_foes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:11:27 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/23 20:56:18 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_render(t_core *core, t_foes *enemy, t_pos start)
{
	if (enemy->dist < core->rc->dist3[enemy->screen_x] && enemy->death == 0)
		transparency_scaled(core->game_img, enemy->activ_img->image, \
		start, enemy->sprite_size);
	else if (enemy->dist < core->rc->dist3[enemy->screen_x] && \
		enemy->atk == 1 && enemy->death == 0)
		transparency_scaled(core->game_img, enemy->activ_img->image, \
		start, enemy->sprite_size);
	else if (enemy->dist < core->rc->dist3[enemy->screen_x] && \
		enemy->death == 1)
		transparency_scaled(core->game_img, enemy->activ_img->image, \
		start, enemy->sprite_size);
	else if (enemy->dist < core->rc->dist3[enemy->screen_x] && \
		enemy->death == 2 && enemy->type != 5)
		transparency_scaled(core->game_img, enemy->img_body, \
		start, enemy->sprite_size);
}

static void	update_foe_angle(t_core *core, t_foes *enemy)
{
	enemy->angle_to_foe = atan2(enemy->dy, enemy->dx);
	if (enemy->angle_to_foe < -PI)
		enemy->angle_to_foe += 2 * PI;
	if (enemy->angle_to_foe > PI)
		enemy->angle_to_foe -= 2 * PI;
	enemy->rel_angle = enemy->angle_to_foe - core->rc->pl_angle;
	if (enemy->rel_angle < -PI)
		enemy->rel_angle += 2 * PI;
	if (enemy->rel_angle > PI)
		enemy->rel_angle -= 2 * PI;
	enemy->dist -= cos(enemy->rel_angle);
}

static void	get_enemy_start_info(t_core *core, t_foes *enemy)
{
	while (enemy)
	{
		enemy->dx = enemy->foe_x - core->rc->pl_x;
		enemy->dy = enemy->foe_y - core->rc->pl_y;
		enemy->dist = sqrt(enemy->dx * enemy->dx + enemy->dy * enemy->dy);
		enemy = enemy->next;
	}
	anim_walk_foe(core);
	anim_attack_foe(core);
	anim_death_foe(core);
	sort_enemies_by_distance(&core->foes);
}

void	render_foes(t_core *core)
{
	t_pos	start;
	t_foes	*enemy;

	enemy = core->foes;
	get_enemy_start_info(core, enemy);
	enemy = core->foes;
	while (enemy)
	{
		update_foe_angle(core, enemy);
		enemy->screen_x = (enemy->rel_angle / (core->fov * RAD)) \
		* S_LENGHT + (S_LENGHT / 2);
		enemy->sprite_size = (int)(S_HEIGHT / enemy->dist) * 8;
		start.x = enemy->screen_x - enemy->sprite_size / 2;
		start.y = (S_HEIGHT / 2) - (enemy->sprite_size / 4);
		if (enemy->screen_x >= 0 && enemy->screen_x < S_LENGHT)
			get_render(core, enemy, start);
		enemy = enemy->next;
	}
	update_foes(core);
	if (all_dead(core->foes))
		revive_all(core->foes);
}
