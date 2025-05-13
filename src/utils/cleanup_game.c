/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 02:08:56 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/13 14:13:01 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup_game(t_core *core)
{
	destroy_img(core);
	if (core->mlx)
		mlx_destroy_window(core->mlx, core->win);
	free_gc(core->gc, NULL);
}
