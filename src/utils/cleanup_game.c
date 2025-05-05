/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 02:08:56 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/04 02:10:06 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup_game(t_core *core)
{
	mlx_destroy_window(core->mlx, core->win);
	free_gc(core->gc, NULL);
	//destroy_img(&core);
}
