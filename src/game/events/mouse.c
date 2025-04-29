/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 03:13:52 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/29 03:37:40 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_menu_hover(int x, int y, void *param)
{
	t_core		*core;
	int			i;

	(void)x;
	core = (t_core *)param;
	i = 0;
	while (i < 4)
	{
		if (y >= core->y_pos[i] && y < core->y_pos[i] + MENU_SPACING)
		{
			if (core->menu_option != i)
			{
				core->menu_option = i;
				core->redraw = true;
			}
			break ;
		}
		i++;
	}
	return (0);
}
