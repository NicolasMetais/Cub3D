/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_notifs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:49:14 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/21 15:11:18 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	notif_init(t_core *core)
{
	t_img	*bigger_notif;

	bigger_notif = hashmap_get(&core->hashmap, "Notif_rocket");
	if (!bigger_notif)
		return (false);
	core->notif_buffer = load_buffer(core->notif_buffer,
			bigger_notif->width, bigger_notif->height, core);
	if (!core->notif_buffer)
		return (false);
	return (true);
}

void	render_notifs(t_core *core)
{
	struct timeval	now;
	long			seconds;
	long			useconds;
	long			elapsed_ms;
	int				width;

	if (!core->isnotif)
		return ;
	gettimeofday(&now, NULL);
	seconds = now.tv_sec - core->notif_timer.tv_sec;
	useconds = now.tv_usec - core->notif_timer.tv_usec;
	elapsed_ms = (seconds * 1000) + (useconds / 1000);
	if (elapsed_ms >= 5000)
	{
		core->isnotif = false;
		core->notif = NULL;
	}
	else if (core->notif)
	{
		width = S_LENGHT - core->notif->width;
		partial_copy_img(core->notif_buffer, core->game_img, width, 0);
		transparency(core->notif_buffer, core->notif, 0, 0);
		mlx_put_image_to_window(core->mlx, core->win,
			core->notif_buffer->img, width, 0);
	}
}

bool	new_notifs(t_core *core, t_item item)
{
	t_img	*notif;

	notif = hashmap_get(&core->hashmap, item.notif);
	if (!notif)
		return (false);
	core->notif = notif;
	core->isnotif = true;
	gettimeofday(&core->notif_timer, NULL);
	return (true);
}
