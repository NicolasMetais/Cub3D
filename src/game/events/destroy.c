/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:48:49 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/27 17:05:26 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_destroy(t_core *core)
{
	mlx_destroy_window(core->mlx, core->win);
	mlx_destroy_display(core->mlx);
	free_gc(core->gc, NULL);
	exit(0);
	return (0);
}
