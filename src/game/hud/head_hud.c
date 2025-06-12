/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:38:17 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/12 16:13:18 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	dead_head_render(t_core *core)
{
	t_img	*dead;

	dead = hashmap_get(&core->hashmap, "STFDEAD0");
	if (!dead)
		return (false);
	transparency(core->hud_img->hud, dead->img, 740, 7);
	mlx_put_image_to_window(core->mlx, core->win, core->hud_img->hud->img,
		0, 840);
	return (true);
}

void	render_head(t_core *core)
{
	t_sprite	*selec;

	selec = NULL;
	if (core->player->health <= 0)
		if (!dead_head_render(core))
			return ;
	if (core->player->health <= 20)
		selec = hashmap_get(&core->hashmap_sprites, "critical");
	else if (core->player->health <= 40)
		selec = hashmap_get(&core->hashmap_sprites, "bloody");
	else if (core->player->health <= 60)
		selec = hashmap_get(&core->hashmap_sprites, "hurt");
	else if (core->player->health <= 80)
		selec = hashmap_get(&core->hashmap_sprites, "tired");
	else
		selec = hashmap_get(&core->hashmap_sprites, "neutral");
	if (selec && !selec)
		return ;
	if (selec && update_sprite_random(selec))
	{
		transparency(core->hud_img->hud, selec->img_list->image, 740, 7);
		mlx_put_image_to_window(core->mlx, core->win, core->hud_img->hud->img,
			0, 840);
	}
}
