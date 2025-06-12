/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_menu_over.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:01:54 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/29 18:01:11 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_percent(t_core *core, char *percent, int render)
{
	int		j;
	char	tmp[2];
	t_img	*tempo;

	j = -1;
	while (percent[++j])
	{
		tmp[0] = percent[j];
		tmp[1] = '\0';
		tempo = (t_img *)hashmap_get(&core->hashmap, tmp);
		render += 44;
		transparency(core->menu_img->bg, tempo, render, 595);
	}
	render += 44;
	tempo = (t_img *)hashmap_get(&core->hashmap, "%");
	transparency(core->menu_img->bg, tempo, render, 595);
	free(percent);
	update_slider(core, core->y_pos, core->menu_img->bg);
}

void	update_fov_variable(t_core *core, int slider_min, int slider_max, int x)
{
	float	ratio;

	if (x < slider_min)
		core->x = slider_min;
	else if (x > slider_max)
		core->x = slider_max;
	else
		core->x = x;
	ratio = (float)(core->x - slider_min) / (slider_max - slider_min);
	if (ratio < 0.0f)
		ratio = 0.0f;
	else if (ratio > 1.0f)
		ratio = 1.0f;
	core->fov = (int)(FOV_MIN + ratio * (FOV_MAX - FOV_MIN));
}

void	slider(t_core *core, int slider_min, int slider_max, int x)
{
	char	*percent;

	update_fov_variable(core, slider_min, slider_max, x);
	percent = ft_itoa(core->fov);
	if (!percent)
		return ;
	render_percent(core, percent, 790);


}

void	options_menu_hover(int x, int y, t_core *core)
{
	int		i;
	int		slider_max;
	int		slider_min;

	i = -1;
	slider_min = core->menu_img->bg->width / 2 + 5 - 70;
	slider_max = slider_min + core->menu_img->slider_bar->width
		- 90 - core->menu_img->cursor->width;
	if (core->state == OPTIONS_MENU)
	{
		while (++i < 1)
		{
			if (y >= core->y_pos[i] && y < core->y_pos[i] + MENU_SPACING)
			{
				core->menu_option = i;
				render_options_menu(core);
				break ;
			}
		}
		if (core->isclicked)
			slider(core, slider_min, slider_max, x);
	}
}
