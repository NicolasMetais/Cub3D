/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:17:25 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/02 00:30:49 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_image(t_img *dst, t_img *src, int offset_y)
{
	int		y;
	char	*src_line;
	char	*dst_line;

	y = 0;
	while (y < src->height)
	{
		src_line = src->addr + y * src->line_len;
		dst_line = dst->addr + (y + offset_y) * dst->line_len;
		ft_memcpy(dst_line, src_line, src->width * (src->bpp / 8));
		y++;
	}
}


t_node_img	*duplicate_node(t_node_img	*original, t_core *core)
{
	t_node_img	*new_node;

	new_node = gc_malloc(&core->gc, sizeof(t_node_img), STRUCT, "node sprite");
	if (!new_node)
		return (NULL);
	new_node->image = gc_malloc(&core->gc, sizeof(t_img),
			STRUCT, "image duplicate");
	if (!new_node->image)
		return (NULL);
	new_node->image->img = mlx_new_image(core->mlx, original->image->width,
			original->image->height + 200);
	if (!new_node->image->img)
		return (NULL);
	new_node->image->addr = mlx_get_data_addr(new_node->image->img,
			&new_node->image->bpp, &new_node->image->line_len,
			&new_node->image->endian);
	new_node->image->width = original->image->width;
	new_node->image->height = original->image->height + 200;
	fill_img_in_green(new_node->image);
	copy_image(new_node->image, original->image, 200);
	// ft_memcpy(new_node->image->addr, original->image->addr,
	// 	original->image->height * original->image->line_len);
	return (new_node);
}

bool	rebuild_fire_anim(t_node_img **anim_list,
		t_sprite *fire_list, t_pos offset, t_core *core)
{
	t_node_img	*first;
	t_node_img	*second;
	t_sprite	*fire_cur;
	t_node_img	*last_inserted;
	t_node_img	*dup;

	first = *anim_list;
	second = first->next;
	fire_cur = fire_list;
	last_inserted = first;
	while (fire_cur->nb-- > 0)
	{
		dup = duplicate_node(first, core);
		if (!dup)
			return (false);
		if (fire_cur->img_list->has_offset)
			transparency(dup->image, fire_cur->img_list->image,
				fire_cur->img_list->offset_x, fire_cur->img_list->offset_y);
		else
			transparency(dup->image, fire_cur->img_list->image,
				offset.x, offset.y);
		dup->next = last_inserted->next;
		last_inserted->next = dup;
		last_inserted = dup;
		fire_cur->img_list = fire_cur->img_list->next;
	}
	last_inserted->next = second;
	return (true);
}

void	setup_animation_exceptions(t_weapon weapon[9])
{
	weapon[3].fire->img_list->next->has_offset = true;
	weapon[3].fire->img_list->next->offset_x = 60;
	weapon[3].fire->img_list->next->offset_y = 115;
	weapon[6].fire->img_list->next->has_offset = true;
	weapon[6].fire->img_list->next->offset_x = 57;
	weapon[6].fire->img_list->next->offset_y = 100;
	weapon[6].fire->img_list->next->next->has_offset = true;
	weapon[6].fire->img_list->next->next->offset_x = 20;
	weapon[6].fire->img_list->next->next->offset_y = 80;
	weapon[6].fire->img_list->next->next->next->has_offset = true;
	weapon[6].fire->img_list->next->next->next->offset_x = 0;
	weapon[6].fire->img_list->next->next->next->offset_y = 25;
	weapon[8].fire->img_list->next->has_offset = true;
	weapon[8].fire->img_list->next->offset_x = 65;
	weapon[8].fire->img_list->next->offset_y = 45;

}

bool	animation_options_init(t_weapon weapon[9], t_core *core)
{
	int				i;
	int				j;
	const t_pos		offsets[] = {
	{55, 120},
	{80, 150},
	{60, 125},
	{75, 120},
	{0, 120},
	{178, 128},
	{145, 120}};

	setup_animation_exceptions(weapon);
	i = 1;
	j = 0;
	while (++i < 9)
	{
		if (i == 4)
			continue ;
		if (!rebuild_fire_anim(&weapon[i].anim->img_list,
				weapon[i].fire, offsets[j], core))
			return (false);
		j++;
	}
	return (true);
}

void	weapons_init_fourth(t_weapon weapon[9], t_core *core)
{
	weapon[7].name = "Plasma Rifle";
	weapon[7].ammo_type = 4;
	weapon[7].cooldown = 0.086;
	weapon[7].fire_rate = 700;
	weapon[7].damage.min = 5;
	weapon[7].damage.max = 40;
	weapon[7].owned = true;
	weapon[7].normal = hashmap_get(&core->hashmap, "PLSGA0");
	weapon[7].anim = hashmap_get(&core->hashmap_sprites, "plasmarifle");
	weapon[7].fire = hashmap_get(&core->hashmap_sprites, "plasmarifle_fire");
	weapon[7].fired = false;
	weapon[8].name = "BFG 9000";
	weapon[8].ammo_type = 4;
	weapon[8].cooldown = 1.07;
	weapon[8].fire_rate = 56;
	weapon[8].damage.min = 2060;
	weapon[8].damage.max = 4200;
	weapon[8].owned = true;
	weapon[8].normal = hashmap_get(&core->hashmap, "BFGGA0");
	weapon[8].anim = hashmap_get(&core->hashmap_sprites, "BFG9000");
	weapon[8].fire = hashmap_get(&core->hashmap_sprites, "BFG9000_fire");
	weapon[8].fired = false;
	animation_options_init(weapon, core);
}

void	weapons_init_third(t_weapon weapon[9], t_core *core)
{
	weapon[5].name = "Chaingun";
	weapon[5].ammo_type = 1;
	weapon[5].cooldown = 0.113;
	weapon[5].fire_rate = 530;
	weapon[5].damage.min = 5;
	weapon[5].damage.max = 15;
	weapon[5].owned = true;
	weapon[5].normal = hashmap_get(&core->hashmap, "CHGGA0");
	weapon[5].anim = hashmap_get(&core->hashmap_sprites, "chaingun");
	weapon[5].fire = hashmap_get(&core->hashmap_sprites, "chaingun_fire");
	weapon[5].fired = false;
	weapon[6].name = "Rocket launcher";
	weapon[6].ammo_type = 3;
	weapon[6].cooldown = 0.566;
	weapon[6].fire_rate = 106;
	weapon[6].damage.min = 148;
	weapon[6].damage.max = 288;
	weapon[6].owned = true;
	weapon[6].normal = hashmap_get(&core->hashmap, "MISGA0");
	weapon[6].anim = hashmap_get(&core->hashmap_sprites, "rocketlauncher");
	weapon[6].fire = hashmap_get(&core->hashmap_sprites, "rocketlauncher_fire");
	weapon[6].fired = false;
	weapons_init_fourth(weapon, core);
}

void	weapons_init_bis(t_weapon weapon[9], t_core *core)
{
	weapon[2].name = "pistol";
	weapon[2].ammo_type = 1;
	weapon[2].cooldown = 0.4;
	weapon[2].fire_rate = 150;
	weapon[2].damage.min = 5;
	weapon[2].damage.max = 15;
	weapon[2].owned = true;
	weapon[2].normal = hashmap_get(&core->hashmap, "PISGA0");
	weapon[2].anim = hashmap_get(&core->hashmap_sprites, "pistol");
	weapon[2].fire = hashmap_get(&core->hashmap_sprites, "pistol_fire");
	weapon[2].lock = false;
	weapon[2].fired = false;
	weapon[2].freeze = false;
	weapon[3].name = "Shotgun";
	weapon[3].ammo_type = 2;
	weapon[3].cooldown = 1.0;
	weapon[3].fire_rate = 58;
	weapon[3].damage.min = 35;
	weapon[3].damage.max = 105;
	weapon[3].owned = true;
	weapon[3].normal = hashmap_get(&core->hashmap, "SHTGA0");
	weapon[3].anim = hashmap_get(&core->hashmap_sprites, "shotgun");
	weapon[3].fire = hashmap_get(&core->hashmap_sprites, "shotgun_fire");
	weapon[3].fired = false;
	weapons_init_third(weapon, core);
}

void	weapons_init(t_weapon weapon[9], t_core *core)
{
	weapon[0].name = "Chainsaw";
	weapon[0].ammo_type = 0;
	weapon[0].cooldown = 0.125;
	weapon[0].fire_rate = 480;
	weapon[0].damage.min = 2;
	weapon[0].damage.max = 20;
	weapon[0].owned = false;
	weapon[0].normal = hashmap_get(&core->hashmap, "SAWGA0");
	weapon[0].anim = hashmap_get(&core->hashmap_sprites, "saw");
	weapon[0].fired = false;
	weapon[1].name = "Fists";
	weapon[1].ammo_type = 0;
	weapon[1].cooldown = 0.5;
	weapon[1].fire_rate = 120;
	weapon[1].damage.min = 2;
	weapon[1].damage.max = 20;
	weapon[1].owned = true;
	weapon[1].normal = hashmap_get(&core->hashmap, "PUNGA0");
	weapon[1].anim = hashmap_get(&core->hashmap_sprites, "fist");
	weapon[1].fired = false;
	weapons_init_bis(weapon, core);
}
