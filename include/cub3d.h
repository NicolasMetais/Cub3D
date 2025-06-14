/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 01:54:17 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/13 02:18:17 by nmetais          ###   ########.fr       */
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

//CHEAT AND DEBUG
# define INFINITE_AMMOS 0

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
# include "events.h"
# include "game.h"
# include "img.h"
# include "hashmap.h"
# include "parsing.h"
# include "hashmap.h"
# include "weapon.h"
# include "menu.h"
# include "hud.h"
# include "player.h"

//MATHS
# include <math.h>
# define PI 3.14159265359
# define RAD 0.0174533

typedef enum s_state
{
	START_MENU,
	OPTIONS_MENU,
	MAPS_MENU,
	GAME,
	PAUSE,
	PAUSE_OPTION,
}	t_state;

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

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
	bool			hud_redraw;
	int				x;
	int				y;
	int				scroll_offset;
	t_projectiles	proj;
	t_impact		impact;
	int				scroll_ingame;
	t_img			*game_img;
	t_img			*weapon_buffer;
	t_img			*pause_buffer;
	t_player		*player;
	t_menu_maps		*menu_maps;
	t_hashmap		hashmap;
	t_hashmap		hashmap_sprites;
	t_menu_img		*menu_img;
	t_state			state;
	t_hud_img		*hud_img;
	t_fonts			*fonts;
	t_textures		*textures;
	t_colors		*colors;
	t_pos			*spawn;
	t_gc_controller	*gc;
	t_rc		*rc;
	t_rc3d		*rc3d;
	t_moves			*r_straff;
	t_moves			*l_straff;
	t_moves			*up;
	t_moves			*down;
}	t_core;

//Norm struct for transparency with scaling i need so much variables zZzZzZzZzZz
typedef struct s_scale_ctx
{
	t_img		*bg;
	const t_img	*fg;
	t_pos		start;
	t_pos		scale;
}	t_scale_ctx;

//-----------------Game-----------------
//launch the game lol
bool			launch_game(t_core *core);
//routine function executed every frame
int				routine(void *param);

//---------------X11 shitty memory------------------
//destroy a non-used img from my hashmap
void			destroy_single_img(void *value, t_core *core);
//destroy all img from my hashmap
void			destroy_img(t_core *core);

//-------------UTILS-----------------
//regular sprite update
bool			update_sprite(t_sprite *sprite);
//update sprite on random nodes
bool			update_sprite_random(t_sprite *sprite);
//update weapon animation
bool			update_animation(t_sprite *sprite);
//generate a name with a concatenate id for hashmap good usage
bool			name_generator(int count, char *prefix_name,
					t_img *image, t_core *core);
//detect empty line in file
bool			is_empty_line(char *str);
//cleanup split
void			cleanup_split(char **str);
//clean all allocated memory + X11 memory
void			cleanup_game(t_core *core);
//copy an image pixel per pixels
void			copy_img(t_img *dest, t_img *copy);
//copy a part of an image
void			partial_copy_img(t_img *dest, t_img *copy,
					int x_start, int y_start);
//load an empty image for buffer purpose
t_img			*load_buffer(t_img *image, int x, int y, t_core *core);
//add transparency on green pixel + rescale an image
void			transparency_scaled(t_img *bg, const t_img *fg,
					t_pos start, int size);
//is my player moving ?
bool			is_moving(t_player *player);
//small getter for ammo type
t_img			*get_ammo_img(t_core *core, int type);
//regular transparency on green pixels
void			transparency(t_img *bg, const t_img *stickonbg,
					int start_x, const int start_y);
//put a pixel on another one
void			put_on_bg(t_img *bg, size_t y, size_t x, int color);
//get a pixel
unsigned int	get_img_pxl(const t_img *stickonbg, size_t x, size_t y);

//-----------------UTILS FOR THE MANDATORY PARTS-------------
bool			load_img(t_img **img, char *path, t_core *core);
int				mouse_direction(int x, int y, void *param);

#endif