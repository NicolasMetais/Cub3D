/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 01:54:17 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/27 16:59:28 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//STRUCTS
# include "type.h"

//LIBC
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/time.h>
# include <stdlib.h>
//X11
# include <X11/keysym.h>
# include <X11/X.h>

//LIBS
# include "mlx.h"
# include "libft.h"

//HEADERS
# include "parsing.h"

//MATHS
# include <math.h>
# define PI 3.14159
# define RAD 0.01745 / 16

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor_color;
	char	*ceiling_color;
}	t_textures;

typedef struct s_colors
{
	t_int_array		*floor;
	t_int_array		*ceiling;
}	t_colors;

typedef struct s_spawn
{
	int	x;
	int	y;
}	t_spawn;

typedef enum e_move {
	UP,
	DOWN,
	LEFT,
	RIGHT
}	t_move;

typedef struct s_tmp_imgdata
{
	char	*img_data;
	int		bpp;
	int		size;
	int		endian;
	void	*img;
}	t_tmp_imgdata;

typedef struct s_tmp_3d
{
    float   line_h;
    float   line_s;
    float   line_e;
    float     x;
    float     y;
}	t_tmp_3d;

//r.. = rays data, m.. = map data, pl.. = player data, dist* = rays lenght;

typedef struct s_tmp_rc
{
	float	pl_x;
	float	pl_y;
	float	pldelt_x;
	float	pldelt_y;
	float	pl_angle;
	int 	r;
	int		max_r;
	int		res; //always power of 2;
    int 	mx;
    int 	my;
    int 	mp;
    int 	px;
    int 	py;
    float   rx;
    float   ry;
    float   ra;
	float	ca;
    float   x;
    float   y;
    float   atan;
    float   ntan;
    float   *dist;
    float   *dist2;
    float   *dist3;
}	t_tmp_rc;

typedef struct s_core
{
	void			*mlx;
	void			*win;
	char			*map_name;
	char			**map;
	int				map_start;
	int				redraw;
	t_textures		*textures;
	t_colors		*colors;
	t_spawn			*spawn;
	t_gc_controller	*gc;
	t_tmp_rc		*tmp_rc;
	t_tmp_imgdata	*tmp_imgdata;
	t_tmp_3d		*tmp_3d;
	t_move			move;
}	t_core;

//Parsing
bool	parsing_cub(t_core *core, char *av);

//UTILS
bool	is_empty_line(char *str);

//Game
bool	launch_game(t_core *core);
int		routine(t_core *core);
void    start_game(t_core *core);

//Keypress
int		handle_keypress(int key, void *param);
int		handle_destroy(t_core *core);
void    move_player(t_core *core, t_move move);

//Temp_functions
void	move_player(t_core *core, t_move move);
void	init_tmp(t_core *core);

//Layers printing
void    print_background(t_core *core, int x, int y, int color);
void    print_player(t_core *core, int color);
void    print_rays(t_core *core, int color);
void    print_3d(t_core *core, int pixel_index);
void    get_rc_data(t_core *core);
void    rays_updates(t_core *core);
void    draw_player_line(t_core *core, int color);

#endif