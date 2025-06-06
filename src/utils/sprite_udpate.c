/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_udpate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 03:53:57 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/06 10:57:00 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//UPDATE THE SPRITE EVERY X MILISEC LIKE PHILOSOPHER
bool	update_sprite(t_sprite *sprite)
{
	struct timeval			current;
	long					elapsed;

	gettimeofday(&current, NULL);
	elapsed = (current.tv_sec - sprite->update.tv_sec) * 1000
		+ (current.tv_usec - sprite->update.tv_usec) / 1000;
	if (elapsed >= sprite->speed)
	{
		sprite->img_list = sprite->img_list->next;
		sprite->update = current;
		return (true);
	}
	return (false);
}

bool	update_loaded_animation(t_weapon *weapon, t_sprite *sprite, bool hold, t_core *core)
{
	struct timeval			current;
	long					elapsed;

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

//pas utilisee
bool	update_weapons_animation(t_sprite *sprite)
{
	struct timeval			current;
	long					elapsed;

	if (!sprite->activ)
		return (false);
	gettimeofday(&current, NULL);
	elapsed = (current.tv_sec - sprite->update.tv_sec) * 1000
		+ (current.tv_usec - sprite->update.tv_usec) / 1000;
	if (elapsed >= sprite->speed)
	{
		sprite->img_list = sprite->img_list->next;
		sprite->update = current;
		if (sprite->started && sprite->img_list == sprite->head)
			sprite->activ = false;
		return (true);
	}
	return (false);
}

bool	update_animation(t_sprite *sprite)
{
	struct timeval			current;
	long					elapsed;

	if (!sprite->activ)
		return (false);
	gettimeofday(&current, NULL);
	elapsed = (current.tv_sec - sprite->update.tv_sec) * 1000
		+ (current.tv_usec - sprite->update.tv_usec) / 1000;
	if (elapsed >= sprite->speed)
	{
		sprite->img_list = sprite->img_list->next;
		sprite->update = current;
		if (sprite->started && sprite->img_list == sprite->head)
			sprite->activ = false;
		return (true);
	}
	return (false);
}

//UPDATE THE SPRITE EVERY X MILISEC LIKE PHILOSOPHER WITH A RANDOM FRAM
bool	update_sprite_random(t_sprite *sprite)
{
	struct timeval			current;
	long					elapsed;
	int						random;
	int						i;

	i = -1;
	gettimeofday(&current, NULL);
	elapsed = (current.tv_sec - sprite->update.tv_sec) * 1000
		+ (current.tv_usec - sprite->update.tv_usec) / 1000;
	random = rand() % sprite->nb;
	if (elapsed >= sprite->speed)
	{
		while (++i < random)
			sprite->img_list = sprite->img_list->next;
		sprite->update = current;
		return (true);
	}
	return (false);
}
