/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_over.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:28:46 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/21 15:37:23 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rewrite_options(t_core *core, const int *y, t_img *bg)
{
	t_sprite	*the_end;
	t_img		*press;

	the_end = (t_sprite *)hashmap_get(&core->hashmap_sprites, "the_end");
	press = (t_img *)hashmap_get(&core->hashmap, "Press");
	if (!the_end || !press)
		return ;
	transparency(bg, the_end->img_list->image, (bg->width / 2) - 100, y[0]);
	transparency(bg, press, (bg->width / 2) - 500, y[1]);
	mlx_put_image_to_window(core->mlx, core->win,
		core->hud_img->pause_buffer->img, 0, 0);
}

//INIT Y POS
static void	start_menu_init(t_core *core)
{
	int	i;

	i = -1;
	while (++i < 2)
		core->y_pos[i] = 400 + (i * 200);
}

//MENU RENDERING EVERYTIME I DO A MOVEMENT IN THE MENU
bool	render_game_over(t_core *core)
{
	start_menu_init(core);
	copy_img(core->hud_img->clean_pause_buffer, core->game_img);
	copy_img(core->hud_img->clean_pause_buffer, core->game_img);
	transparency(core->hud_img->clean_pause_buffer, core->hud_img->hud,
		0, 840);
	transparency(core->hud_img->clean_pause_buffer, core->hud_img->ammo1,
		1380, 865);
	transparency(core->hud_img->clean_pause_buffer, core->hud_img->ammo2,
		1380, 895);
	transparency(core->hud_img->clean_pause_buffer, core->hud_img->ammo3,
		1380, 925);
	transparency(core->hud_img->clean_pause_buffer, core->hud_img->ammo4,
		1380, 955);
	transparency(core->hud_img->clean_pause_buffer, core->hud_img->life,
		250, 880);
	transparency(core->hud_img->clean_pause_buffer, core->hud_img->armor,
		945, 880);
	transparency(core->hud_img->clean_pause_buffer, core->hud_img->ammo,
		5, 880);
	d4rk_img(core->hud_img->clean_pause_buffer, 0.2);
	copy_img(core->hud_img->pause_buffer, core->hud_img->clean_pause_buffer);
	core->menu_option = 0;
	rewrite_options(core, core->y_pos, core->hud_img->pause_buffer);
	return (true);
}
