/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 02:08:56 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/13 02:16:30 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_impact(t_core *core)
{
	t_impact_node	*temp;

	while (core->impact.impact_list)
	{
		temp = core->impact.impact_list;
		core->impact.impact_list = core->impact.impact_list->next;
		free(temp);
	}
}

void	cleanup_game(t_core *core)
{
	free_impact(core);
	//free projectiles ossi
	destroy_img(core);
	if (core->mlx && core->win)
		mlx_destroy_window(core->mlx, core->win);
	if (core->mlx)
		mlx_destroy_display(core->mlx);
	free_gc(core->gc, NULL);
	exit(0);
}
