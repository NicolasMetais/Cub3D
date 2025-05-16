/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:34:06 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/16 13:15:31 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_menu_release(int button, int x, int y, t_core *core)
{
	(void)x;
	(void)y;
	if (core->state == OPTIONS_MENU)
	{
		if (button == 1)
			core->isclicked = 0;
	}
	return (0);
}
