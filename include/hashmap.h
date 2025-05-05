/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:47:09 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/05 17:51:04 by nmetais          ###   ########.fr       */
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

bool	hashmap_init(t_core *core, int size);

bool	hashmap_insert(t_hashmap *map, char *key, t_img *img, t_core *core);

t_img	*hashmap_get(t_hashmap *map, char *key);

void	word_creator(char *word, t_core *core, int x, int y);

int		power_of_two(int n);

#endif