/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loaded_anim.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:50:13 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/12 18:50:20 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	update_loaded_anim_state(t_weapon *weapon, t_sprite *sprite,
			bool hold, t_core *core)
{
	if (hold)
	{
		if (sprite->img_list == weapon->loop_loaded)
			sprite->img_list = weapon->loop_loaded->next;
		else
			sprite->img_list = weapon->loop_loaded;
		fire_charged_weapons(core);
		return (true);
	}
	if (sprite->img_list->next == sprite->head)
	{
		sprite->img_list = sprite->head;
		sprite->activ = false;
	}
	else
		sprite->img_list = sprite->img_list->next;
	return (false);
}

bool	update_loaded_animation(t_weapon *weapon, t_sprite *sprite,
			bool hold, t_core *core)
{
	struct timeval	current;
	long			elapsed;

	if (!sprite->activ)
		return (false);
	gettimeofday(&current, NULL);
	elapsed = (current.tv_sec - sprite->update.tv_sec) * 1000
		+ (current.tv_usec - sprite->update.tv_usec) / 1000;
	if (elapsed < sprite->speed)
		return (false);
	sprite->update = current;
	if (!sprite->started && sprite->img_list->next)
	{
		sprite->img_list = sprite->img_list->next;
		sprite->started = true;
		return (true);
	}
	return (update_loaded_anim_state(weapon, sprite, hold, core));
}
