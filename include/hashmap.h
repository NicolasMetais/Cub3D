/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:47:09 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/26 15:51:22 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include <stdbool.h>

typedef struct s_img	t_img;

typedef struct s_hashmap_entry
{
	char					*key;
	t_img					*img;
	struct s_hashmap_entry	*next;
}	t_hashmap_entry;

typedef struct s_hashmap
{
	t_hashmap_entry	**buckets;
	int				size;
}	t_hashmap;

bool			hashmap_init(t_core *core, int size);

bool			hashmap_insert(t_hashmap *map, char *key, t_img *img, t_core *core);

t_img			*hashmap_get(t_hashmap *map, char *key);

unsigned long	hasher(const char *str);

bool			hashmap_delete(t_hashmap *map, char *key, t_core *core);

int				power_of_two(int n);

#endif