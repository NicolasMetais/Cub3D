/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:53:24 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/27 17:00:38 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int key, void *param)
{
	t_core	*core;

	core = (t_core *)param;
	if (key == XK_Escape)
		handle_destroy(core);
	else if (key == 65361 || key == 'a')
		move_player(core, LEFT);
	else if (key == 65363 || key == 'd')
		move_player(core, RIGHT);
	else if (key == 65362 || key == 'w')
		move_player(core, UP);
	else if (key == 65364 || key == 's')
		move_player(core, DOWN);
	return (true);
}
