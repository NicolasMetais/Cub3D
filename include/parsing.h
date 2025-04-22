/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 01:58:43 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/22 21:02:36 by nmetais          ###   ########.fr       */
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
bool	parse_textures_colors(t_core *core);

//checker to check if there's at least, 1 texture each, colors and a correct map
bool	check_map_validity(t_core *core);
#endif