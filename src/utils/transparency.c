/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparency.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 00:46:55 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/06 22:55:37 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_on_bg(t_img *bg, size_t y, size_t x, int color)
{
	char	*change_pix;

	if (color == (int)0x00FF00)
		return ;
	change_pix = bg->addr + (y * bg->line_len + x * (bg->bpp / 8));
	*(unsigned int *) change_pix = color;
}

unsigned int	get_img_pxl(const t_img *stickonbg, size_t x, size_t y)
{
	return (*(unsigned int *)(stickonbg->addr
		+ (y * stickonbg->line_len + x * (stickonbg->bpp / 8))));
}

//WRITE AN IMAGE ON ANOTHER IMAGE IGNORING GREEN (00FF00)
void	transparency(t_img *bg, const t_img *stickonbg,
		int start_x, const int start_y)
{
	int	i;
	int	j;
	int	bg_x;
	int	bg_y;

	i = 0;
	while (i < stickonbg->height)
	{
		j = 0;
		while (j < stickonbg->width)
		{
			bg_y = i + start_y;
			bg_x = j + start_x;
			if (bg_x >= 0 && bg_x < bg->width && bg_y >= 0 && bg_y < bg->height)
				put_on_bg(bg, bg_y, bg_x, get_img_pxl(stickonbg, j, i));
			j++;
		}
		i++;
	}
}

void transparency_scaled(t_img *bg, const t_img *stickonbg, int start_x, int start_y, int size)
{
	int		i, j;
	int		bg_x, bg_y;
	float	scale_x = (float)stickonbg->width / size;
	float	scale_y = (float)stickonbg->height / size;
	int		src_x, src_y;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			bg_y = i + start_y;
			bg_x = j + start_x;
			if (bg_x < 0 || bg_x >= bg->width || bg_y < 0 || bg_y >= bg->height)
				continue;
			src_x = (int)(j * scale_x);
			src_y = (int)(i * scale_y);
			if (src_x < 0 || src_x >= stickonbg->width || src_y < 0 || src_y >= stickonbg->height)
				continue;

			unsigned int color = get_img_pxl(stickonbg, src_x, src_y);
			if (color != 0x00FF00)
				put_on_bg(bg, bg_y, bg_x, color);
		}
	}
}
