/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_menu_hud.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:51:43 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/29 18:01:38 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	render_weapon_menu(t_core *core)
{
	t_img	*number;
	int		i;
	char	*file_id;
	char	*num;
	int		x;
	int		y;

	i = 1;
	x = 555;
	y = 21;
	while (++i < 8)
	{
		num = ft_itoa(i);
		if (!num)
			return (false);
		if (core->player->weapon[i].owned)
		{
			file_id = ft_strjoin(num, "_yellow");
			if (!file_id)
				return (free(num), false);
		}
		else
		{
			file_id = ft_strjoin(num, "_grey");
			if (!file_id)
				return (free(num), false);
			number = (t_img *)hashmap_get(&core->hashmap, file_id);
		}
		number = (t_img *)hashmap_get(&core->hashmap, file_id);
		free(file_id);
		transparency(core->hud_img->hud, number, x, y);
		free(num);
		if (i == 4)
		{
			y += 50;
			x = 555;
		}
		else
			x += 59;
	}
	return(true);
}
