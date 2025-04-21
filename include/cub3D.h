/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 01:54:17 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/21 15:47:31 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//LIBC
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/time.h>
# include <stdlib.h>

//LIBS
# include "libft.h"

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		*floor_color;
	int		*ceiling_color;
}	t_texture;

typedef struct s_core
{
	char			*map_name;
	char			**map;
	t_texture		texture;
//	t_gc_controller	*gc;

}	t_core;

//extension checker
bool	valid_extension(char *version, char *tocheck);

//Extract all datas from .cub files
int		parsing_map(t_core *core);


#endif