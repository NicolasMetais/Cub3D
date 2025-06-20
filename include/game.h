/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 01:32:25 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/14 16:28:52 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <stdbool.h>

typedef struct s_rc3d
{
    float   line_h;
    float   line_s;
    float   line_e;
    float     x;
    float     y;
    int     start;
    int     end;
    int     pixel_index;
	float	tex_index;
	float	step;
	float	ty;
	float	ty_off;
	float	tx;
	float	offset;
	float 	tex_pos;
	int		draw_start;
	int		draw_end;

}	t_rc3d;

//r.. = rays data, m.. = map data, pl.. = player data, dist* = rays lenght;

typedef struct s_rc
{
	double	pl_x;
	double	pl_y;
	double	pldelt_x;
	double	pldelt_y;
	double	pl_angle;
	int		r;
	int		max_r;
	int		res; //always power of 2;
    int		mx;
    int		my;
    int		mp;
    int		px;
    int		py;
    double	rx;
    double	ry;
    double	ra;
	double	ca;
    double   x;
    double   y;
    double   atan;
    double   ntan;
    float   *dist;
    float   *dist2;
    float   *dist3;
	char	v_wall;
	char	h_wall;
	char	hit_wall;
	char	front_wall;
	int		front_x;
	int		front_y;
	double	hx;
	double	hy;
	double	vx;
	double	vy;
	int		of_x;	//values for collision and movements
	int		of_y;
	int		px2;
	int		py2;
	int		px2_add;
	int		py2_add;
	int		px2_sub;
	int		py2_sub;
	int		was_vertical;
	int		map_size;
	double	door_x;  //values for opening door
	double	door_y;
	float	*door_dist;
	double	v_door_x;
	double	v_door_y;
	float	*v_door_dist;
	double	h_door_x;
	double	h_door_y;
	float	*h_door_dist;
	int		open_door;

}	t_rc;

//start the game ;D
bool			start_game(t_core *core);

//Temp_functions
void			move_player(t_core *core, t_move move, double delta_time);
void			init_tmp(t_core *core);
bool			init_map_textures(t_core *core);
//??
void			init_new_pos(t_core *core);

//Layers printing
void			print_background(t_core *core);
void			print_player(t_core *core, int color);
void			print_rays(t_core *core, int color);
void			print_3d(t_core *core);
void			draw_ceiling_floor(t_core *core);
bool			rc_init(t_core *core);
void			rays_updates(t_core *core);
void			draw_player_line(t_core *core, int color);
void			move_player(t_core *core, t_move move, double delta_time);
void			init_tmp(t_core *core);

//Doors
void			anim_door(t_core *core);
void			handle_door(t_core *core);
void			print_anim_door(t_core *core, int i);
void			print_door_render(t_core *core);
void			get_door_loop_data(t_core *core);

//Minimap in game
void			draw_minimap_game(t_core *core);
void			print_miscellaneous(t_core *core, int color);
int				get_map_tile_x(t_core *core, int x);
int				get_map_tile_y(t_core *core, int y);

//Raycast
void			get_raycast_data(t_core *core);
void			loop_tiles_width(t_core *core, int i);
void			loop_tiles_height(t_core *core, int i);
void			draw_3d(t_core *core);
void			get_3d_based_data(t_core *core);
void			get_draw_start_data(t_core *core);
void			get_draw_loop_data(t_core *core);
void			print_3d_render(t_core *core);
void			print_3d_vertical(t_core *core);
void			print_3d_horizontal(t_core *core);
void			print_open_doors(t_core *core);
void			print_doors(t_core *core);

// //Layers printing
// void			print_background(t_core *core, int x, int y, int color);
// void			print_player(t_core *core, int color);
// void			print_rays(t_core *core, int color);
// void			print_3d(t_core *core, int pixel_index);
// void			get_rc_data(t_core *core);
// void			rays_updates(t_core *core);
// void			draw_player_line(t_core *core, int color);

#endif
