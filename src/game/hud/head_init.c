/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:37:51 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/30 00:07:52 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	head_init(t_core *core)
{
	t_sprite	*head;

	head = hashmap_get(&core->hashmap_sprites, "neutral");
	head->timer = 0;
	head->speed = 1000;
	head = hashmap_get(&core->hashmap_sprites, "tired");
	head->timer = 0;
	head->speed = 1000;
	head = hashmap_get(&core->hashmap_sprites, "hurt");
	head->timer = 0;
	head->speed = 1000;
	head = hashmap_get(&core->hashmap_sprites, "bloody");
	head->timer = 0;
	head->speed = 1000;
	head = hashmap_get(&core->hashmap_sprites, "critical");
	head->timer = 0;
	head->speed = 1000;
	return (true);
}
