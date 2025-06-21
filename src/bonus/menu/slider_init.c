/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slider_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 00:17:59 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/21 18:45:29 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	sliders_init_third(t_core *core, int width)
{
	core->menu_img->sliders[4] = (t_slider){
		.slider_min = 1255,
		.slider_max = 1285,
		.x_var = &core->cursor[4],
		.int_var = &core->infinite_ammos,
		.min_val = 0,
		.max_val = 1,
		.label = "AMMOS"
	};
	if (!slider_constructor(core, width))
		return (false);
	if (!small_slider_constructor(core))
		return (false);
	return (true);
}

bool	sliders_init_bis(t_core *core, int width)
{
	core->menu_img->sliders[2] = (t_slider){
		.slider_min = 325,
		.slider_max = 635,
		.x_var = &core->cursor[2],
		.int_var = &core->sound,
		.min_val = 0,
		.max_val = 100,
		.label = "SOUND"
	};
		core->menu_img->sliders[3] = (t_slider){
		.slider_min = 1255,
		.slider_max = 1285,
		.x_var = &core->cursor[3],
		.int_var = &core->godmod,
		.min_val = 0,
		.max_val = 1,
		.label = "GODMOD"
	};
	if (!sliders_init_third(core, width))
		return (false);
	return (true);
}

bool	sliders_init(t_core *core, int width)
{
	core->menu_img->sliders[0] = (t_slider){
		.slider_min = 325,
		.slider_max = 635,
		.x_var = &core->cursor[0],
		.int_var = &core->fov,
		.min_val = FOV_MIN,
		.max_val = FOV_MAX,
		.label = "FOV"
	};
	core->menu_img->sliders[1] = (t_slider){
		.slider_min = 325,
		.slider_max = 635,
		.x_var = &core->cursor[1],
		.int_var = &core->speed,
		.min_val = 10,
		.max_val = 150,
		.label = "SPEED"
	};
	if (!sliders_init_bis(core, width))
		return (false);
	return (true);
}
