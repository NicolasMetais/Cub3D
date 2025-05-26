/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:33:49 by tvacher           #+#    #+#             */
/*   Updated: 2025/05/14 13:33:51 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int map[] = 
{
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1,
    1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1,
    1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

void    draw_tile(char *img_data, int bpp, int size_line, int x, int y, int color)
{
    int i;
    int j;
    int pixel_index;

    j = 0;
    while (j < 31)
    {
        i = 0;
        while (i < 31)
        {
            pixel_index = (y + j) * size_line + (x + i) * (bpp / 8);
            img_data[pixel_index + 0] = (color & 0x0000FF);
            img_data[pixel_index + 1] = (color & 0x00FF00) >> 8;
            img_data[pixel_index + 2] = (color & 0xFF0000) >> 16;
            if (bpp == 32)
                img_data[pixel_index + 3] = 0;
            i++;
        }
        j++;
    }
}

void    draw_test_map2(char *img_data, int bpp, int size_line)
{
    int x;
    int y;
    int tile_x;
    int tile_y;

    y = 0;
    while (y < 16)
    {
        x = 0;
        while (x < 16)
        {
            tile_x = x * 32;
            tile_y = y * 32;
            if (map[y * 16 + x] == 1)
                draw_tile(img_data, bpp, size_line, tile_x, tile_y, 0xFFFFFF);
            else
                draw_tile(img_data, bpp, size_line, tile_x, tile_y, 0x000000);
            x++;
        }
        y++;
    }
}

void    draw_test_map(char *img_data, int bpp, int size_line)
{
    int x;
    int y;
    int tile_x;
    int tile_y;

    y = 0;
    while (y < 16)
    {
        x = 0;
        while (x < 16)
        {
            tile_x = x * 32;
            tile_y = y * 32;
            if (map[y * 16 + x] == 1)
                draw_tile(img_data, bpp, size_line, tile_x, tile_y, 0xFFFFFF);
            // else
            //     draw_tile(img_data, bpp, size_line, tile_x, tile_y, 0x000000);
            x++;
        }
        y++;
    }
}
void    draw_3d(t_core *core)
{
    core->tmp_3d->line_h = (16 * S_HEIGHT) / core->tmp_rc->dist3[core->tmp_rc->r];
    if (core->tmp_3d->line_h > S_HEIGHT)
        core->tmp_3d->line_h = S_HEIGHT;
    core->tmp_3d->line_s = (S_HEIGHT - core->tmp_3d->line_h) / 3;
    core->tmp_3d->line_e = core->tmp_3d->line_s + core->tmp_3d->line_h;
    core->tmp_3d->y = 0;
	while (core->tmp_3d->y < S_HEIGHT)
	{
		print_3d(core);
		core->tmp_3d->y++;
	}
}

static void loop_tiles(t_core *core, int i)
{
    while (i < 16)
    {
        core->tmp_rc->mx = (int)core->tmp_rc->rx >> 5;
        core->tmp_rc->my = (int)core->tmp_rc->ry >> 5;
        core->tmp_rc->mp = core->tmp_rc->my * 16 + core->tmp_rc->mx;
        if (core->tmp_rc->mp >= 0 && core->tmp_rc->mp < 16 * 16 && map[core->tmp_rc->mp] == 1)
            break ;
        else
        {
            core->tmp_rc->rx += core->tmp_rc->x;
            core->tmp_rc->ry += core->tmp_rc->y;
            i++;
        }
    }  
}

void    horizontal_cast(t_core *core)
{
    int i;

    i = 0;
    core->tmp_rc->atan = -1 / tan(core->tmp_rc->ra);
    if (core->tmp_rc->ra > PI)
    {
        core->tmp_rc->ry = (((int)core->tmp_rc->pl_y >> 5) << 5) -0.0001;
        core->tmp_rc->rx = (core->tmp_rc->pl_y - core->tmp_rc->ry) * core->tmp_rc->atan + core->tmp_rc->pl_x;
        core->tmp_rc->y = -32;
        core->tmp_rc->x = -core->tmp_rc->y * core->tmp_rc->atan;
    }
    if (core->tmp_rc->ra < PI)
    {
        core->tmp_rc->ry = (((int)core->tmp_rc->pl_y >> 5) << 5) + 32;
        core->tmp_rc->rx = (core->tmp_rc->pl_y - core->tmp_rc->ry) * core->tmp_rc->atan + core->tmp_rc->pl_x;
        core->tmp_rc->y = 32;
        core->tmp_rc->x = -core->tmp_rc->y * core->tmp_rc->atan;
    }
    if (core->tmp_rc->ra == 0 || core->tmp_rc->ra == PI)
    {
        core->tmp_rc->rx = core->tmp_rc->pl_x;
        core->tmp_rc->ry = core->tmp_rc->pl_y;
        i = 16;
    }
    loop_tiles(core, i);
}

void    vertical_cast(t_core *core)
{
    int i;

    i = 0;
    core->tmp_rc->ntan = -tan(core->tmp_rc->ra);
    if (core->tmp_rc->ra > PI / 2 && core->tmp_rc->ra < 3 * PI / 2)
    {
        core->tmp_rc->rx = (((int)core->tmp_rc->pl_x >> 5) << 5) - 0.0001;
        core->tmp_rc->ry = (core->tmp_rc->pl_x - core->tmp_rc->rx) * core->tmp_rc->ntan + core->tmp_rc->pl_y;
        core->tmp_rc->x = -32;
        core->tmp_rc->y = -core->tmp_rc->x * core->tmp_rc->ntan;
    }
    if (core->tmp_rc->ra < PI / 2 || core->tmp_rc->ra > 3 * PI / 2)
    {
        core->tmp_rc->rx = (((int)core->tmp_rc->pl_x >> 5) << 5) + 32;
        core->tmp_rc->ry = (core->tmp_rc->pl_x - core->tmp_rc->rx) * core->tmp_rc->ntan + core->tmp_rc->pl_y;
        core->tmp_rc->x = 32;
        core->tmp_rc->y = -core->tmp_rc->x * core->tmp_rc->ntan;
    }
    if (core->tmp_rc->ra == 0 || core->tmp_rc->ra == PI)
    {
        core->tmp_rc->rx = core->tmp_rc->pl_x;
        core->tmp_rc->ry = core->tmp_rc->pl_y;
        i = 16;
    }
    loop_tiles(core, i);
}

void    get_raycast_data(t_core *core)
{
    core->tmp_rc->ra = core->tmp_rc->pl_angle - RAD * ((core->tmp_rc->max_r) / 2);
    if (core->tmp_rc->ra < 0)
        core->tmp_rc->ra += 2 * PI;
    if (core->tmp_rc->ra > 2 * PI)
        core->tmp_rc->ra -= 2 * PI;
    core->tmp_rc->r = 0;
    while (core->tmp_rc->r < core->tmp_rc->max_r)
    {
        horizontal_cast(core);
        core->tmp_rc->dist[core->tmp_rc->r] = sqrt((core->tmp_rc->rx - core->tmp_rc->pl_x) * (core->tmp_rc->rx - core->tmp_rc->pl_x) + \
                (core->tmp_rc->ry - core->tmp_rc->pl_y) * (core->tmp_rc->ry - core->tmp_rc->pl_y));
        vertical_cast(core);
        core->tmp_rc->dist2[core->tmp_rc->r] = sqrt((core->tmp_rc->rx - core->tmp_rc->pl_x) * (core->tmp_rc->rx - core->tmp_rc->pl_x) + \
                (core->tmp_rc->ry - core->tmp_rc->pl_y) * (core->tmp_rc->ry - core->tmp_rc->pl_y));
		if (core->tmp_rc->dist[core->tmp_rc->r] > core->tmp_rc->dist2[core->tmp_rc->r])
        	core->tmp_rc->dist3[core->tmp_rc->r] = core->tmp_rc->dist2[core->tmp_rc->r];
    	else
		{
        	core->tmp_rc->dist3[core->tmp_rc->r] = core->tmp_rc->dist[core->tmp_rc->r];
		}
		print_rays(core, 0xFF0000);
		rays_updates(core);
        draw_3d(core);
    }
}

void    get_rc_data(t_core *core)
{
    core->tmp_rc = malloc(sizeof(*core->tmp_rc));
    if (!core->tmp_rc)
        return ;
    core->tmp_rc->pl_x = 100;
    core->tmp_rc->pl_y = 100;
    core->tmp_rc->pl_angle = 0;
    core->tmp_rc->pldelt_x = cos(core->tmp_rc->pl_angle) / 2;
    core->tmp_rc->pldelt_y = sin(core->tmp_rc->pl_angle) / 2;
	core->tmp_rc->res = 16;
    core->tmp_rc->max_r = core->fov * 16;
	core->tmp_rc->dist = gc_malloc(&core->gc, sizeof(float) * core->tmp_rc->max_r, FLOAT, "dist");
	core->tmp_rc->dist2 = gc_malloc(&core->gc, sizeof(float) * core->tmp_rc->max_r, FLOAT, "dist2");
	core->tmp_rc->dist3 = gc_malloc(&core->gc, sizeof(float) * core->tmp_rc->max_r, FLOAT, "dist3");
	if (!core->tmp_rc->dist || !core->tmp_rc->dist2 || !core->tmp_rc->dist3)
		return ;
}

void    start_game(t_core *core)
{
    core->tmp_imgdata = malloc(sizeof(t_tmp_imgdata));
    if (!core->tmp_imgdata)
        return ;
    core->tmp_imgdata->img = mlx_new_image(core->mlx, S_LENGHT, S_HEIGHT);
    if (!core->tmp_imgdata->img)
		return ;
	core->tmp_3d = malloc(sizeof(t_tmp_3d));
    if (!core->tmp_3d)
        return ;
    core->tmp_imgdata->img_data = mlx_get_data_addr(core->tmp_imgdata->img, \
    &core->tmp_imgdata->bpp, &core->tmp_imgdata->size, &core->tmp_imgdata->endian);
    print_background(core, S_LENGHT, S_HEIGHT, 0xAAAAAA);
	draw_test_map2(core->tmp_imgdata->img_data, core->tmp_imgdata->bpp, core->tmp_imgdata->size);
	get_raycast_data(core);
    print_player(core, 0xFFFF00);
	draw_test_map(core->tmp_imgdata->img_data, core->tmp_imgdata->bpp, core->tmp_imgdata->size);
    mlx_put_image_to_window(core->mlx, core->win, core->tmp_imgdata->img, 0, 0);
    core->redraw = false;
}