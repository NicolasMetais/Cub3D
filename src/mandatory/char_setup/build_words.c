/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:25:43 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/12 20:14:17 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//GET WIDTH AND HEIGHT OF AN IMAGE
void	get_img_size(const t_fonts *fonts, char *word, int *w, int *h)
{
	int				i;
	int				j;
	const t_font	*selected_font;

	if (fonts->state == SMALL)
		selected_font = fonts->small;
	if (fonts->state == REGULAR)
		selected_font = fonts->regular;
	if (fonts->state == BIG)
		selected_font = fonts->big;
	i = -1;
	while (word[++i])
	{
		j = -1;
		while (++j < 68)
		{
			if (word[i] == selected_font[j].c || j == 67)
			{
				*w += selected_font[j].width;
				if (*h < selected_font[j].height)
					*h = selected_font[j].height;
				break ;
			}
		}
	}
}

//FIND THE RIGHT INDEX OF THE CHAR IN THE FONT
int	get_index(char c, const t_font *font)
{
	int	i;

	i = -1;
	while (++i < 68)
	{
		if (c == font[i].c || i == 67)
			return (i);
	}
	return (0);
}

//COPY A LETTER INSIDE MY TMP IMAGE
void	copy_letters(t_img **dest, int start_x, const t_font font, t_img *sheet)
{
	int				x;
	int				y;
	unsigned int	pixel;

	y = 0;
	while (y < font.height)
	{
		x = 0;
		while (x < font.width)
		{
			pixel = get_img_pxl(sheet, font.x_offset + x, font.y_offset + y);
			put_on_bg(*dest, (*dest)->height - font.height + y,
				start_x + x, pixel);
			x++;
		}
		y++;
	}
}

//WRITE ALL LETTER SIDE BY SIDE ON THE RIGH Y AXIX
void	write_words(t_img **img, t_fonts *fonts, char *word, t_core *core)
{
	int				i;
	int				j;
	int				px_start;
	const t_font	*selected_font;
	t_img			*selected_sheet;

	px_start = 0;
	j = 0;
	init_font(fonts, &selected_font, &selected_sheet, core);
	i = -1;
	while (word[++i])
	{
		j = get_index(word[i], selected_font);
		copy_letters(img, px_start, selected_font[j], selected_sheet);
		px_start += selected_font[j].width;
	}
}

//INIT WORD AND CREATE A TMP IMAGE TO WRITE THE WORDS
bool	build_words(t_core *core, t_img **img, t_font_size size, char *word)
{
	int		width;
	int		height;
	int		i;

	width = 0;
	height = 0;
	i = -1;
	if (size == SMALL)
		core->fonts->state = SMALL;
	if (size == REGULAR)
		core->fonts->state = REGULAR;
	if (size == BIG)
		core->fonts->state = BIG;
	get_img_size(core->fonts, word, &width, &height);
	(*img)->img = mlx_new_image(core->mlx, width, height);
	if (!(*img)->img)
		return (false);
	(*img)->width = width;
	(*img)->height = height;
	(*img)->addr = mlx_get_data_addr((*img)->img, &(*img)->bpp,
			&(*img)->line_len, &(*img)->endian);
	fill_img_in_green(*img);
	write_words(img, core->fonts, word, core);
	return (true);
}
