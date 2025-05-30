/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:43:55 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/29 22:41:33 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	store_img(char **line, t_core *core)
{
	t_img	*img;

	img = NULL;
	if (line[2] && (!ft_strncmp(line[2], "word_creator:", 13)))
	{
		line[2] += 13;
		if (!load_word_image(&img, core,
				line[1], line[2]))
			return (line[2] -= 13, false);
		line[2] -= 13;
	}
	else
	{
		if (!load_image(&img, line[1], core, line[2]))
			return (false);
	}
	if (!hashmap_insert(&core->hashmap, line[0], (void *)img, core))
	{
		ft_putendl_fd("Error: Failed to insert image into hashmap", 2);
		return (false);
	}
	free_gc(core->gc, "original img");
	return (true);
}

unsigned int	hashmap_size(char **data)
{
	int	i;
	int	size;

	i = -1;
	size = 0;
	while (data[++i])
	{
		if (!data[i][0] || data[i][0] == '#')
			continue ;
		size++;
	}
	return (size);
}

bool	extract_img_data(t_core *core)
{
	int		i;
	char	**data;
	char	**tmp;

	data = NULL;
	if (!file_extract("config.cfg", &data, core))
		return (false);
	i = -1;
	if (!hashmap_init(core, hashmap_size(data)))
		return (false);
	while (data[++i])
	{
		if (data[i][0] == '#' || !data[i][0])
			continue ;
		tmp = ft_split(data[i], '\t');
		if (!tmp || !store_img(tmp, core))
			return (ft_free_tab(tmp), false);
		ft_free_tab(tmp);
	}
	load_assets(core, data);
	return (true);
}
