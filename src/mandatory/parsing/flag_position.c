/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:57:39 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/26 13:30:25 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_textures_colors(t_tmp *stock, char **prefix)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	count = 0;
	while (stock->tmp_maps[++i])
	{
		j = -1;
		while (prefix[++j])
		{
			if (!ft_strncmp(stock->tmp_maps[i], prefix[j],
					ft_strlen(prefix[j]))
				&& (stock->tmp_maps[i][ft_strlen(prefix[j])] == ' '
				|| stock->tmp_maps[i][ft_strlen(prefix[j])] == '\t'))
			{
				if (i > stock->map_start)
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
	int	ret;

	ret = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	while (*str)
	{
		if (*str != '0' && *str != '1' && *str != ' '
			&& *str != 'N' && *str != 'S' && *str != 'E' && *str != 'W')
			return (0);
		if (*str == '0' || *str == '1')
			ret = 1;
		str++;
	}
	return (ret);
}

int	is_valid_line(char *str, char **prefix)
{
	int	j;

	j = -1;
	while (prefix[++j])
	{
		if (!ft_strncmp(str, prefix[j], ft_strlen(prefix[j])))
			return (1);
	}
	return (0);
}

int	first_map_line(t_tmp *stock, char **prefix)
{
	int		i;
	char	*tmp;

	i = -1;
	while (stock->tmp_maps[++i])
	{
		tmp = stock->tmp_maps[i];
		while (*tmp == ' ' || *tmp == '\t')
			tmp++;
		if (is_empty_line(tmp))
			continue ;
		if (is_valid_line(tmp, prefix))
			continue ;
		if (is_a_line(tmp))
			return (i);
	}
	return (-1);
}

bool	check_flag_position(t_tmp *stock, char *prefix[7])
{
	int	prefix_nb;

	stock->map_start = first_map_line(stock, prefix);
	prefix_nb = is_textures_colors(stock, prefix);
	if (prefix_nb < 0)
		return (false);
	if (prefix_nb < 6)
	{
		ft_putendl_fd("Error \nMissing textures or colors", 2);
		return (false);
	}
	return (true);
}
