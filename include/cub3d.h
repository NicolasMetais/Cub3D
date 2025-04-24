/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 01:54:17 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/23 16:03:26 by nmetais          ###   ########.fr       */
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

//LIBS
# include "libft.h"

//HEADERS
# include "parsing.h"

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
	t_int_array		*floor_color;
	t_int_array		*ceiling_color;
}	t_colors;

typedef struct s_core
{
	char			*map_name;
	char			**map;
	int				map_start;
	t_textures		*textures;
	t_colors		*colors;
	t_gc_controller	*gc;

}	t_core;

//Parsing
bool	parsing_cub(t_core *core, char *av);


#endif