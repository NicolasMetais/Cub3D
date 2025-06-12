/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:00:22 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/12 23:51:54 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	load_img(t_img **img, char *path, t_core *core)
{
	int	width;
	int	height;

	(*img)->img = mlx_xpm_file_to_image(core->mlx, path,
			&width, &height);
	if (!(*img)->img)
		return (ft_putendl_fd("Error \n Corrupted", 2), false);
	(*img)->addr = mlx_get_data_addr((*img)->img, &(*img)->bpp,
			&(*img)->line_len, &(*img)->endian);
	(*img)->width = width;
	(*img)->height = height;
	return (true);
}
