/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:49:25 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/28 02:28:21 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	routine(void *param)
{
	t_core	*core;

	core = (t_core *)param;
	if (core->state == MENU)
		render_menu(core);
	else if (core->state == GAME)
		printf("game playing");
	return (0);
}
