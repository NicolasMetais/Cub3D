/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_words_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:08:06 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/29 18:01:02 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//SELECT RIGHT DATAS DEPENDING ON THE STATE GIVEN
void	init_font(t_fonts *fonts, const t_font **selected_font,
		t_img **selected_sheet, t_core *core)
{
	if (fonts->state == SMALL)
	{
		*selected_sheet = (t_img *)hashmap_get(&core->hashmap, "Small_sheet");
		*selected_font = fonts->small;
	}
	if (fonts->state == REGULAR)
	{
		*selected_sheet = (t_img *)hashmap_get(&core->hashmap, "Regular_sheet");
		*selected_font = fonts->regular;
	}
	if (fonts->state == BIG)
	{
		*selected_sheet = (t_img *)hashmap_get(&core->hashmap, "Big_sheet");
		*selected_font = fonts->big;
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
