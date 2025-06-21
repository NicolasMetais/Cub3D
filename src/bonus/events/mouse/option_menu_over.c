/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_menu_over.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:01:54 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/21 16:53:32 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	render_percent(t_core *core, char *percent, int render, t_img *bg)
{
	int		j;
	char	tmp[2];
	t_img	*tempo;
	int		x;

	j = -1;
	x = 390;
	while (percent[++j])
	{
		tmp[0] = percent[j];
		tmp[1] = '\0';
		tempo = (t_img *)hashmap_get(&core->hashmap, tmp);
		if (!tempo)
			return (false);
		x += 44;
		transparency(bg, tempo, x, render);
	}
	x += 44;
	tempo = (t_img *)hashmap_get(&core->hashmap, "%");
	if (!tempo)
		return (false);
	transparency(bg, tempo, x, render);
	free(percent);
	return (true);
}

void	slider_updater(t_pos pos, int x, t_slider *slider, t_core *core)
{
	float	ratio;
	float	slider_width;

	slider_width = pos.y - pos.x;
	ratio = (float)(x - pos.x) / slider_width;
	if (ratio < 0.0f)
		ratio = 0.0f;
	else if (ratio > 1.0f)
		ratio = 1.0f;
	*slider->int_var = slider->min_val + ratio
		* (slider->max_val - slider->min_val);
	*slider->x_var = pos.x + ratio * slider_width;
	if (ft_strcmp(slider->label, "SOUND") == 0)
		SetMusicVolume(core->bg_music, ratio);
}

bool	percent_option_rendering(t_core *core, t_slider	*slider, t_img *bg)
{
	char	*percent;

	percent = ft_itoa(*slider->int_var);
	if (!percent)
		return (false);
	if (!ft_strcmp(slider->label, "FOV"))
	{
		if (!render_percent(core, percent, 550, bg))
			return (false);
	}
	else if (!ft_strcmp(slider->label, "SPEED"))
	{
		if (!render_percent(core, percent, 685, bg))
			return (false);
	}
	else if (!ft_strcmp(slider->label, "SOUND"))
	{
		if (!render_percent(core, percent, 830, bg))
			return (false);
	}
	return (true);
}

bool	percent_pause_option_rendering(t_core *core,
			t_slider	*slider, t_img *bg)
{
	char	*percent;

	percent = ft_itoa(*slider->int_var);
	if (!percent)
		return (false);
	if (!ft_strcmp(slider->label, "FOV"))
	{
		if (!render_percent(core, percent, 350, bg))
			return (false);
	}
	else if (!ft_strcmp(slider->label, "SPEED"))
	{
		if (!render_percent(core, percent, 490, bg))
			return (false);
	}
	else if (!ft_strcmp(slider->label, "SOUND"))
	{
		if (!render_percent(core, percent, 630, bg))
			return (false);
	}
	return (true);
}

void	options_menu_hover(int x, int y, t_core *core)
{
	int			i;
	t_pos		pos;
	t_slider	*slider;

	i = -1;
	if (core->state != OPTIONS_MENU && core->state != PAUSE_OPTION)
		return ;
	while (++i < 5)
	{
		if (y >= core->y_pos[i] && y < core->y_pos[i] + MENU_SPACING)
		{
			core->menu_option = i;
			if (core->state == OPTIONS_MENU)
				render_options_menu(core);
			else if (core->state == PAUSE_OPTION)
				render_pause_options(core);
			break ;
		}
	}
	if (!core->isclicked)
		return ;
	slider = &core->menu_img->sliders[core->active_slider];
	pos.x = slider->slider_min;
	pos.y = slider->slider_max;
	slider_updater(pos, x, slider, core);
}
