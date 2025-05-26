/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:03:55 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/05 06:13:06 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_img(t_core *core)
{
	int				i;
	t_hashmap_entry	*tmp;

	i = -1;
	while (++i < core->hashmap.size)
	{
		tmp = core->hashmap.buckets[i];
		while (tmp)
		{
			if (tmp->img)
				mlx_destroy_image(core->mlx, tmp->img->img);
			tmp = tmp->next;
		}
	}
}
