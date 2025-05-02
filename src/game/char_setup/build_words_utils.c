/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_words_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:08:06 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/02 15:38:38 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//SELECT RIGHT DATAS DEPENDING ON THE STATE GIVEN
void	init_font(t_fonts *fonts, const t_font **selected_font,
		t_img **selected_sheet)
{
	if (fonts->state == SMALL)
	{
		*selected_font = fonts->small;
		*selected_sheet = fonts->small_img;
	}
	if (fonts->state == REGULAR)
	{
		*selected_font = fonts->regular;
		*selected_sheet = fonts->regular_img;
	}
	if (fonts->state == BIG)
	{
		*selected_font = fonts->big;
		*selected_sheet = fonts->big_img;
	}
}

//FILL MY TMP IMG WITH GREEN (THE COLOR FOR TRANSPARENCY)
void	fill_img_in_green(t_img **img)
{
	int				i;
	unsigned int	*pixels;

	i = -1;
	pixels = (unsigned int *)(*img)->addr;
	while (++i < ((*img)->width * (*img)->height))
		pixels[i] = 0x00FF00;
}
