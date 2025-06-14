/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:49:25 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/13 00:22:43 by nmetais          ###   ########.fr       */
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

//WHOLE GAME ROUTINE
int	routine(void *param)
{
	t_core		*core;

	core = (t_core *)param;
	if (core->state == GAME)
	{
		core->rc->max_r = S_LENGHT;
		movements(core);
		if (core->redraw == true)
			start_game(core);
	}
	core->redraw = false;
	return (0);
}
