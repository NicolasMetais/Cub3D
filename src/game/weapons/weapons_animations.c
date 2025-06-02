/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_animations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:00:55 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/02 21:08:56 by nmetais          ###   ########.fr       */
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
	return (new_node);
}

static void	apply_fire_offset(t_node_img *dup,
		t_sprite *fire_cur, t_pos offset)
{
	if (fire_cur->img_list->has_offset)
		transparency(dup->image, fire_cur->img_list->image,
			fire_cur->img_list->offset_x, fire_cur->img_list->offset_y);
	else
		transparency(dup->image, fire_cur->img_list->image,
			offset.x, offset.y);
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
		apply_fire_offset(dup, fire_cur, offset);
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
	weapon[5].fire->img_list->next->has_offset = true;
	weapon[5].fire->img_list->next->offset_x = 57;
	weapon[5].fire->img_list->next->offset_y = 100;
	weapon[5].fire->img_list->next->next->has_offset = true;
	weapon[5].fire->img_list->next->next->offset_x = 20;
	weapon[5].fire->img_list->next->next->offset_y = 80;
	weapon[5].fire->img_list->next->next->next->has_offset = true;
	weapon[5].fire->img_list->next->next->next->offset_x = 0;
	weapon[5].fire->img_list->next->next->next->offset_y = 25;
	weapon[7].fire->img_list->next->has_offset = true;
	weapon[7].fire->img_list->next->offset_x = 65;
	weapon[7].fire->img_list->next->offset_y = 45;
}
