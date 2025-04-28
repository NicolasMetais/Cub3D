/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 01:54:17 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/28 05:48:09 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define S_LENGHT 1920
# define S_HEIGHT 1080
//MENU PLACEMENT
# define MENU_START_Y 300
# define MENU_SPACING 150

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

typedef struct s_menu_img
{
	t_img	*skulls_left;
	t_img	*skulls_right;
	t_img	*bg;
	t_img	*play;
	t_img	*maps;
	t_img	*options;
	t_img	*quit;
}	t_menu_img;

typedef enum s_state
{
	MENU,
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

typedef struct s_core
{
	void			*mlx;
	void			*win;
	char			*map_name;
	char			**map;
	int				map_start;
	int				menu_option;
	t_menu_img		*menu_img;
	t_state			state;
	t_textures		*textures;
	t_colors		*colors;
	t_spawn			*spawn;
	t_gc_controller	*gc;

}	t_core;

//Parsing
bool	parsing_cub(t_core *core, char *av);

//UTILS
bool	is_empty_line(char *str);
void	transparency(t_img *bg, const t_img *stickonbg,
			int start_x, const int start_y);

//Game
bool	launch_game(t_core *core);
int		routine(void *param);

//Menu
bool	render_menu(t_core *core);

//Keypress
int		handle_keypress(int key, void *param);
int		handle_destroy(t_core *core);

//Destroy X11 memory img
void	destroy_img(t_core *core);


#endif