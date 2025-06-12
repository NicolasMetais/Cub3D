/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:47:38 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/12 20:12:22 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_click_game(t_core *core, int button)
{
	t_sprite	*anim;
	int			i;

	i = -1;
	if (button == 1)
	{
		core->player->weapon[core->player->curr_wpn].lock = true;
		anim = hashmap_get(&core->hashmap_sprites, "pistol");
		while(++i < anim->nb)
		{

			anim->img_list = anim->img_list->next;
			render_weapon(core);
			mlx_put_image_to_window(core->mlx, core->win, core->game_img->img, 0, 0);
		}
		core->player->weapon[core->player->curr_wpn].lock = false;
		render_weapon(core);
		mlx_put_image_to_window(core->mlx, core->win, core->game_img->img, 0, 0);

	}
}
