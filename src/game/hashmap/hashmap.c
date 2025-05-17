/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:57:29 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/17 13:22:42 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned long	hasher(const char *str)
{
	unsigned long	hash;
	int				c;

	hash = 5381;
	c = *str++;
	while (c)
	{
		hash = ((hash << 5) + hash) + c;
		c = *str++;
	}
	return (hash);
}

t_img	*hashmap_get(t_hashmap *map, char *key)
{
	unsigned int	index;
	t_hashmap_entry	*entry;

	index = hasher(key) % map->size;
	entry = map->buckets[index];
	while (entry)
	{
		if (ft_strcmp(entry->key, key) == 0)
			return (entry->img);
		entry = entry->next;
	}
	return (NULL);
}

bool	hashmap_init(t_core *core, int size)
{
	int	hash_size;

	hash_size = power_of_two(size * 2);
	core->hashmap.buckets = gc_malloc(&core->gc,
			sizeof(t_hashmap_entry *) * hash_size, STRUCT, "hashmap_image");
	if (!core->hashmap.buckets)
		return (false);
	ft_memset(core->hashmap.buckets, 0, sizeof(t_hashmap_entry *) * hash_size);
	core->hashmap.size = hash_size;
	return (true);
}

bool	node_exist(t_hashmap_entry	*node, char *key, t_img *img)
{

	while (node)
	{
		if (!ft_strcmp(node->key, key))
		{
			node->img = img;
			return (true);
		}
		node = node->next;
	}
	return (false);
}

bool	hashmap_insert(t_hashmap *map, char *key, t_img *img, t_core *core)
{
	int				i;
	unsigned long	hash;
	t_hashmap_entry	*head;
	t_hashmap_entry	*new;

	if (!key || !img || !map)
		return (false);
	hash = hasher(key);
	i = hash % map->size;
	head = map->buckets[i];
	if (node_exist(head, key, img))
		return (true);
	new = gc_malloc(&core->gc, sizeof(t_hashmap_entry), STRUCT, "hashmap node");
	if (!new)
		return (false);
	new->key = ft_strdup(key);
	if (!new->key)
		return (false);
	add_to_gc(&core->gc, new->key, STRING, "hashmap key");
	new->img = img;
	new->next = map->buckets[i];
	map->buckets[i] = new;
	return (true);
}
