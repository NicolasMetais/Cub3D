/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:16:14 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/02 23:03:37 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hud_render_percent(t_img *buffer, t_core *core,
			char *percent, int render)
{
	int		j;
	char	tmp[2];
	t_img	*tempo;
	int		x;

	j = -1;
	x = 0;
	while (percent[++j])
	{
		tmp[0] = percent[j];
		tmp[1] = '\0';
		tempo = (t_img *)hashmap_get(&core->hashmap, tmp);
		x += 44;
		transparency(buffer, tempo, x, 0);
	}
	x += 44;
	tempo = (t_img *)hashmap_get(&core->hashmap, "%");
	transparency(buffer, tempo, x, 0);
	mlx_put_image_to_window(core->mlx, core->win, buffer->img, render, 880);
	free(percent);
}


void	hud_render_number(t_img *buffer, t_core *core,
			char *percent, int render)
{
	int		j;
	char	tmp[2];
	t_img	*tempo;
	int		x;

	j = -1;
	x = 0;
	while (percent[++j])
	{
		tmp[0] = percent[j];
		tmp[1] = '\0';
		tempo = (t_img *)hashmap_get(&core->hashmap, tmp);
		x += 44;
		transparency(buffer, tempo, x, 0);
	}
	mlx_put_image_to_window(core->mlx, core->win, buffer->img, render, 880);
	free(percent);
}

//FAUT FAIRE CA SUR LES 2 AUTRE NUM DE MERDE ET LE HUD EST PIXEL PERFECT OPTIMISE DU CUL
bool	render_ammo_red_num(t_core *core)
{
	char	*number;
	int		ammo_type;

	ammo_type = core->player->weapon[core->player->current_weapon].ammo_type;
	if (core->hud_img->ammo1_render || core->hud_img->ammo2_render
		|| core->hud_img->ammo3_render || core->hud_img->ammo4_render)
	{
		number = ft_itoa(core->player->ammo[ammo_type]);
		if (!number)
			return (false);
		if (ft_strlen(number) == 1)
		{
			partial_copy_img(core->hud_img->ammo, core->hud_img->hud, 45, 40);
			hud_render_number(core->hud_img->ammo, core, number, 45);
		}
		else if (ft_strlen(number) == 2)
		{
			partial_copy_img(core->hud_img->ammo, core->hud_img->hud, 30, 40);
			hud_render_number(core->hud_img->ammo, core, number, 30);
		}
		else
		{
			partial_copy_img(core->hud_img->ammo, core->hud_img->hud, 15, 40);
			hud_render_number(core->hud_img->ammo, core, number, 15);
		}
	}
	return (true);
}

bool	render_numbers(t_core *core)
{
	char	*number;

	if (core->hud_img->health_render)
	{
		number = ft_itoa(core->player->health);
		if (!number)
			return (false);
		partial_copy_img(core->hud_img->health, core->hud_img->hud, 255, 40);
		hud_render_percent(core->hud_img->health, core, number, 255);
	}
	if (core->hud_img->armor_render)
	{
		number = ft_itoa(core->player->armor);
		if (!number)
			return (false);
		partial_copy_img(core->hud_img->armor, core->hud_img->hud, 945, 40);
		hud_render_percent(core->hud_img->armor, core, number, 945);
	}
	render_ammo_red_num(core);
	return (true);
}
