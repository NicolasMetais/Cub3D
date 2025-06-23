/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:57:33 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/23 23:07:08 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	flood_fill(char **map, int x, int y, int len)
{
	if (x < 0 || y < 0 || y >= len || x >= (int)ft_strlen(map[y]))
		return (false);
	if (map[y][x] == ' ' || map[y][x] == '\0')
		return (false);
	if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'D')
		return (true);
	if (map[y][x] == '2')
		map[y][x] = 'D';
	else
		map[y][x] = 'V';
	if (!flood_fill(map, x + 1, y, len)
		|| !flood_fill(map, x - 1, y, len)
		|| !flood_fill(map, x, y + 1, len)
		|| !flood_fill(map, x, y - 1, len))
		return (false);
	return (true);
}

bool	walkable(char **dup_maps, t_tmp *stock, bool *spawn)
{
	int		i;
	int		j;

	i = -1;
	while (dup_maps[++i])
	{
		j = -1;
		while (dup_maps[i][++j])
		{
			if (dup_maps[i][j] == 'N' || dup_maps[i][j] == 'S'
				|| dup_maps[i][j] == 'E' || dup_maps[i][j] == 'W')
			{
				*spawn = true;
				stock->spawn->x = j;
				stock->spawn->y = i;
				if (!flood_fill(dup_maps, j, i, ft_strlen_tab(dup_maps)))
				{
					dup_maps[i][j] = 'V';
					return (ft_putendl_fd(
							"Error \n Invalid map. void detected", 2), false);
				}
			}
		}
	}
	return (true);
}
