/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:40:31 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/26 17:15:48 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	hashmap_delete(t_hashmap *map, char *key, t_core *core)
{
	t_hashmap_entry	*to_del;
	t_hashmap_entry	*prev;
	t_img			*img;
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
			img = (t_img *)to_del->img;
			if (img && img->img)
				mlx_destroy_image(core->mlx, img->img);
			if (prev)
				prev->next = to_del->next;
			else
				map->buckets[index] = to_del->next;
			return (true);
		}
	}
		prev = to_del;
		to_del = to_del->next;
	return (false);
}
