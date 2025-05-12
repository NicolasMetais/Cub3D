/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_names.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 03:22:15 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/12 13:18:09 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_maps_numbers(DIR *dir)
{
	struct dirent	*files;
	int				size;

	size = 0;
	files = readdir(dir);
	while (files)
	{
		printf("%s\n", files->d_name);
		if (ft_strcmp(files->d_name, "..") && ft_strcmp(files->d_name, "."))
		{
			size++;
			if (!valid_extension(".cub", files->d_name))
			{
				ft_putendl_fd(
					"Error \nOnly .cub maps extension in maps folder", 2);
				return (-1);
			}
		}
		files = readdir(dir);
	}
	return (size);
}

bool	extract_maps_names(t_core *core)
{
	DIR				*dir;
	struct dirent	*files;
	int				size;
	int				i;

	i = 0;
	dir = opendir("./maps");
	if (!dir)
		return (ft_putendl_fd("Error \n can't load maps folder", 2), false);
	size = get_maps_numbers(dir);
	if (size == -1)
		return (false);
	core->menu_maps = gc_malloc(&core->gc, sizeof(t_menu_maps) * size,
			STRUCT, "menu maps");
	if (!core->menu_maps)
		return (closedir(dir), false);
	rewinddir(dir);
	files = readdir(dir);
	while (files)
	{
		if (ft_strcmp(files->d_name, "..") && ft_strcmp(files->d_name, "."))
			core->menu_maps[i++].name = ft_strdup(files->d_name);
		files = readdir(dir);
	}
	return (closedir(dir), true);
}
