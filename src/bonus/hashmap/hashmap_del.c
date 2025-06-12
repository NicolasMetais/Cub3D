/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:40:31 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/29 17:51:08 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	hashmap_delete(t_hashmap *map, char *key, t_core *core,
			void (*destroy)(void *value, t_core *core))
{
	t_hashmap_entry	*to_del;
	t_hashmap_entry	*prev;
	unsigned int	index;

	if (!key || !map)
		return (false);
	index = hasher(key) % map->size;
	to_del = map->buckets[index];
	prev = NULL;
	while (to_del)
	{
		if (ft_strcmp(to_del->key, key) == 0)
		{
			if (destroy)
				destroy(to_del->value, core);
			if (prev)
				prev->next = to_del->next;
			else
				map->buckets[index] = to_del->next;
			return (true);
		}
		prev = to_del;
		to_del = to_del->next;
	}
	return (false);
}
