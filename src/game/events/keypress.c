/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:53:24 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/28 03:12:47 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int key, void *param)
{
	t_core	*core;

	core = (t_core *)param;
	if (key == XK_Escape)
		handle_destroy(core);
	if (core->state == MENU)
	{
		if (key == XK_Up)
		{
			if (core->menu_option > 0)
				core->menu_option--;
			else
				core->menu_option = 3;
		}
		else if (key == XK_Down)
		{
			if (core->menu_option < 3)
				core->menu_option++;
			else
				core->menu_option = 0;
		}
		render_menu(core);
	}
	return (true);
}
