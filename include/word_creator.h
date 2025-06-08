/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_creator.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 01:55:28 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/08 18:39:16 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORD_CREATOR_H
# define WORD_CREATOR_H

# include <stdbool.h>
# define N 100

typedef struct s_core	t_core;

typedef struct s_img	t_img;

typedef enum s_font_size
{
	SMALL,
	REGULAR,
	BIG,
}	t_font_size;

typedef struct s_font
{
	char	c;
	int		x_offset;
	int		y_offset;
	int		width;
	int		height;
}	t_font;

typedef struct s_fonts
{
	t_font_size		state;
	const t_font	*small;
	const t_font	*regular;
	const t_font	*big;
	t_img			*big_img;
	t_img			*regular_img;
	t_img			*small_img;
}	t_fonts;

void	init_chars_nodes(t_core	*core);

bool	build_words(t_core *core, t_img **img, t_font_size size, char *word);

bool	init_font(t_fonts *fonts, const t_font **selected_font,
			t_img **selected_sheet, t_core *core);

void	fill_img_in_green(t_img *img);

#endif