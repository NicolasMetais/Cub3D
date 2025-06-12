/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:06:20 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/12 15:37:20 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*get_ammo_img(t_core *core, int type)
{
	if (type == 0)
		return (core->hud_img->ammo1);
	if (type == 1)
		return (core->hud_img->ammo2);
	if (type == 2)
		return (core->hud_img->ammo3);
	if (type == 3)
		return (core->hud_img->ammo4);
	return (NULL);
}

bool	hud_render_percent(t_img *buffer, t_core *core,
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
		if (!tempo)
			return (false);
		x += 44;
		transparency(buffer, tempo, x, 0);
	}
	x += 44;
	tempo = (t_img *)hashmap_get(&core->hashmap, "%");
	if (!tempo)
		return (false);
	transparency(buffer, tempo, x, 0);
	mlx_put_image_to_window(core->mlx, core->win, buffer->img, render, 880);
	free(percent);
	return (true);
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
		if (!tempo)
			return ;
		x += 44;
		transparency(buffer, tempo, x, 0);
	}
	mlx_put_image_to_window(core->mlx, core->win, buffer->img, render, 880);
	free(percent);
}
