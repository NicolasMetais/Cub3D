/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparency_scaled.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:27:00 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/12 18:38:40 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_if_not_transparent(t_scale_ctx *ctx,
			t_pos bg_pos, t_pos src_pos)
{
	unsigned int	color;

	color = get_img_pxl(ctx->fg, src_pos.x, src_pos.y);
	if (color != 0x00FF00)
		put_on_bg(ctx->bg, bg_pos.y, bg_pos.x, color);
}

void	handle_pixel(t_scale_ctx *ctx, int j, int i)
{
	t_pos	bg_pos;
	t_pos	src_pos;

	bg_pos.x = j + ctx->start.x;
	bg_pos.y = i + ctx->start.y;
	if (bg_pos.x < 0 || bg_pos.x >= ctx->bg->width
		|| bg_pos.y < 0 || bg_pos.y >= ctx->bg->height)
		return ;
	src_pos.x = (int)(j * ctx->scale.x);
	src_pos.y = (int)(i * ctx->scale.y);
	if (src_pos.x < 0 || src_pos.x >= ctx->fg->width
		|| src_pos.y < 0 || src_pos.y >= ctx->fg->height)
		return ;
	draw_if_not_transparent(ctx, bg_pos, src_pos);
}

void	transparency_scaled(t_img *bg, const t_img *fg, t_pos start, int size)
{
	t_scale_ctx	ctx;
	int			i;
	int			j;

	ctx.bg = bg;
	ctx.fg = fg;
	ctx.start = start;
	ctx.scale.x = (float)fg->width / size;
	ctx.scale.y = (float)fg->height / size;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			handle_pixel(&ctx, j, i);
	}
}
