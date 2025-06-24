/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:30:16 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/24 17:53:55 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	bonus_or_not(t_parse_map *pm)
{
	if (IS_BONUS == 1)
	{
		if (!extend_strdup_bonus(pm))
			return (false);
	}
	else
	{
		if (!extend_strdup(pm))
			return (false);
	}
	return (true);
}

bool	realloc_map_2(t_tmp	*stock, char **dup_maps, int i)
{
	int	j;
	int	size;

	j = -1;
	stock->tmp_map_content[i] = ft_calloc(stock->width + 1, sizeof(char));
	if (!stock->tmp_map_content[i])
		return (false);
	size = ft_strlen(dup_maps[i]);
	while (++j < stock->width)
	{
		if (j < size)
			stock->tmp_map_content[i][j] = dup_maps[i][j];
		else
			stock->tmp_map_content[i][j] = ' ';
	}
	stock->tmp_map_content[i][j] = '\0';
	return (true);
}

void	free_partial_map(char **map, int up_to)
{
	int	i;

	i = 0;
	while (i < up_to)
		free(map[i++]);
	free(map);
}

bool	realloc_map(t_tmp *stock, char **dup_maps)
{
	int	i;
	int	lines;

	lines = ft_strlen_tab(dup_maps);
	stock->tmp_map_content = malloc(sizeof(char *)
			* (lines + 1));
	if (!stock->tmp_map_content)
		return (false);
	i = -1;
	while (++i < lines)
		if (!realloc_map_2(stock, dup_maps, i))
			return (free_partial_map(stock->tmp_map_content, i), false);
	stock->height = i;
	stock->tmp_map_content[i] = NULL;
	return (true);
}
