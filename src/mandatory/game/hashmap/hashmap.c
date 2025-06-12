/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:57:29 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/29 18:49:22 by nmetais          ###   ########.fr       */
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

void	*hashmap_get(t_hashmap *map, char *key)
{
	unsigned int	index;
	t_hashmap_entry	*entry;

	index = hasher(key) % map->size;
	entry = map->buckets[index];
	while (entry)
	{
		if (ft_strcmp(entry->key, key) == 0)
			return (entry->value);
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
	core->hashmap_sprites.buckets = gc_malloc(&core->gc,
			sizeof(t_hashmap_entry *) * hash_size, STRUCT, "hashmap_sprites");
	if (!core->hashmap_sprites.buckets)
		return (false);
	ft_memset(core->hashmap_sprites.buckets, 0,
		sizeof(t_hashmap_entry *) * hash_size);
	core->hashmap_sprites.size = hash_size;
	return (true);
}

bool	node_exist(t_hashmap_entry	*node, char *key, void *img)
{

	while (node)
	{
		if (!ft_strcmp(node->key, key))
		{
			node->value = img;
			return (true);
		}
		node = node->next;
	}
	return (false);
}

bool	hashmap_insert(t_hashmap *map, char *key, void *value, t_core *core)
{
	int				i;
	unsigned long	hash;
	t_hashmap_entry	*head;
	t_hashmap_entry	*new;

	if (!key || !value || !map)
		return (false);
	hash = hasher(key);
	i = hash % map->size;
	head = map->buckets[i];
	if (node_exist(head, key, value))
		return (true);
	new = gc_malloc(&core->gc, sizeof(t_hashmap_entry), STRUCT, "hashmap node");
	if (!new)
		return (false);
	new->key = ft_strdup(key);
	if (!new->key)
		return (false);
	add_to_gc(&core->gc, new->key, STRING, "hashmap key");
	new->value = value;
	new->next = map->buckets[i];
	map->buckets[i] = new;
	return (true);
}
