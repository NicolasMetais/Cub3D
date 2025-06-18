/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:55:32 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/16 20:18:08 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	player_init(t_core *core)
{
	core->player = gc_malloc(&core->gc, sizeof(t_player),
			STRUCT, "struct player");
	if (!core->player)
		return (false);
	ft_memset(core->player, 0, sizeof(t_player));
	core->player->position = gc_malloc(&core->gc, sizeof(t_pos),
			STRUCT, "pos player");
	if (!core->player->position)
		return (false);
	core->player->position->x = core->spawn->x;
	core->player->position->y = core->spawn->y;
	core->player->health = 100;
	core->player->ammo[0] = 50;
	core->player->curr_wpn = 2;
	core->player->speed = PLAYER_SPEED;
	return (true);
}

bool	game_init(t_core *core)
{
	core->game_img = gc_malloc(&core->gc, sizeof(t_img), STRUCT, "game_img");
	if (!core->game_img)
		return (false);
	core->game_img->img = mlx_new_image(core->mlx, S_LENGHT, S_HEIGHT);
	if (!core->game_img->img)
		return (NULL);
	core->game_img->addr = mlx_get_data_addr(core->game_img->img,
			&core->game_img->bpp, &core->game_img->line_len,
			&core->game_img->endian);
	core->game_img->width = S_LENGHT;
	core->game_img->height = S_HEIGHT;
	core->fontss = gc_malloc(&core->gc,
			sizeof(t_fonts), STRUCT, "fonts");
	if (!core->fontss)
		return (false);
	core->redraw = true;
	if (!player_init(core))
		return (false);
	init_map_textures(core);
	mlx_clear_window(core->mlx, core->win);
	return (true);
}
