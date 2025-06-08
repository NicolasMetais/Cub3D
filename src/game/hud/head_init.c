/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:37:51 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/08 18:54:40 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	head_init(t_core *core)
{
	t_sprite	*head;

	head = hashmap_get(&core->hashmap_sprites, "neutral");
	if (!head)
		return (false);
	head->timer = 0;
	head->speed = 1000;
	head = hashmap_get(&core->hashmap_sprites, "tired");
	if (!head)
		return (false);
	head->timer = 0;
	head->speed = 1000;
	head = hashmap_get(&core->hashmap_sprites, "hurt");
	if (!head)
		return (false);
	head->timer = 0;
	head->speed = 1000;
	head = hashmap_get(&core->hashmap_sprites, "bloody");
	if (!head)
		return (false);
	head->timer = 0;
	head->speed = 1000;
	head = hashmap_get(&core->hashmap_sprites, "critical");
	if (!head)
		return (false);
	head->timer = 0;
	head->speed = 1000;
	return (true);
}
