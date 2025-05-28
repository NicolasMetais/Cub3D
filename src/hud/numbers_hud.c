/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:16:14 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/28 16:09:05 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hud_render_percent(t_core *core, char *percent, int render)
{
	int		j;
	char	tmp[2];
	t_img	*tempo;

	j = -1;
	while (percent[++j])
	{
		tmp[0] = percent[j];
		tmp[1] = '\0';
		tempo = hashmap_get(&core->hashmap, tmp);
		render += 44;
		transparency(core->hud_img->hud, tempo, render, 45);
	}
	render += 44;
	tempo = hashmap_get(&core->hashmap, "%");
	transparency(core->hud_img->hud, tempo, render, 45);
	free(percent);
}

bool	render_numbers(t_core *core)
{
	char	*health;
	char	*armor;

	health = ft_itoa(core->player->health);
	if (!health)
		return (false);
	hud_render_percent(core, health, 255);
	armor = ft_itoa(core->player->armor);
	if (!armor)
		return (false);
	hud_render_percent(core, armor, 945);
	return (true);
}
