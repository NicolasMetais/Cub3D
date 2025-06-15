/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_pause_options.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:47:28 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/15 18:07:24 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pause_option_keypress(int key, t_core *core)
{
	if (key == XK_BackSpace)
	{
		core->state = PAUSE;
		core->menu_option = 1;
		render_pause_menu(core);
	}
}
