/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 02:35:31 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/08 18:27:31 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_on_img(t_img **bg, size_t y, size_t x, int pixel)
{
	char	*change_pix;

	change_pix = (*bg)->addr + (y * (*bg)->line_len + x * ((*bg)->bpp / 8));
	*(unsigned int *) change_pix = pixel;
}

void	resize_img(t_img *original, t_img **resized, int scale)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	pixel;

	y = -1;
	while (++y < original->height)
	{
		x = -1;
		while (++x < original->width)
		{
			pixel = get_img_pxl(original, x, y);
			dy = -1;
			while (++dy < scale)
			{
				dx = -1;
				while (++dx < scale)
					put_on_img(resized, y * scale + dy,
						x * scale + dx, pixel);
			}
		}
	}
}

//MALLOC IMG AND SETUP THE T_IMG WITH GET_DATA_ADDR
bool	load_image(t_img **img, char *path, t_core *core, char *scale)
{
	t_img	*original;

	original = malloc(sizeof(t_img));
	if (!original)
		return (false);
	original->img = mlx_xpm_file_to_image(core->mlx, path, &original->width,
			&original->height);
	if (!original->img)
		return (ft_putendl_fd("Error \n Images corrupted", 2), free(original), false);
	original->addr = mlx_get_data_addr(original->img, &original->bpp,
			&original->line_len, &original->endian);
	*img = gc_malloc(&core->gc, sizeof(t_img), STRUCT, "image du menu");
	if (!*img)
		return (false);
	(*img)->img = mlx_new_image(core->mlx, original->width * ft_atoi(scale),
			original->height * ft_atoi(scale));
	if (!(*img)->img)
		return (ft_putendl_fd("Error \n Images corrupted", 2), free(original), false);
	(*img)->addr = mlx_get_data_addr((*img)->img, &(*img)->bpp,
			&(*img)->line_len, &(*img)->endian);
	resize_img(original, img, ft_atoi(scale));
	(*img)->width = original->width * ft_atoi(scale);
	(*img)->height = original->height * ft_atoi(scale);
	mlx_destroy_image(core->mlx, original->img);
	return (free(original), true);
}

//INIT A WORD IMAGE
bool	load_word_image(t_img **img, t_core *core, char *word, char *state)
{
	*img = gc_malloc(&core->gc, sizeof(t_img), STRUCT, "writing");
	if (!*img)
		return (false);
	if (!ft_strcmp(state, "small"))
		build_words(core, img, SMALL, word);
	else if (!ft_strcmp(state, "regular"))
		build_words(core, img, REGULAR, word);
	else if (!ft_strcmp(state, "big"))
		build_words(core, img, BIG, word);
	else
		return (ft_putendl_fd(
				"Error \n wrong word size in config.txt", 2), false);
	if (!(*img)->img)
		return (ft_putendl_fd("Error \n word images corrupted", 2), false);
	return (true);
}
