/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:03:55 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/29 17:56:06 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_single_img(void *value, t_core *core)
{
	t_img	*img;

	img = (t_img *)value;
	if (img && img->img)
		mlx_destroy_image(core->mlx, img->img);
}

void	destroy_img(t_core *core)
{
	int				i;
	t_hashmap_entry	*tmp;
	t_img			*img;

	i = -1;
	while (++i < core->hashmap.size)
	{
		tmp = core->hashmap.buckets[i];
		while (tmp)
		{
			img = (t_img *)tmp->value;
			if (img && img->img)
				mlx_destroy_image(core->mlx, img->img);
			tmp = tmp->next;
		}
	}
}
