/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:09:05 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/30 00:16:51 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	new_sprite_node(t_core *core, t_sprite *tempo, t_node_img *head,
		char *name)
{
	t_node_img	*new;

	new = gc_malloc(&core->gc, sizeof(t_node_img), STRUCT, "node sprite");
	if (!new)
		return (false);
	new->image = hashmap_get(&core->hashmap, name);
	if (!new->image)
		return (false);
	if (!head)
	{
		tempo->img_list = new;
		new->next = new;
	}
	else
	{
		head->next = new;
		new->next = tempo->img_list;
	}
	tempo->nb++;
	return (true);
}

bool	load_sprites(t_core *core, char **key, char *name)
{
	t_sprite	*tempo;
	t_node_img	*head;
	int			i;

	i = -1;
	if (ft_strcmp(key[0], "sprite") != 0)
		return (ft_putendl_fd("Error \n Wrong flag in sprites setup", 2), false);
	tempo = (t_sprite *)hashmap_get(&core->hashmap_sprites, key[1]);
	if (!tempo)
	{
		tempo = gc_malloc(&core->gc, sizeof(t_sprite), STRUCT, "sprite");
		if (!tempo)
			return (false);
		ft_memset(tempo, 0, sizeof(t_sprite));
		if (!new_sprite_node(core, tempo, NULL, name))
			return (false);
		hashmap_insert(&core->hashmap_sprites, key[1], (void *)tempo, core);
		return (true);
	}
	head = tempo->img_list;
	while (++i < tempo->nb - 1)
		head = head->next;
	if (!new_sprite_node(core, tempo, head, name))
		return (false);
	return (true);
}

bool	load_assets(t_core *core, char **data)
{
	int			i;
	char		**line;
	char		**tmp;

	i = -1;
	while (data[++i])
	{
		if (data[i][0] == '#' || !data[i][0])
			continue ;
		line = ft_split(data[i], '\t');
		if (!line)
			return (ft_free_tab(line), false);
		if (line[3])
		{
			tmp = ft_split(line[3], ':');
			if (!tmp)
				return (ft_free_tab(line), false);
			if (!load_sprites(core, tmp, line[0]))
				return (ft_free_tab(line), ft_free_tab(tmp), false);
			ft_free_tab(tmp);
		}
		ft_free_tab(line);
	}
	return (true);
}
