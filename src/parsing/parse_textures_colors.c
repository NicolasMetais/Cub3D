/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:28:37 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/22 21:41:44 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	strlen_without_spaces(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			count++;
		i++;
	}
	return (count);
}

char	*strdup_without_spaces(const char *s)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*cpy;

	i = 0;
	j = 0;
	len = strlen_without_spaces(s);
	cpy = malloc(len * sizeof(char) + 1);
	if (cpy == NULL)
		return (NULL);
	while (s[j])
	{
		if (s[j] != ' ' && s[j] != '\t' && s[j] != '\n')
		{
			cpy[i++] = s[j];
		}
		j++;
	}
	cpy[i] = '\0';
	return ((void *)cpy);
}

bool	extract_textures(t_core *core, char *prefix)
{
	int		i;
	char	*tmp;

	i = -1;
	core->textures = ft_calloc(1, sizeof(t_textures));
	add_to_gc(&core->gc, core->textures, STRUCT, "textures");
	while (core->map[++i])
	{
		tmp = core->map[i];
		while (*tmp == ' ' || *tmp == '\t')
				tmp++;
		if (ft_strncmp(tmp, prefix, 2) == 0)
		{
			tmp += 2;
			free(core->textures->north);
			while (*tmp == ' ' || *tmp == '\t')
				tmp++;
			core->textures->north = strdup_without_spaces(tmp);
		}
	}
	add_to_gc(&core->gc, core->textures->north, STRING, "texture");
	return (true);
}

bool	parse_textures_colors(t_core *core)
{
	if (!extract_textures(core, "NO"))
		return (false);
	if (!extract_textures(core, "SD"))
		return (false);
	if (!extract_textures(core, "WE"))
		return (false);
	if (!extract_textures(core, "EA"))
		return (false);
	print_allocated_vars(core->gc, "texture");
	return (true);
}
