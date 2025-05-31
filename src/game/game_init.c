/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:55:32 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/31 23:49:48 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

	// int i = -1;
	// while(++i < 9)
	// {
	// 	if (i == 4)
	// 		i++;
	// 	if (weapon[i].normal)
	// 		printf("NORMAL : width : %d, Height : %d\n", weapon[i].normal->width, weapon[i].normal->height);
	// 	int j = -1;
	// 	while(++j < weapon[i].anim->nb)
	// 	{
	// 		printf("ANIM : width : %d, Height : %d\n", weapon[i].anim->img_list->image->width, weapon[i].anim->img_list->image->height);
	// 		weapon[i].anim->img_list = weapon[i].anim->img_list->next;
	// 	}
	// 	j = -1;
	// 	if (!weapon[i].fire)
	// 		continue ;
	// 	while (++j < weapon[i].fire->nb)
	// 	{
	// 		printf("FIRE : width : %d, Height : %d\n", weapon[i].fire->img_list->image->width, weapon[i].fire->img_list->image->height);
	// 		weapon[i].fire->img_list = weapon[i].fire->img_list->next;
	// 	}
	// }

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
	core->player->current_weapon = 2;
	core->player->speed = PLAYER_SPEED;
	return (true);
}

bool	hud_init(t_core *core)
{
	t_img	*arms;

	core->hud_img = gc_malloc(&core->gc, sizeof(t_hud_img), STRUCT, "hug_img");
	if (!core->hud_img)
		return (false);
	core->hud_img->clean_hud = (t_img *)hashmap_get(&core->hashmap, "hud");
	core->hud_img->hud = (t_img *)hashmap_get(&core->hashmap, "hud");
	arms = (t_img *)hashmap_get(&core->hashmap, "arms");
	transparency(core->hud_img->hud, arms, 520, 0);
	return (true);
}

bool	game_init(t_core *core)
{
	core->game_img = gc_malloc(&core->gc, sizeof(t_img), STRUCT, "game_img");
	if (!core->game_img)
		return (false);
	core->game_img->img = mlx_new_image(core->mlx, S_LENGHT, S_HEIGHT);
	if (!core->game_img->img)
		return (false);
	core->game_img->addr = mlx_get_data_addr(core->game_img->img,
			&core->game_img->bpp, &core->game_img->line_len,
			&core->game_img->endian);
	core->game_img->width = S_LENGHT;
	core->game_img->height = S_HEIGHT;
	core->redraw = true;
	hashmap_insert(&core->hashmap, "game_img", (void *)core->game_img, core);
	if (!player_init(core))
		return (false);
	if (!hud_init(core))
		return (false);
	if (!head_init(core))
		return (false);
    init_map_textures(core);
	weapons_init(core->player->weapon, core);
	core->weapon_buffer = gc_malloc(&core->gc, sizeof(t_img), STRUCT, "weapon_buffer");
	if (!core->weapon_buffer)
		return (false);
	core->weapon_buffer->img = mlx_new_image(core->mlx, 680, 604);
	if (!core->weapon_buffer->img)
		return (false);
	core->weapon_buffer->addr = mlx_get_data_addr(core->weapon_buffer->img,
			&core->weapon_buffer->bpp, &core->weapon_buffer->line_len,
			&core->weapon_buffer->endian);
	core->weapon_buffer->width = 680;
	core->weapon_buffer->height = 604;
	hashmap_insert(&core->hashmap, "weapon_buffer", (void *)core->weapon_buffer, core);
	t_weapon	*weapon;
	weapon = core->player->weapon;
	mlx_clear_window(core->mlx, core->win);
	return (true);
}
