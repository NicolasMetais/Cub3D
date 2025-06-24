/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:53:24 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/23 22:44:04 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//KEYBOARD MANAGEMENT
int	handle_keypress(int key, void *param)
{
	t_core	*core;

	core = (t_core *)param;
	if (key == XK_Escape)
		cleanup_game(core);
	if (core->state == GAME)
		on_keypress_game(key, core);
	return (true);
}
