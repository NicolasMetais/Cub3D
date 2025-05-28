/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 01:54:17 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/28 22:56:35 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define TILE 64
//FOV
# define FOV_MIN 60
# define FOV_MAX 120
# define FOV_DEFAULT 90

//SCALE IMAGE RENDERING
# define GAME_SCALE 5

# define SLIDER_SIZE 9

//WINDOW SIZE
# define S_LENGHT 1600
# define S_HEIGHT 1000

//MENU PLACEMENT
# define MENU_START_Y 540
# define MENU_SPACING 100

//VISIBLE SCROLLING ELEMENTS
# define VISIBLE 4

//LIBC
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/time.h>
# include <stdlib.h>
# include <dirent.h>
# include <limits.h>
//X11
# include <X11/keysym.h>
# include <X11/X.h>

//LIBS
# include "mlx.h"
# include "libft.h"

//HEADERS
# include "word_creator.h"
# include "parsing.h"
# include "hashmap.h"
# include "weapon.h"
# include "player.h"

//MATHS
# include <math.h>
# define PI 3.14159265359
# define RAD 0.0174533

extern int	map[];

typedef struct s_img_loader
{
	t_img	**img;
	char	*path;
}	t_img_loader;

typedef struct s_word_loader
{
	t_img		**img;
	char		*word;
	t_font_size	state;
}	t_word_loader;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_sprite
{
	t_img	**sprites;
	int		nb;
	int		frame;
	int		timer;
	int		speed;
}	t_sprite;

typedef struct s_menu_img
{
	t_img		*bg;
	t_img		*bg_clean;
	t_img		*slider_bar;
	t_img		*cursor;
	t_img		*loaded_map;
	t_img		*minimap;
	t_sprite	*skulls;
}	t_menu_img;

typedef struct s_hud_img
{
	t_img		*clean_hud;
	t_img		*hud;
	t_sprite	*neutral;
	t_sprite	*tired;
	t_sprite	*hurt;
	t_sprite	*bloody;
	t_sprite	*critical;
}	t_hud_img;

typedef enum s_state
{
	START_MENU,
	OPTIONS_MENU,
	MAPS_MENU,
	GAME,
}	t_state;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	t_img	*tmp_north;
	t_img	*tmp_south;
	t_img	*tmp_west;
	t_img	*tmp_east;
	char	*floor_color;
	char	*ceiling_color;
}	t_textures;

typedef struct s_colors
{
	t_int_array		*floor;
	t_int_array		*ceiling;
}	t_colors;

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_menu_maps
{
	char	*name;
	bool	parsed;
}	t_menu_maps;

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
	int		r;
	int		max_r;
	int		res; //always power of 2;
    int		mx;
    int		my;
    int		mp;
    int		px;
    int		py;
    float	rx;
    float	ry;
    float	ra;
	float	ca;
    float   x;
    float   y;
    float   atan;
    float   ntan;
    float   *dist;
    float   *dist2;
    float   *dist3;
	int		of_x;	//values for collision and movements
	int		of_y;
	int		px2;
	int		py2;
	int		px2_add;
	int		py2_add;
	int		px2_sub;
	int		py2_sub;
}	t_tmp_rc;

typedef struct s_core
{
	void			*mlx;
	void			*win;
	char			*map_name;
	char			**map;
	int				map_height;
	int				map_width;
	int				map_start;
	int				menu_option;
	bool			redraw;
	int				y_pos[4];
	char			tmp[2];
	int				enter;
	int				fov;
	float			fov_ratio;
	int				maps_nb;
	char			*loaded_map;
	bool			isclicked;
	bool			map_changed;
	int				x;
	int				y;
	int				scroll_offset;
	t_player		*player;
	t_menu_maps		*menu_maps;
	t_hashmap		hashmap;
	t_menu_img		*menu_img;
	t_state			state;
	t_hud_img		*hud_img;
	t_fonts			*fonts;
	t_textures		*textures;
	t_colors		*colors;
	t_pos			*spawn;
	t_gc_controller	*gc;
	t_tmp_rc		*tmp_rc;
	t_tmp_imgdata	*tmp_imgdata;
	t_tmp_3d		*tmp_3d;
	t_move			move;
}	t_core;

//Parsing
bool			parsing_cub(t_core *core, char *av);

//UTILS
bool			update_sprite(t_sprite *sprite);
bool			is_empty_line(char *str);
void			cleanup_split(char **str);
void			cleanup_game(t_core *core);
void			copy_img(t_img *dest, t_img *copy);

//TRANSPARENCY
void			transparency(t_img *bg, const t_img *stickonbg,
					int start_x, const int start_y);
void			put_on_bg(t_img *bg, size_t y, size_t x, int color);
unsigned int	get_img_pxl(const t_img *stickonbg, size_t x, size_t y);

//Create new t_img
bool			load_image(t_img **img, char *path, t_core *core, char *scale);
bool			load_word_image(t_img **img, t_core *core,
					char *word, char *state);
void			fill_img_in_green(t_img **img);

//Game
bool			launch_game(t_core *core);
int				routine(void *param);

//Menu
bool			start_menu(t_core *core);
bool			render_menu(t_core *core);
bool			render_maps_menu(t_core *core);
bool			extract_maps_names(t_core *core);
bool			render_options_menu(t_core *core);
void			skulls_render(t_core *core, const int *y, int frame);
bool			slider_constructor(t_core *core, int width);
bool			loaded_map(t_img *bg, t_core *core);

//Init img
bool			extract_img_data(t_core *core);

//Slider bar img construc
bool			slider_constructor(t_core *core, int width);

//MAP SELECTOR
bool			map_selector(t_core *core);

//Keypress Event
void			maps_menu_keypress(int key, t_core *core);
int				handle_keypress(int key, void *param);
int				handle_destroy(t_core *core);

//Mouse Event
int				mouse_menu_click(int button, int x, int y, t_core *core);
int				mouse_menu_hover(int x, int y, void *param);
int				mouse_menu_release(int button, int x, int y, t_core *core);
void			options_menu_hover(int x, int y, t_core *core);

//Slider Update
void			update_slider(t_core *core, const int *y, t_img *bg);

//Percent with number render
void			render_percent(t_core *core, char *percent, int render);

//Destroy X11 memory img
void			destroy_img(t_core *core);
bool			launch_game(t_core *core);
int				routine(void *param);

void			start_game(t_core *core);

//Keypress
int				handle_keypress(int key, void *param);
int				handle_destroy(t_core *core);
void			move_player(t_core *core, t_move move);

//Temp_functions
void	move_player(t_core *core, t_move move);
void	init_tmp(t_core *core);
void    init_map_textures(t_core *core);

//Layers printing
void    print_background(t_core *core, int x, int y, int color);
void    print_player(t_core *core, int color);
void    print_rays(t_core *core, int color);
void    print_3d(t_core *core);
void    get_rc_data(t_core *core);
void    rays_updates(t_core *core);
void    draw_player_line(t_core *core, int color);
void			move_player(t_core *core, t_move move);
void			init_tmp(t_core *core);

// //Layers printing
// void			print_background(t_core *core, int x, int y, int color);
// void			print_player(t_core *core, int color);
// void			print_rays(t_core *core, int color);
// void			print_3d(t_core *core, int pixel_index);
// void			get_rc_data(t_core *core);
// void			rays_updates(t_core *core);
// void			draw_player_line(t_core *core, int color);

//HUD
bool			render_hud(t_core *core);
bool			render_head(t_core *core);
bool			render_numbers(t_core *core);
bool			render_weapon_menu(t_core *core);
bool			render_ammo(t_core *core);
bool			head_init(t_core *core);


#endif