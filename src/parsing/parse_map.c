/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:50:31 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/21 21:07:50 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	extend_strdup(t_parse_map *pm)
{
	int		c;

	if (pm->s[pm->i] != '0' && pm->s[pm->i] != '1'
		&& pm->s[pm->i] != 'N' && pm->s[pm->i] != 'S'
		&& pm->s[pm->i] != 'E' && pm->s[pm->i] != 'W'
		&& pm->s[pm->i] != '\t' && pm->s[pm->i] != '2'
		&& pm->s[pm->i] != '\t' && pm->s[pm->i] != ' ')
		return (free(pm->cpy), ft_putendl_fd(
				"Error \n Invalid character in the map", 2), false);
	if (pm->s[pm->i] == 'N' || pm->s[pm->i] == 'S'
		|| pm->s[pm->i] == 'E' || pm->s[pm->i] == 'W')
			(pm->count)++;
	if (pm->count > 1)
		return (free(pm->cpy), ft_putendl_fd(
				"Error \n Too many spawn point", 2), false);
	if (pm->s[pm->i] == '\t')
	{
		c = -1;
		while (++c < 4)
			pm->cpy[pm->j++] = ' ';
	}
	else
		pm->cpy[pm->j++] = pm->s[pm->i];
	return (true);
}

char	*ft_strdup_error(const char *s, int *count)
{
	t_parse_map	pm;
	int			tab;

	pm.i = -1;
	pm.s = s;
	pm.j = 0;
	pm.count = *count;
	tab = 0;
	while (s[++pm.i])
		if (s[pm.i] == '\t')
			tab++;
	pm.cpy = malloc((ft_strlen(s) + (tab * 3) + 1) * sizeof(char));
	if (pm.cpy == NULL)
		return (NULL);
	pm.i = -1;
	while (s[++pm.i])
		if (!extend_strdup(&pm))
			return (NULL);
	pm.cpy[pm.j] = '\0';
	return ((void *)pm.cpy);
}

char	**dup_map(t_tmp *stock)
{
	char	**dup_maps;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = stock->map_start - 1;
	j = 0;
	stock->width = 0;
	dup_maps = malloc(sizeof(char *) * (ft_strlen_tab(stock->tmp_maps)
				- stock->map_start + 1));
	if (!dup_maps)
		return (false);
	while (stock->tmp_maps[++i])
	{
		dup_maps[j] = ft_strdup_error(stock->tmp_maps[i], &count);
		if (!dup_maps[j])
			return (NULL);
		if (stock->width < (int)ft_strlen(dup_maps[j]))
			stock->width = ft_strlen(dup_maps[j]);
		j++;
	}
	dup_maps[j] = NULL;
	realloc_map(stock, dup_maps);
	return (dup_maps);
}

bool	parse_map(t_tmp *stock)
{
	stock->spawn = malloc(sizeof(t_pos));
	if (!stock->spawn)
		return (false);
	stock->valid_map_tiles = dup_map(stock);
	if (!stock->valid_map_tiles)
		return (false);
	if (!walkable(stock->valid_map_tiles, stock))
	{
		ft_putendl_fd(
			"Error \n Invalid map. i shoudn't be able to walk in the void", 2);
		return (false);
	}
	return (true);
}
