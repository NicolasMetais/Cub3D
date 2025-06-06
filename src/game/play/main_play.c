/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:33:49 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/06 13:08:01 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_3d(t_core *core)
{
    int     start;
    int     end;
    int     pixel_index;
	float	tex_index;
	float	step;
	float	ty;
	float	ty_off;
	float	tx;

	ty_off = 0;
    core->tmp_3d->line_h = (8 * S_HEIGHT) / core->tmp_rc->dist3[core->tmp_rc->r];
	//step = (float)core->textures->tmp_east->height / (float)core->tmp_3d->line_h;
    step = (float)core->textures->tmp_east->height / (float)core->tmp_3d->line_h;
    core->tmp_3d->line_s = (S_HEIGHT - core->tmp_3d->line_h) / 2;
    core->tmp_3d->line_e = core->tmp_3d->line_s + core->tmp_3d->line_h;
    if (core->tmp_3d->line_h > S_HEIGHT)
	{
        ty_off = (core->tmp_3d->line_h - S_HEIGHT) / 2;
        core->tmp_3d->line_e = S_HEIGHT;
	}
    core->tmp_3d->y = 0;
	tx = 0;
	float offset;

	if (core->tmp_rc->was_vertical)
    	offset = fmodf(core->tmp_rc->ry, 8);
	else
    	offset = fmodf(core->tmp_rc->rx, 8);

	offset = fmodf(offset, 8.0f);
	if (offset < 0)
		offset += 8.0f;
	start = (int)(core->tmp_rc->r * 1);
    end = (int)((core->tmp_rc->r + 1) * 1);
	tx = (int)(offset / 8.0f * core->textures->tmp_east->width);
	if (tx < 0)
		tx = 0;
	if (tx >= core->textures->tmp_east->width)
		tx = core->textures->tmp_east->width - 1;
	
	int draw_start = -core->tmp_3d->line_h / 2 + S_HEIGHT / 2;
	if (draw_start < 0) draw_start = 0;
	int draw_end = core->tmp_3d->line_h / 2 + S_HEIGHT / 2;
	if (draw_end >= S_HEIGHT) draw_end = S_HEIGHT - 1;

	float tex_pos = (draw_start - S_HEIGHT / 2 + core->tmp_3d->line_h / 2) * step;
	core->tmp_3d->y = draw_start;
	while (core->tmp_3d->y < draw_end)
	{
		ty = (int)tex_pos & (core->textures->tmp_east->height - 1);
		tex_pos += step;
    	if (end > S_LENGHT)
			end = S_LENGHT;
		core->tmp_3d->x = start;
		if ((int)ty >= core->textures->tmp_east->height)
			ty = core->textures->tmp_east->height - 1;
		while (core->tmp_3d->x < end && (core->tmp_3d->x > core->tmp_rc->map_size + 8 || core->tmp_3d->y > core->tmp_rc->map_size + 8) && \
		core->tmp_3d->y < S_HEIGHT - 160)
		{
			pixel_index = core->tmp_3d->y * core->game_img->line_len + core->tmp_3d->x * (core->game_img->bpp / 8);
			if (core->tmp_3d->y >= core->tmp_3d->line_s && core->tmp_3d->y <= \
    		core->tmp_3d->line_e && core->tmp_rc->dist2[core->tmp_rc->r] > core->tmp_rc->dist[core->tmp_rc->r] && (core->tmp_3d->y > draw_start && core->tmp_3d->y < draw_end))
    		{
        		if (core->tmp_rc->ra > PI)
        		{
					tex_index = (int)ty * core->textures->tmp_east->line_len + (int)tx * (core->textures->tmp_east->bpp / 8);
					core->game_img->addr[pixel_index + 0] = core->textures->tmp_east->addr[(int)tex_index + 0];
					core->game_img->addr[pixel_index + 1] = core->textures->tmp_east->addr[(int)tex_index + 1];
					core->game_img->addr[pixel_index + 2] = core->textures->tmp_east->addr[(int)tex_index + 2];
        		}
        		else
        		{
					tex_index = (int)ty * core->textures->tmp_north->line_len + (int)tx * (core->textures->tmp_north->bpp / 8);
					core->game_img->addr[pixel_index + 0] = core->textures->tmp_north->addr[(int)tex_index + 0];
					core->game_img->addr[pixel_index + 1] = core->textures->tmp_north->addr[(int)tex_index + 1];
					core->game_img->addr[pixel_index + 2] = core->textures->tmp_north->addr[(int)tex_index + 2];
        		}
    		}
   			else if (core->tmp_3d->y >= core->tmp_3d->line_s && core->tmp_3d->y <= \
            core->tmp_3d->line_e && core->tmp_rc->dist[core->tmp_rc->r] > core->tmp_rc->dist2[core->tmp_rc->r] && (core->tmp_3d->y > draw_start && core->tmp_3d->y < draw_end))
            {
                if (core->tmp_rc->ra > PI / 2 && core->tmp_rc->ra < 3 * PI / 2)
                {
					tex_index = (int)ty * core->textures->tmp_west->line_len + (int)tx * (core->textures->tmp_west->bpp / 8);
					core->game_img->addr[pixel_index + 0] = core->textures->tmp_west->addr[(int)tex_index + 0];
					core->game_img->addr[pixel_index + 1] = core->textures->tmp_west->addr[(int)tex_index + 1];
					core->game_img->addr[pixel_index + 2] = core->textures->tmp_west->addr[(int)tex_index + 2];
                }
                else
                {
					tex_index = (int)ty * core->textures->tmp_south->line_len + (int)tx * (core->textures->tmp_south->bpp / 8);
					core->game_img->addr[pixel_index + 0] = core->textures->tmp_south->addr[(int)tex_index + 0];
					core->game_img->addr[pixel_index + 1] = core->textures->tmp_south->addr[(int)tex_index + 1];
					core->game_img->addr[pixel_index + 2] = core->textures->tmp_south->addr[(int)tex_index + 2];
                }
            }
            core->tmp_3d->x += 1;
        }
		core->tmp_3d->y++;
	}
}

static void loop_tiles_height(t_core *core, int i)
{
    while (i < core->map_height)
    {
        core->tmp_rc->mx = (int)core->tmp_rc->rx >> 3;
        core->tmp_rc->my = (int)core->tmp_rc->ry >> 3;
        // core->tmp_rc->mp = core->tmp_rc->my * core->map_width + core->tmp_rc->mx;
        // if (core->tmp_rc->mp >= 0 && core->tmp_rc->mp < core->map_width && core->map[core->tmp_rc->my][core->tmp_rc->mx] == '1')
        if (core->tmp_rc->my >= 0 && core->tmp_rc->my < core->map_height \
            && core->tmp_rc->mx >= 0 && core->tmp_rc->mx < core->map_width \
            && core->map[core->tmp_rc->my][core->tmp_rc->mx] == '1')
		{
			core->tmp_rc->hx = core->tmp_rc->rx;
			core->tmp_rc->hy = core->tmp_rc->ry;
	        break ;
		}
        else
        {
            core->tmp_rc->rx += core->tmp_rc->x;
            core->tmp_rc->ry += core->tmp_rc->y;
            i++;
        }
    }  
}

static void loop_tiles_width(t_core *core, int i)
{
    while (i < core->map_width)
    {
        core->tmp_rc->mx = (int)core->tmp_rc->rx >> 3;
        core->tmp_rc->my = (int)core->tmp_rc->ry >> 3;
        // core->tmp_rc->mp = core->tmp_rc->my * core->map_width + core->tmp_rc->mx;
        // if (core->tmp_rc->mp >= 0 && core->tmp_rc->mp < core->map_width && core->map[core->tmp_rc->my][core->tmp_rc->mx] == '1')
        if (core->tmp_rc->my >= 0 && core->tmp_rc->my < core->map_height \
            && core->tmp_rc->mx >= 0 && core->tmp_rc->mx < core->map_width \
            && core->map[core->tmp_rc->my][core->tmp_rc->mx] == '1')
		{
			core->tmp_rc->vx = core->tmp_rc->rx;
			core->tmp_rc->vy = core->tmp_rc->ry;
	        break ;
		}
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
        core->tmp_rc->ry = (((int)core->tmp_rc->pl_y >> 3) << 3) -0.0001;
        core->tmp_rc->rx = (core->tmp_rc->pl_y - core->tmp_rc->ry) * core->tmp_rc->atan + core->tmp_rc->pl_x;
        core->tmp_rc->y = -8;
        core->tmp_rc->x = -core->tmp_rc->y * core->tmp_rc->atan;
    }
    if (core->tmp_rc->ra < PI)
    {
        core->tmp_rc->ry = (((int)core->tmp_rc->pl_y >> 3) << 3) + 8;
        core->tmp_rc->rx = (core->tmp_rc->pl_y - core->tmp_rc->ry) * core->tmp_rc->atan + core->tmp_rc->pl_x;
        core->tmp_rc->y = 8;
        core->tmp_rc->x = -core->tmp_rc->y * core->tmp_rc->atan;
    }
    if (core->tmp_rc->ra == 0 || core->tmp_rc->ra == PI)
    {
        core->tmp_rc->rx = core->tmp_rc->pl_x;
        core->tmp_rc->ry = core->tmp_rc->pl_y;
        i = core->map_height;
    }
    loop_tiles_height(core, i);
}

void    vertical_cast(t_core *core)
{
    int i;

    i = 0;
    core->tmp_rc->ntan = -tan(core->tmp_rc->ra);
    if (core->tmp_rc->ra > PI / 2 && core->tmp_rc->ra < 3 * PI / 2)
    {
        core->tmp_rc->rx = (((int)core->tmp_rc->pl_x >> 3) << 3) - 0.0001;
        core->tmp_rc->ry = (core->tmp_rc->pl_x - core->tmp_rc->rx) * core->tmp_rc->ntan + core->tmp_rc->pl_y;
        core->tmp_rc->x = -8;
        core->tmp_rc->y = -core->tmp_rc->x * core->tmp_rc->ntan;
    }
    if (core->tmp_rc->ra < PI / 2 || core->tmp_rc->ra > 3 * PI / 2)
    {
        core->tmp_rc->rx = (((int)core->tmp_rc->pl_x >> 3) << 3) + 8;
        core->tmp_rc->ry = (core->tmp_rc->pl_x - core->tmp_rc->rx) * core->tmp_rc->ntan + core->tmp_rc->pl_y;
        core->tmp_rc->x = 8;
        core->tmp_rc->y = -core->tmp_rc->x * core->tmp_rc->ntan;
    }
    if (core->tmp_rc->ra == 0 || core->tmp_rc->ra == PI)
    {
        core->tmp_rc->rx = core->tmp_rc->pl_x;
        core->tmp_rc->ry = core->tmp_rc->pl_y;
        i = core->map_width;
    }
    loop_tiles_width(core, i);
}

void    get_raycast_data(t_core *core)
{
    core->tmp_rc->ra = core->tmp_rc->pl_angle - RAD * ((core->fov) / 2);
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
		{
			core->tmp_rc->rx = core->tmp_rc->vx;
			core->tmp_rc->ry = core->tmp_rc->vy;
        	core->tmp_rc->dist3[core->tmp_rc->r] = core->tmp_rc->dist2[core->tmp_rc->r];
			core->tmp_rc->was_vertical = 1;
		}
    	else
		{
			core->tmp_rc->rx = core->tmp_rc->hx;
			core->tmp_rc->ry = core->tmp_rc->hy;
        	core->tmp_rc->dist3[core->tmp_rc->r] = core->tmp_rc->dist[core->tmp_rc->r];
			core->tmp_rc->was_vertical = 0;
		}
		print_rays(core, 0xFFFF00);
    	core->tmp_rc->ca = core->tmp_rc->ra - core->tmp_rc->pl_angle;
    	if (core->tmp_rc->ca < -PI)
			core->tmp_rc->ca += 2 * PI;
		if (core->tmp_rc->ca > PI)
			core->tmp_rc->ca -= 2 * PI;
		core->tmp_rc->dist3[core->tmp_rc->r] = core->tmp_rc->dist3[core->tmp_rc->r] * cos(core->tmp_rc->ca); 
		draw_3d(core);
		rays_updates(core);
    }
    impacts(core);
    render_projectiles(core);
}

void    get_rc_data(t_core *core)
{
    core->tmp_3d = malloc(sizeof(t_tmp_3d));
    if (!core->tmp_3d)
        return ;
    core->tmp_rc = malloc(sizeof(*core->tmp_rc));
    if (!core->tmp_rc)
        return ;
    core->tmp_rc->pl_x = core->spawn->x * 8;
    core->tmp_rc->pl_y = core->spawn->y * 8;
    core->tmp_rc->pl_angle = 2 * PI;
    core->tmp_rc->pldelt_x = cos(core->tmp_rc->pl_angle);
    core->tmp_rc->pldelt_y = sin(core->tmp_rc->pl_angle);
    core->tmp_rc->res = 16;
    core->tmp_rc->max_r = S_LENGHT;
    core->tmp_rc->dist = gc_malloc(&core->gc, sizeof(float) * core->tmp_rc->max_r, FLOAT, "dist");
    core->tmp_rc->dist2 = gc_malloc(&core->gc, sizeof(float) * core->tmp_rc->max_r, FLOAT, "dist2");
    core->tmp_rc->dist3 = gc_malloc(&core->gc, sizeof(float) * core->tmp_rc->max_r, FLOAT, "dist3");
    if (!core->tmp_rc->dist || !core->tmp_rc->dist2 || !core->tmp_rc->dist3)
        return ;
}

bool    start_game(t_core *core)
{
    t_sprite    *sprite;
    t_weapon *wpn;

    wpn = &core->player->weapon[core->player->curr_wpn];
	core->tmp_3d = malloc(sizeof(t_tmp_3d));
    if (!core->tmp_3d)
        return (false);
    print_background(core);
    draw_minimap_game(core);
	get_raycast_data(core);
    print_player(core, 0xFFFF00);
    sprite = core->player->weapon[core->player->curr_wpn].anim;
	if (core->player->weapon[core->player->curr_wpn].lock)
    {
        if (core->player->firing)
            update_loaded_animation(wpn, sprite, true, core);
        else
            update_loaded_animation(wpn, sprite, false, core);
        if (!sprite->activ)
            wpn->lock = false;
    }
	fill_img_in_green(core->weapon_buffer);
    if (!update_projectiles(core))
        return (false);
    render_weapon(core);
    mlx_put_image_to_window(core->mlx, core->win, core->game_img->img, 0, 0);
	render_hud(core);
	render_head(core);
    return (true);
}
