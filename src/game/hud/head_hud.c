/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:38:17 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/30 00:04:39 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//GERER LE UPDATE SPRITE AVEC UNE STRUCT TIMEVAL DIRECTEMENT DANS LE T_SPRITE
void	render_head(t_core *core)
{
	t_sprite	*selec;
	t_img		*dead;

	if (core->player->health <= 0)
	{
		dead = (t_img *)hashmap_get(&core->hashmap, "STFDEAD0");
		transparency(core->hud_img->hud, dead, 740, 7);
		return ;
	}
	else if (core->player->health <= 20)
		selec = hashmap_get(&core->hashmap_sprites, "critical");
	else if (core->player->health <= 40)
		selec = hashmap_get(&core->hashmap_sprites, "bloody");
	else if (core->player->health <= 60)
		selec = hashmap_get(&core->hashmap_sprites, "hurt");
	else if (core->player->health <= 80)
		selec = hashmap_get(&core->hashmap_sprites, "tired");
	else
		selec = hashmap_get(&core->hashmap_sprites, "neutral");
	if (selec && update_sprite_random(selec))
	{
		transparency(core->hud_img->hud, selec->img_list->image, 740, 7);
		mlx_put_image_to_window(core->mlx, core->win, core->hud_img->hud->img,
			0, 840);
	}
}
