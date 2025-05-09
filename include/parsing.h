/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 01:58:43 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/25 01:28:44 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>
# include "type.h"

//Extension checker
bool	valid_extension(char *version, char *tocheck);

//Extract all datas from .cub files
int		file_extract(t_core *core);

//check and extract textures from the file
bool	parse_textures_colors(t_core *core, char *prefix[7], void *targets[6]);

//Check if there's at least, 1 texture each, colors and a correct map
bool	check_flag_position(t_core *core, char *prefix[7]);

//Ensure correct RGB & texture character + convert colors in int arrays
bool	parse_textures_content(t_core *core, void *targets[6]);

//Check for wrong char in map and check walls
bool	parse_map(t_core *core);

//Checker to check if my player is surrounded by walls
bool	walkable(char **dup_maps, t_core *core);
#endif