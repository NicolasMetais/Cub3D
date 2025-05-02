/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_udpate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 03:53:57 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/30 00:18:31 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//UPDATE THE SPRITE EVERY X MILISEC LIKE PHILOSOPHER
bool	update_sprite(t_sprite *sprite)
{
	static struct timeval	save_time = {0};
	struct timeval			current;
	long					elapsed;

	gettimeofday(&current, NULL);
	elapsed = (current.tv_sec - save_time.tv_sec) * 1000
		+ (current.tv_usec - save_time.tv_usec) / 1000;

	if (elapsed >= sprite->speed)
	{
		sprite->frame = (sprite->frame + 1) % sprite->nb;
		save_time = current;
		return (true);
	}
	return (false);
}
