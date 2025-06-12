/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyrelease.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:52:44 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/13 00:31:29 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keyrelease(int key, void *param)
{
	t_core	*core;

	core = (t_core *)param;
	if (core->state == GAME)
		on_keyrelease_game(key, core);
	return (true);
}
