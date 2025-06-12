/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:37:51 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/12 15:41:16 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	head_init(t_core *core)
{
	t_sprite	*head;
	int			i;
	char		*heads[5];

	i = -1;
	heads[0] = "neutral";
	heads[1] = "tired";
	heads[2] = "hurt";
	heads[3] = "bloody";
	heads[4] = "critical";
	while (++i < 6)
	{
		head = hashmap_get(&core->hashmap_sprites, heads[i]);
		if (!head)
			return (false);
		head->timer = 0;
		head->speed = 1000;
	}
	return (true);
}
