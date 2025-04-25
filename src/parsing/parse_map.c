/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:50:31 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/25 01:46:45 by nmetais          ###   ########.fr       */
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

bool	realloc_map(t_core *core, char **dup_maps)
{
	int	i;

	free_gc(core->gc, "map");
	core->map = gc_malloc(&core->gc,
			sizeof(char *) * (ft_strlen_tab(dup_maps) + 1),
			TAB_STRING, "map");
	if (!core->map)
		return (false);
	i = -1;
	while (dup_maps[++i])
	{
		core->map[i] = ft_strdup(dup_maps[i]);
		if (!core->map[i])
			return (false);
	}
	core->map[i] = NULL;
	return (true);
}

char	**dup_map(t_core *core)
{
	char	**dup_maps;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = core->map_start;
	j = 0;
	dup_maps = gc_malloc(&core->gc,
			sizeof(char *) * (ft_strlen_tab(core->map) - core->map_start + 1),
			TAB_STRING, "dup_map");
	if (!dup_maps)
		return (false);
	while (core->map[i])
	{
		dup_maps[j] = ft_strdup_error(core->map[i++], &count);
		if (!dup_maps[j++])
			return (false);
	}
	dup_maps[j] = NULL;
	realloc_map(core, dup_maps);
	return (dup_maps);
}

bool	parse_map(t_core *core)
{
	char	**dup_maps;

	core->spawn = gc_malloc(&core->gc, sizeof(t_spawn), STRUCT, "spawn");
	if (!core->spawn)
		return (false);
	dup_maps = dup_map(core);
	if (!dup_maps)
		return (false);
	if (!walkable(dup_maps, core))
	{
		ft_putendl_fd(
			"Error \n Invalid map. i shoudn't be able to walk in the void", 2);
		return (false);
	}
	return (true);
}
