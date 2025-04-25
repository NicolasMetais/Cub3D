/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:57:33 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/25 01:59:52 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	flood_fill(char **map, int x, int y, int len)
{
	if (x < 0 || y < 0 || y >= len || x >= (int)ft_strlen(map[y]))
		return (false);
	if (map[y][x] == ' ' || map[y][x] == '\0')
		return (false);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (true);
	map[y][x] = 'V';
	if (!flood_fill(map, x + 1, y, len)
		|| !flood_fill(map, x - 1, y, len)
		|| !flood_fill(map, x, y + 1, len)
		|| !flood_fill(map, x, y - 1, len))
		return (false);
	return (true);
}

bool	walkable(char **dup_maps, t_core *core)
{
	int	i;
	int	j;

	i = -1;
	while (dup_maps[++i])
	{
		j = -1;
		while (dup_maps[i][++j])
		{
			if (dup_maps[i][j] == 'N' || dup_maps[i][j] == 'S'
				|| dup_maps[i][j] == 'E' || dup_maps[i][j] == 'W')
			{
				if (!flood_fill(dup_maps, j, i, ft_strlen_tab(dup_maps)))
				{
					core->spawn->x = i;
					core->spawn->y = j;
					dup_maps[i][j] = 'V';
					return (false);
				}
			}
		}
	}
	return (true);
}
