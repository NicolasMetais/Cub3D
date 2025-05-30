/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_names.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 03:22:15 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/26 16:50:47 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_maps_numbers(DIR *dir, t_core *core)
{
	struct dirent	*files;
	int				size;

	size = 0;
	files = readdir(dir);
	while (files)
	{
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
	core->maps_nb = size;
	return (size);
}

bool	allocate_names(struct dirent *files, char **name, t_core *core, int *i)
{
	char	*tmp;

	if (ft_strcmp(files->d_name, "..") && ft_strcmp(files->d_name, "."))
	{
		tmp = ft_substr(files->d_name, 0, ft_strlen(files->d_name) - 4);
		if (!tmp)
			return (false);
		*name = ft_strdup(tmp);
		if (!*name)
			return (false);
		if (!add_to_gc(&core->gc, *name, STRING, "file names"))
			return (false);
		(*i)++;
		free(tmp);
	}
	return (true);
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
	size = get_maps_numbers(dir, core);
	if (size == -1)
		return (closedir(dir), false);
	core->menu_maps = gc_malloc(&core->gc, sizeof(t_menu_maps) * size,
			STRUCT, "menu maps");
	if (!core->menu_maps)
		return (closedir(dir), false);
	rewinddir(dir);
	files = readdir(dir);
	while (files)
	{
		core->menu_maps[i].parsed = false;
		if (!allocate_names(files, &core->menu_maps[i].name, core, &i))
			return (closedir(dir), false);
		files = readdir(dir);
	}
	return (closedir(dir), true);
}
