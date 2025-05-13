/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 01:54:17 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/13 20:19:13 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//SCALE IMAGE RENDERING
# define GAME_SCALE 5

# define S_LENGHT 1600
# define S_HEIGHT 1000
//MENU PLACEMENT
# define MENU_START_Y 540
# define MENU_SPACING 100

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
	t_sprite	*skulls;
}	t_menu_img;

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

typedef struct s_menu_maps
{
	char	*name;
	bool	parsed;
}	t_menu_maps;

typedef struct s_core
{
	void			*mlx;
	void			*win;
	char			*map_name;
	char			**map;
	int				map_start;
	int				menu_option;
	bool			redraw;
	int				y_pos[4];
	int				enter;
	int				maps_nb;
	t_menu_maps		*menu_maps;
	t_hashmap		hashmap;
	t_menu_img		*menu_img;
	t_state			state;
	t_fonts			*fonts;
	t_textures		*textures;
	t_colors		*colors;
	t_spawn			*spawn;
	t_gc_controller	*gc;

}	t_core;

//TEMPORAIRE
void			skulls_render_tempo(t_core *core, const int *y, int frame);

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

//Init img
bool			extract_img_data(t_core *core);

//Keypress Event
int				handle_keypress(int key, void *param);
int				handle_destroy(t_core *core);

//Mouse Event
int				mouse_menu_click(int button, int x, int y, t_core *core);
int				mouse_menu_hover(int x, int y, void *param);

//Destroy X11 memory img
void			destroy_img(t_core *core);


#endif