/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:57:39 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/22 23:01:26 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_textures_colors(t_core *core, char **prefix)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	count = 0;
	while (core->map[++i])
	{
		j = -1;
		while (prefix[++j])
		{
			if (!ft_strncmp(core->map[i], prefix[j], ft_strlen(prefix[j])))
			{
				if (i <= core->map_start)
					return (ft_putendl_fd("Error \n Invalid map position", 2)
						, -1);
				count++;
				break ;
			}
		}
	}
	return (count);
}

int	is_a_line(char *str)
{
	while (*str)
	{
		if (*str != '0' && *str != '1' && *str != ' '
			&& *str != 'N' && *str != 'S' && *str != 'E' && *str != 'W')
			return (0);
				str++;
	}
	return (1);
}

int	first_map_line(t_core *core)
{
	int	i;

	i = -1;
	while (core->map[++i])
	{
		if (is_a_line(core->map[i]))
			return (i);
	}
	return (0);
}

bool	check_map_validity(t_core *core)
{
	char	*prefix[7];
	int		prefix_nb;

	prefix[0] = "NO";
	prefix[1] = "SD";
	prefix[2] = "WE";
	prefix[3] = "EA";
	prefix[4] = "F";
	prefix[5] = "C";
	prefix[6] = NULL;
	core->map_start = first_map_line(core);
	prefix_nb = is_textures_colors(core, prefix);
	if (prefix > 0)
		return (false);
	if (prefix_nb < 6)
	{
		ft_putendl_fd("Error \nMissing textures or colors", 2);
		return (false);
	}
	return (true); 
}
