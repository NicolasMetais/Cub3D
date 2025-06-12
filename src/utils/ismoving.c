/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ismoving.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:34:11 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/12 18:50:34 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_moving(t_player *player)
{
	if (player->key_down || player->key_up
		|| player->key_left || player->key_right)
		return (true);
	return (false);
}
