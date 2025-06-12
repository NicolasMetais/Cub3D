/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:47:38 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/30 20:16:41 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_scroll_game(t_core *core, int x, int y)
{
	int	offset;

	mlx_mouse_get_pos(core->mlx, core->win, &x, &y);
	if (x > 0 && x < core->scroll_ingame)
		offset = -1;
	else if (x > core->scroll_ingame && x < S_LENGHT)
		offset = 1;
	else
		offset = 0;
	if (x < 100)
		mlx_mouse_move(core->mlx, core->win, S_LENGHT -100, S_HEIGHT / 2);
	if (x > S_LENGHT - 100)
		mlx_mouse_move(core->mlx, core->win, 100, S_HEIGHT / 2);
	core->tmp_rc->pl_angle += 0.03 * offset;
	if (core->tmp_rc->pl_angle > 2 * PI)
		core->tmp_rc->pl_angle -= 2 * PI;
	core->tmp_rc->pldelt_x = cos(core->tmp_rc->pl_angle);
	core->tmp_rc->pldelt_y = sin(core->tmp_rc->pl_angle);
	core->scroll_ingame = x;

}

void	mouse_click_game(t_core *core, int button)
{
	t_sprite	*anim;
	int			i;

	i = -1;
	if (button == 1)
	{
		core->player->weapon[core->player->current_weapon].lock = true;
		anim = hashmap_get(&core->hashmap_sprites, "pistol");
		while(++i < anim->nb)
		{

			anim->img_list = anim->img_list->next;
			render_weapon(core);
			mlx_put_image_to_window(core->mlx, core->win, core->game_img->img, 0, 0);
		}
		core->player->weapon[core->player->current_weapon].lock = false;
		render_weapon(core);
		mlx_put_image_to_window(core->mlx, core->win, core->game_img->img, 0, 0);

	}
}
