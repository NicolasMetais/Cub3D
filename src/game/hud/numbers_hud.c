/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:16:14 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/08 18:51:38 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	render_ammo_red_num(t_core *core, t_img *bg)
{
	char	*num;

	if (!(core->hud_img->ammo1_render || core->hud_img->ammo2_render
			|| core->hud_img->ammo3_render || core->hud_img->ammo4_render))
		return (true);
	num = ft_itoa(core->player->ammo[core->player->weapon
		[core->player->curr_wpn].ammo_type]);
	if (!num)
		return (false);
	if (ft_strlen(num) == 1)
	{
		partial_copy_img(core->hud_img->ammo, bg, 45, 40);
		hud_render_number(core->hud_img->ammo, core, num, 45);
	}
	else if (ft_strlen(num) == 2)
	{
		partial_copy_img(core->hud_img->ammo, bg, 30, 40);
		hud_render_number(core->hud_img->ammo, core, num, 30);
	}
	else
	{
		partial_copy_img(core->hud_img->ammo, bg, 5, 40);
		hud_render_number(core->hud_img->ammo, core, num, 5);
	}
	return (true);
}

bool	render_health_red_num(t_core *core, t_img *bg)
{
	char	*num;

	if (core->hud_img->health_render)
	{
		num = ft_itoa(core->player->health);
		if (!num)
			return (false);
		if (ft_strlen(num) == 1)
		{
			partial_copy_img(core->hud_img->life, bg, 300, 40);
			if (!hud_render_percent(core->hud_img->life, core, num, 300))
				return (false);
		}
		else if (ft_strlen(num) == 2)
		{
			partial_copy_img(core->hud_img->life, bg, 270, 40);
			if (!hud_render_percent(core->hud_img->life, core, num, 270))
				return (false);
		}
		else
		{
			partial_copy_img(core->hud_img->life, bg, 250, 40);
			if (!hud_render_percent(core->hud_img->life, core, num, 250))
				return (false);
		}
	}
	return (true);
}

bool	render_armor_red_num(t_core *core, t_img *bg)
{
	char	*num;

	if (core->hud_img->armor_render)
	{
		num = ft_itoa(core->player->armor);
		if (!num)
			return (false);
		if (ft_strlen(num) == 1)
		{
			partial_copy_img(core->hud_img->armor, bg, 945, 40);
			if (!hud_render_percent(core->hud_img->armor, core, num, 945))
				return (false);
		}
		else if (ft_strlen(num) == 2)
		{
			partial_copy_img(core->hud_img->armor, bg, 930, 40);
			if (!hud_render_percent(core->hud_img->armor, core, num, 930))
				return (false);
		}
		else
		{
			partial_copy_img(core->hud_img->armor, bg, 905, 40);
			if (!hud_render_percent(core->hud_img->armor, core, num, 905))
				return (false);
		}
	}
	return (true);
}

bool	render_numbers(t_core *core, t_img	*bg)
{
	if (!render_health_red_num(core, bg))
		return (false);
	if (!render_armor_red_num(core, bg))
		return (false);
	if (!render_ammo_red_num(core, bg))
		return (false);
	return (true);
}
