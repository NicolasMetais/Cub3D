/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:51:57 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/11 15:33:29 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*load_buffer(t_img *image, int x, int y, t_core *core)
{
	static int	count = 0;

	image = gc_malloc(&core->gc, sizeof(t_img),
			STRUCT, "buffer_img");
	if (!image)
		return (NULL);
	image->img = mlx_new_image(core->mlx, x, y);
	image->addr = mlx_get_data_addr(image->img,
			&image->bpp, &image->line_len,
			&image->endian);
	image->width = x;
	image->height = y;
	if (!name_generator(count++, "buffer_img", image, core))
		return (NULL);
	return (image);
}
