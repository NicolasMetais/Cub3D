/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:50:31 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/27 16:22:34 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup_error(const char *s, int *count)
{
	size_t	i;
	char	*cpy;

	i = -1;
	cpy = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (cpy == NULL)
		return (NULL);
	while (s[++i])
	{
		if (s[i] != '0' && s[i] != '1' && s[i] != 'N' && s[i] != 'S'
			&& s[i] != 'E' && s[i] != 'W' && s[i] != '\t' && s[i] != ' ')
			return (free(cpy), ft_putendl_fd(
					"Error \n Invalid character in the map", 2), NULL);
		if (s[i] == 'N' || s[i] == 'S' || s[i] == 'E' || s[i] == 'W')
				(*count)++;
		if (*count > 1)
			return (free(cpy), ft_putendl_fd(
					"Error \n Too many spawn point", 2), NULL);
		cpy[i] = s[i];
	}
	cpy[i] = '\0';
	return ((void *)cpy);
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

char	**dup_map(t_tmp *stock)
{
	char	**dup_maps;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = stock->map_start;
	j = 0;
	dup_maps = malloc(sizeof(char *) * (ft_strlen_tab(stock->tmp_maps)
				- stock->map_start + 1));
	if (!dup_maps)
		return (false);
	while (stock->tmp_maps[i])
	{
		if (stock->width < (int)ft_strlen(stock->tmp_maps[i]))
			stock->width = ft_strlen(stock->tmp_maps[i]);
		dup_maps[j] = ft_strdup_error(stock->tmp_maps[i++], &count);
		if (!dup_maps[j++])
			return (false);
	}
	dup_maps[j] = NULL;
	realloc_map(stock, dup_maps);
	return (dup_maps);
}

bool	parse_map(t_tmp *stock)
{
	char	**dup_maps;

	stock->spawn = malloc(sizeof(t_pos));
	if (!stock->spawn)
		return (false);
	dup_maps = dup_map(stock);
	if (!dup_maps)
		return (false);
	if (!walkable(dup_maps, stock))
	{
		ft_putendl_fd(
			"Error \n Invalid map. i shoudn't be able to walk in the void", 2);
		return (false);
	}
	ft_free_tab(dup_maps);
	return (true);
}
