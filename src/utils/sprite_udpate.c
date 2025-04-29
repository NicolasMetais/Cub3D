/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_udpate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 03:53:57 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/29 03:54:42 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_sprite(t_sprite *sprite)
{
	sprite->timer++;
	if (sprite->timer >= sprite->speed)
	{
		sprite->timer = 0;
		sprite->frame = (sprite->frame + 1) % sprite->nb;
	}
}
