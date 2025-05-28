/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:37:51 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/29 00:24:27 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	head_sprite_init(t_core *core, t_sprite **sprite)
{

	*sprite = gc_malloc(&core->gc, sizeof(t_sprite), STRUCT, "head sprite");
	if (!*sprite)
		return (false);
	(*sprite)->nb = 3;
	(*sprite)->sprites = gc_malloc(&core->gc, sizeof(t_img *) * (*sprite)->nb,
			STRUCT, "skull sprite");
	if (!(*sprite)->sprites)
		return (false);
	(*sprite)->frame = 0;
	(*sprite)->timer = 0;
	(*sprite)->speed = 2000;
	return (true);
}

bool	head_sprite_img(t_core *core, int *i, t_sprite *sprite)
{
	char		*name;
	char		*num;
	int			index;

	index = -1;
	while (++index < sprite->nb)
	{
		name = "STFST";
		num = ft_itoa(*i);
		if (!num)
			return (false);
		name = ft_strjoin(name, num);
		free(num);
		if (!name)
			return (false);
		sprite->sprites[index] = hashmap_get(&core->hashmap, name);
		free(name);
		(*i)++;
	}
	return (true);
}

bool	head_init(t_core *core)
{
	int			i;
	t_sprite	**sprite[5];
	int			count;

	sprite[0] = &core->hud_img->neutral;
	sprite[1] = &core->hud_img->tired;
	sprite[2] = &core->hud_img->hurt;
	sprite[3] = &core->hud_img->bloody;
	sprite[4] = &core->hud_img->critical;
	i = -1;
	count = 0;
	while (++i < 43)
	{
		if (!head_sprite_init(core, sprite[count]))
			return (false);
		if (!head_sprite_img(core, &i, *sprite[count]))
			return (false);
		count++;
		i += 8;
	}
	return (true);
}
