/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 01:58:43 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/13 01:41:23 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>

typedef struct s_core		t_core;
typedef struct s_pos		t_pos;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*path_sky;
	char	*path_door;
	char 	*path_open_door;
	t_img	*tmp_north;
	t_img	*tmp_south;
	t_img	*tmp_west;
	t_img	*tmp_east;
	t_img 	*open_doors;
	t_img	*sky;
	t_img	*door;
	char	*floor_color;
	char	*ceiling_color;
}	t_textures;

typedef struct s_colors
{
	t_int_array		*floor;
	t_int_array		*ceiling;
}	t_colors;

//Je stocke toutes les data que je parse au cas ou le parsing foire
typedef struct s_tmp
{
	char		*map_name;
	t_textures	*tmp_textures;
	t_colors	*tmp_colors;
	t_pos		*spawn;
	int			width;
	int			height;
	char		**tmp_maps;
	char		**tmp_map_content;
	char		*tmp_loaded_map;
	int			map_start;
}	t_tmp;

typedef struct s_parse_map
{
	size_t		i;
	int			j;
	int			count;
	char		*cpy;
	const char	*s;
}	t_parse_map;

//Extension checker
bool	valid_extension(char *version, char *tocheck);

//Extract all datas from .cub files
bool	file_extract(char *file_name, char ***tab, t_core *core);

//check and extract textures from the file
bool	parse_textures_colors(t_tmp *stock, char *prefix[7], void *targets[6]
			, t_core *core);

//Check if there's at least, 1 texture each, colors and a correct map
bool	check_flag_position(t_tmp *stock, char *prefix[7]);

//Ensure correct RGB & texture character + convert colors in int arrays
bool	parse_textures_content(t_core *core, t_tmp *stock, void *targets[6]);

//Check for wrong char in map and check walls
bool	parse_map(t_tmp *stock);

//Checker to check if my player is surrounded by walls
bool	walkable(char **dup_maps, t_tmp *stock);

//Free all temporary data from half-loaded maps
void	free_parsing(t_tmp *stock);

//Put all valid datas inside the garbage
bool	load_valid_datas(t_core *core, t_tmp *stock);

//dup_map for flood_fill
bool	realloc_map(t_tmp *stock, char **dup_maps);

//launch parsing
bool	parsing_cub(t_core *core, char *av);


#endif