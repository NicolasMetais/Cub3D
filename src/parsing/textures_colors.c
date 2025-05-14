/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:28:37 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/14 11:43:11 by nmetais          ###   ########.fr       */
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
			cpy[i++] = s[j];
		j++;
	}
	cpy[i] = '\0';
	return ((void *)cpy);
}

bool	extract_textures(char **dest, t_core *core, char *prefix)
{
	int		i;
	char	*tmp;

	i = -1;
	while (core->map[++i])
	{
		tmp = core->map[i];
		while (*tmp == ' ' || *tmp == '\t')
				tmp++;
		if (ft_strncmp(tmp, prefix, ft_strlen(prefix)) == 0)
		{
			tmp += 2;
			while (*tmp == ' ' || *tmp == '\t')
				tmp++;
			*dest = strdup_without_spaces(tmp);
			if (!*dest)
				return (false);
			add_to_gc(&core->gc, *dest, STRING, "textures");
		}
	}
	return (true);
}

bool	parse_textures_colors(t_core *core, char *prefix[7], void *targets[6])
{
	int		i;

	i = -1;
	while (prefix[++i])
	{
		if (!extract_textures(targets[i], core, prefix[i]))
			return (false);
	}
	return (true);
}
