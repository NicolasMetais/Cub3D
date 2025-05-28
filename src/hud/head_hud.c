/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:38:17 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/29 00:26:09 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//GERER LE UPDATE SPRITE AVEC UNE STRUCT TIMEVAL DIRECTEMENT DANS LE T_SPRITE
//METTRE UN RANDOM SUR LA FRAME DE L'ANIMATION
bool	render_head(t_core *core)
{
	t_sprite	*selected;
	t_img		*head;

	selected = NULL;
	if (core->player->health <= 0)
	{
		//FAUT METTRE L'IMAGE DEAD A LA PLACE
		head = hashmap_get(&core->hashmap, "head");
		transparency(core->hud_img->hud, head, 740, 7);
	}
	else if (core->player->health <= 20)
		selected = core->hud_img->critical;
	else if (core->player->health <= 40)
		selected = core->hud_img->bloody;
	else if (core->player->health <= 60)
		selected = core->hud_img->hurt;
	else if (core->player->health <= 80)
		selected = core->hud_img->tired;
	else
		selected = core->hud_img->neutral;
	if (selected && update_sprite(selected))
	{
		transparency(core->hud_img->hud, selected->sprites[selected->frame],
		740, 7);
		printf("%d\n", selected->frame);
	}

	return (true);
}
