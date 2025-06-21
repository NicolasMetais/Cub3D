/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:10:08 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/21 16:14:18 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	seconds(void)
{
	struct timeval	sec;

	gettimeofday(&sec, NULL);
	return ((double)(sec.tv_sec) + (double)sec.tv_usec / 1000000.0f);
}

void	movements(t_core *core)
{
	double			current_time;

	current_time = seconds();
	if (core->player->last_time == 0.0)
		core->player->delta_time = 0.0;
	else
		core->player->delta_time = current_time - core->player->last_time;
	core->player->last_time = current_time;
	game_keypress(core, core->player->delta_time);
}

void	calculate_bob(t_core *core, double ampli, double freq)
{
	core->player->bobbing_speed = 2.0 * PI * freq;
	core->player->bob_y = ampli * sin(core->player->bobbing_speed
			* core->player->bobbing_time);
	core->player->bob_x = (ampli / 2.0)
		* sin(core->player->bobbing_speed * 2.0 * core->player->bobbing_time);
}
