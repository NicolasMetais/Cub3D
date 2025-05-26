/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:00:44 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/23 21:45:09 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	valid_chars(char **colors)
{
	int		i;
	int		j;
	char	*error;

	i = -1;
	while (colors[++i])
	{
		j = -1;
		while (colors[i][++j])
		{
			if (!ft_isdigit(colors[i][j]))
			{
				error = ft_strjoin(
						"Error \n RGB colors only take digits :", colors[i]);
				if (!error)
					return (false);
				ft_putendl_fd(error, 2);
				free(error);
				return (false);
			}
		}
	}
	return (true);
}

bool	valid_numbers_range(char **colors, void **var_ptr)
{
	int			i;
	char		*error;
	t_int_array	*tmp;

	i = -1;
	tmp = *var_ptr;
	while (colors[++i])
	{
		tmp->data[i] = ft_atoi(colors[i]);
		if (tmp->data[i] < 0 || tmp->data[i] > 255)
		{
			error = ft_strjoin(
					"Error \n Invalid RGB number (0 - 255) : ", colors[i]);
			if (!error)
				return (false);
			ft_putendl_fd(error, 2);
			free(error);
			return (false);
		}
	}
	return (true);
}

bool	rgb_error(t_core *core, void *targets[6], int i, void **var_ptr)
{
	char	**colors;

	*var_ptr = gc_malloc(&core->gc, sizeof(int) * 3, TAB_INT, "colors");
	if (!*var_ptr)
		return (false);
	colors = ft_split(*(char **)targets[i], ',');
	if (!colors)
		return (cleanup_split(colors), false);
	if (ft_strlen_tab(colors) != 3)
		return (ft_free_tab(colors), ft_putendl_fd(
				"Error \n Wrong typo : (numbers,numbers,numbers)", 2), false);
	if (!valid_chars(colors))
		return (ft_free_tab(colors), false);
	if (!valid_numbers_range(colors, var_ptr))
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

bool	parse_textures_content(t_core *core, t_tmp *stock, void *targets[6])
{
	int		i;
	void	*var_ptr[2];
	int		j;

	var_ptr[0] = &stock->tmp_colors->floor;
	var_ptr[1] = &stock->tmp_colors->ceiling;
	i = -1;
	j = 0;
	while (++i < 4)
	{
		if (!xmp_extension_error(targets, i))
			return (false);
	}
	stock->tmp_colors = ft_calloc(1, sizeof(t_colors));
	if (!stock->tmp_colors)
		return (false);
	while (i < 6)
	{
		if (!rgb_error(core, targets, i, &var_ptr[j]))
			return (false);
		i++;
		j++;
	}
	return (true);
}
