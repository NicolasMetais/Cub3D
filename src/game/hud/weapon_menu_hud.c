/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_menu_hud.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:51:43 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/12 16:52:09 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*pick_img(int i, t_core *core)
{
	char	*num;
	char	*file_id;

	num = ft_itoa(i);
	if (!num)
		return (false);
	if (core->player->weapon[i].owned)
	{
		file_id = ft_strjoin(num, "_yellow");
		if (!file_id)
			return (free(num), NULL);
	}
	else
	{
		file_id = ft_strjoin(num, "_grey");
		if (!file_id)
			return (free(num), NULL);
	}
	free(num);
	return (file_id);
}

void	coor_update(int i, int *x, int *y)
{
	if (i == 4)
	{
		*y += 50;
		*x = 555;
	}
	else
		*x += 59;
}

bool	render_weapon_menu(t_core *core)
{
	t_img	*number;
	int		i;
	char	*file_id;
	int		x;
	int		y;

	i = 1;
	x = 555;
	y = 21;
	while (++i < 8)
	{
		file_id = pick_img(i, core);
		number = (t_img *)hashmap_get(&core->hashmap, file_id);
		free(file_id);
		if (!number)
			return (false);
		transparency(core->hud_img->hud, number, x, y);
		coor_update(i, &x, &y);
	}
	return (true);
}
