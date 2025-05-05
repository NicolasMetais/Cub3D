/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 04:00:45 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/05 04:08:37 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_img(t_img *dest, t_img *copy)
{
	int				x;
	int				y;
	unsigned int	pixel;

	y = 0;
	while (y < copy->height)
	{
		x = 0;
		while (x < copy->width)
		{
			pixel = get_img_pxl(copy, x, y);
			put_on_bg(dest, y, x, pixel);
			x++;
		}
		y++;
	}
}
