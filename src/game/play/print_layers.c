/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_layers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:48:11 by tvacher           #+#    #+#             */
/*   Updated: 2025/05/25 13:48:41 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    print_3d(t_core *core)
{
    float   ray_width;
    int     start;
    int     end;
    int     pixel_index;
    //int     tex_index;

    ray_width = 1;
    if (ray_width < 1)
        ray_width = 1;
    start = (int)(core->tmp_rc->r * (ray_width));
    end = (int)((core->tmp_rc->r + 1) * (ray_width));
    if (end > S_LENGHT)
        end = S_LENGHT;
    core->tmp_3d->x = start;
    while (core->tmp_3d->x < end && (core->tmp_3d->x > core->map_width * 8 || core->tmp_3d->y > core->map_height * 8) && \
        core->tmp_3d->y < S_HEIGHT - 160)
    {
        pixel_index = core->tmp_3d->y * core->tmp_imgdata->size + core->tmp_3d->x * (core->tmp_imgdata->bpp / 8);
        // pixel_index = core->tmp_3d->y * core->textures->tmp_north->width + core->tmp_3d->x * (core->textures->tmp_north->bpp / 8);
        // tex_index = core->textures->tmp_north
        if (core->tmp_3d->y >= core->tmp_3d->line_s && core->tmp_3d->y <= \
        core->tmp_3d->line_e && core->tmp_rc->dist[core->tmp_rc->r] > core->tmp_rc->dist2[core->tmp_rc->r])
        {
            // core->tmp_imgdata->img_data[pixel_index + 0] = core->textures->tmp_north->addr[];
            core->tmp_imgdata->img_data[pixel_index + 0] = 0x00;
            core->tmp_imgdata->img_data[pixel_index + 1] = 0xFF;
            core->tmp_imgdata->img_data[pixel_index + 2] = 0x00;
        }
        else if (core->tmp_3d->y >= core->tmp_3d->line_s && core->tmp_3d->y <= \
        core->tmp_3d->line_e && core->tmp_rc->dist2[core->tmp_rc->r] > core->tmp_rc->dist[core->tmp_rc->r])
        {
            core->tmp_imgdata->img_data[pixel_index + 0] = 0x00;
            core->tmp_imgdata->img_data[pixel_index + 1] = 0xDD;
            core->tmp_imgdata->img_data[pixel_index + 2] = 0x00;
        }
        if (core->tmp_imgdata->bpp == 32)
            core->tmp_imgdata->img_data[pixel_index + 3] = 0;
        core->tmp_3d->x += 1;
    }
}

void    print_rays(t_core *core, int color)
{
    int i;
    int px_index;

    i = 0;

    while (i < (int)core->tmp_rc->dist3[core->tmp_rc->r])
    {
        core->tmp_rc->px = core->tmp_rc->pl_x + cos(core->tmp_rc->ra) * i;
        core->tmp_rc->py = core->tmp_rc->pl_y + sin(core->tmp_rc->ra) * i;
        if (core->tmp_rc->px >= 0 && core->tmp_rc->py >= 0)
        {
            px_index = core->tmp_rc->py * core->tmp_imgdata->size + core->tmp_rc->px * (core->tmp_imgdata->bpp / 8);
            core->tmp_imgdata->img_data[px_index + 0] = (color >> 0) & 0xFF;
            core->tmp_imgdata->img_data[px_index + 1] = (color >> 8) & 0xFF;
            core->tmp_imgdata->img_data[px_index + 2] = (color >> 16) & 0xFF;
            if (core->tmp_imgdata->bpp == 4)
                core->tmp_imgdata->img_data[px_index + 0] = 0xFF;
        }
        i++;
    }
}

void    draw_player_line(t_core *core, int color)
{
    int i;
    int px;
    int py;
    int px_index;

    i = 0;
    while (i < 8)
    {
        px = core->tmp_rc->pl_x + cos(core->tmp_rc->pl_angle) * i;
        py = core->tmp_rc->pl_y + sin(core->tmp_rc->pl_angle) * i;
        if (px >= 0 && py >= 0)
        {
            px_index = py * core->tmp_imgdata->size + px * (core->tmp_imgdata->bpp / 8);
            core->tmp_imgdata->img_data[px_index + 0] = (color >> 0) & 0xFF;
            core->tmp_imgdata->img_data[px_index + 1] = (color >> 8) & 0xFF;
            core->tmp_imgdata->img_data[px_index + 2] = (color >> 16) & 0xFF;
            if (core->tmp_imgdata->bpp == 4)
                core->tmp_imgdata->img_data[px_index + 0] = 0xFF;
        }
        i++;
    }
}

void    print_player(t_core *core, int color)
{
    int     x;
    int     y;
    int     px_index;

    y = core->tmp_rc->pl_y;
    while (y < core->tmp_rc->pl_y + 4)
    {
        x = core->tmp_rc->pl_x;
        while (x < core->tmp_rc->pl_x + 4)
        {
            px_index = y * core->tmp_imgdata->size + x * (core->tmp_imgdata->bpp / 8);
            core->tmp_imgdata->img_data[px_index + 0] = (color >> 0) & 0xFF;
            core->tmp_imgdata->img_data[px_index + 1] = (color >> 8) & 0xFF;
            core->tmp_imgdata->img_data[px_index + 2] = (color >> 16) & 0xFF;
            if (core->tmp_imgdata->bpp == 4)
                core->tmp_imgdata->img_data[px_index + 0] = 0xFF;
            x++;
        }
        y++;
    }
    draw_player_line(core, color);
}

void    print_background(t_core *core, int x, int y, int color)
{
    int i;
    int j;
    int px_index;

    j = 0;
    while (j < y)
    {
        i = 0;
        while (i < x)
        {
            px_index = j * core->tmp_imgdata->size + i * (core->tmp_imgdata->bpp / 8);
            core->tmp_imgdata->img_data[px_index + 0] = (color >> 0) & 0xFF;
            core->tmp_imgdata->img_data[px_index + 1] = (color >> 8) & 0xFF;
            core->tmp_imgdata->img_data[px_index + 2] = (color >> 16) & 0xFF;
            if (core->tmp_imgdata->bpp == 4)
                core->tmp_imgdata->img_data[px_index + 0] = 0xFF;
            i++;
        }
        j++;
    }
}
