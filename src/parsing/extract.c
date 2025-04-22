/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 02:30:20 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/22 15:51:00 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool extend_extract_datas(t_core *core, int *nb, int count)
{
	char	**new;
	int		i;

	i = -1;
	new = malloc(sizeof(char *) * (*nb * 2));
	if (!new)
		return (false);
	while (++i < count)
		new[i] = core->map[i];
	free(core->map);
	core->map = new;
	*nb *= 2;
	return (true);
}

int	extract_datas(t_core *core, int map_fd)
{
	int		count;
	int		nb;
	char	*line;


	count = 0;
	nb = 16;
	line = get_next_line(map_fd);
	if (!line)
		return (false);
	while (line)
	{
		if (count >= nb - 1)
		{
			if (!extend_extract_datas(core, &nb, count))
				return (false);
		}
		core->map[count++] = line;
		line = get_next_line(map_fd);
	}
	core->map[count] = NULL;
	return (true);
}

int	parsing_map(t_core *core)
{
	int		map_fd;

	map_fd = open(core->map_name, O_RDONLY);
	if (map_fd == -1)
		perror("cub3D: open_file");
	core->map = malloc(sizeof(char *) * 16);
	if (!core->map)
		return (false);
	if (!extract_datas(core, map_fd))
		return (false);
	add_to_gc(&core->gc, core->map, TAB_STRING, "map");
	return (true);
}


