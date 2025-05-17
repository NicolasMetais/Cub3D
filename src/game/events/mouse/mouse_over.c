/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_over.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 03:13:52 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/17 13:34:19 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	starting_menu_hover(int y, t_core *core)
{
	int	i;

	i = -1;
	if (core->state == START_MENU)
	{
		while (++i < 4)
		{
			if (y >= core->y_pos[i] && y < core->y_pos[i] + MENU_SPACING)
			{
				core->menu_option = i;
				render_menu(core);
				break ;
			}
		}
	}
}

void	options_menu_hover(int x, int y, t_core *core)
{
	int		i;
	int		j;
	int		slider_min;
	int		slider_max;
	float	ratio;
	char 	*percent;
	char 	tmp[2];
	t_img	*tempo;

	i = -1;
	j = -1;
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
		{
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
			percent = ft_itoa(core->fov);
			if (!percent)
				return ;
			while (percent[++j])
			{
				tmp[0] = percent[j];
				tmp[1] = '\0';
				printf("%c", percent[j]);
				tempo = hashmap_get(&core->hashmap, tmp);
				if (j == 0)
					transparency(core->menu_img->bg, tempo, 200, 200);
				if (j == 1)
					transparency(core->menu_img->bg, tempo, 250, 200);
				if (j == 2)
					transparency(core->menu_img->bg, tempo, 300, 200);
			}
			tempo = hashmap_get(&core->hashmap, "%");
			transparency(core->menu_img->bg, tempo, 0, 150);
			printf("\n");
			free(percent);
			update_slider(core, core->y_pos, core->menu_img->bg);
		}
	}
}

void	maps_menu_hover(int y, t_core *core)
{
	int	i;

	i = -1;
	if (core->state == MAPS_MENU)
	{
		while (++i < core->maps_nb)
		{
			if (y >= core->y_pos[i] && y < core->y_pos[i] + MENU_SPACING)
			{
				core->menu_option = i;
				render_maps_menu(core);
				break ;
			}
		}
	}
}

//CLICK MANAGEMENT
int	mouse_menu_hover(int x, int y, void *param)
{
	t_core		*core;

	(void)x;
	core = (t_core *)param;
	starting_menu_hover(y, core);
	options_menu_hover(x, y, core);
	maps_menu_hover(y, core);
	return (0);
}


