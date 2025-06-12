/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:30:16 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/12 17:52:36 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

bool	realloc_map(t_tmp *stock, char **dup_maps)
{
	int	i;

	stock->tmp_map_content = malloc(sizeof(char *)
			* (ft_strlen_tab(dup_maps) + 1));
	if (!stock->tmp_map_content)
		return (false);
	i = -1;
	while (dup_maps[++i])
		if (!realloc_map_2(stock, dup_maps, i))
			return (false);
	stock->height = i;
	stock->tmp_map_content[i] = NULL;
	return (true);
}
