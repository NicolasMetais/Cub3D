/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 02:30:20 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/27 17:05:45 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Extension de la fonction d'extraction du fichier, la Norme TMTC
bool	extend_extract_datas(t_core *core, int *nb, int count)
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

//Je recup toutes les lignes du fichier et gere les alloc EN MEME TEMPS.
//pour eviter de devoir compter les lignes du fichier avant de les stocker.
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

int	file_extract(t_core *core)
{
	int		map_fd;
	int		i;
	int		j;

	i = -1;
	map_fd = open(core->map_name, O_RDONLY);
	if (map_fd == -1)
		perror("cub3D: open_file");
	core->map = malloc(sizeof(char *) * 16);
	if (!core->map)
		return (false);
	if (!extract_datas(core, map_fd))
		return (false);
	while (core->map[++i])
	{
		j = -1;
		while (core->map[i][++j])
		{
			if (core->map[i][j] == '\n')
				core->map[i][j] = '\0';
		}
	}
	if (!add_to_gc(&core->gc, core->map, TAB_STRING, "map"))
		return (false);
	return (true);
}
