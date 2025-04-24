/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:00:44 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/24 14:50:31 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	valid_chars(char **colors)
{
	int	i;
	int	j;

	i = -1;
	while (colors[++i])
	{
		j = -1;
		while (colors[i][++j])
		{
			if (!ft_isdigit(colors[i][j]))
			{
				ft_putendl_fd("Error \n RGB colors only take digits\n", 2);
				return (false);
			}
		}
	}
	return (true);
}

bool	valid_numbers_range(t_core *core, char **colors)
{
	int	i;

	(void)core;
	i = -1;
	while (colors[++i])
	{
			
	}
	return (true);
}

bool	rgb_error(t_core *core, void *targets[6], int i)
{
	char	**colors;

	(void)core;
	colors = ft_split(*(char **)targets[i], ',');
	if (!colors)
		return (false);
	if (ft_strlen_tab(colors) != 3)
		return (ft_free_tab(colors), ft_putendl_fd(
				"Error \n Too many or not enought RGB number\n", 2), false);
	if (!valid_chars(colors))
		return (ft_free_tab(colors), false);
	core->colors = gc_malloc(&core->gc, sizeof(t_colors), STRUCT, "colors");
	if (!core->colors)
		return (ft_free_tab(colors), false);
	if (!valid_numbers_range(core, colors))
		return (ft_free_tab(colors), false);
	ft_free_tab(colors);
	return (true);
}

bool	xmp_extension_error(void *targets[6], int i)
{
	char	*error;

	if (!valid_extension(".xpm", *(char **)targets[i]))
	{
		error = ft_strjoin("Error \n Invalid texture extension (.xpm) : ",
				*(char **)targets[i]);
		if (!error)
			return (false);
		ft_putendl_fd(error, 2);
		if (error)
			free(error);
		return (false);
	}
	return (true);
}

bool	parse_textures_content(t_core *core, void *targets[6])
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (!xmp_extension_error(targets, i))
			return (false);
	}
	while (i < 6)
	{
		if (!rgb_error(core, targets, i))
			return (false);
		i++;
	}
	return (true);
}
