/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 02:30:20 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/26 14:42:56 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Extension de la fonction d'extraction du fichier, la Norme TMTC
bool	extend_extract_datas(char ***tab, int *nb, int count, t_core *core)
{
	char	**new;
	int		i;

	i = -1;
	new = malloc(sizeof(char *) * (*nb * 2));
	if (!new)
		return (false);
	add_to_gc(&core->gc, new, STRING, "extract datas");
	while (++i < count)
		new[i] = (*tab)[i];
	*tab = new;
	*nb *= 2;
	return (true);
}

//Je recup toutes les lignes du fichier et gere les alloc EN MEME TEMPS.
//pour eviter de devoir compter les lignes du fichier avant de les stocker.
bool	extract_datas(char ***tab, int fd, t_core *core)
{
	int		count;
	int		nb;
	char	*line;

	count = 0;
	nb = 16;
	line = get_next_line(fd);
	if (!line)
		return (false);
	if (!add_to_gc(&core->gc, line, STRING, "line"))
		return (false);
	while (line)
	{
		if (count >= nb - 1)
		{
			if (!extend_extract_datas(tab, &nb, count, core))
				return (false);
		}
		(*tab)[count++] = line;
		line = get_next_line(fd);
		if (!add_to_gc(&core->gc, line, STRING, "line"))
			return (false);
	}
	(*tab)[count] = NULL;
	return (true);
}

bool	file_extract(char *file_name, char ***tab, t_core *core)
{
	int		fd;
	int		i;
	int		j;

	i = -1;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (perror("cub3D: file_extract"), false);
	*tab = ft_calloc(sizeof(char *), 16);
	if (!*tab)
		return (close(fd), false);
	add_to_gc(&core->gc, *tab, STRING, "extract data");
	if (!extract_datas(tab, fd, core))
		return (close(fd), false);
	while ((*tab)[++i])
	{
		j = -1;
		while ((*tab)[i][++j])
		{
			if ((*tab)[i][j] == '\n')
			(*tab)[i][j] = '\0';
		}
	}
	return (close(fd), true);
}
