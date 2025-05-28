/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ammo_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:51:54 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/28 19:45:37 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	write_max_mun(t_core *core, int x, int y, char *max_mun)
{
	t_img	*number;
	char	*file_id;
	int		i;

	i = ft_strlen(max_mun) - 1;
	x = 1560;
	while (i >= 0)
	{
		core->tmp[0] = max_mun[i--];
		file_id = ft_strjoin(core->tmp, "_yellow");
		if (!file_id)
			return (false);
		number = hashmap_get(&core->hashmap, file_id);
		free(file_id);
		transparency(core->hud_img->hud, number, x, y);
		x -= 20;
	}
	return (true);
}

bool	write_ammo_type(t_core *core, int y, int ammo_type, char *max_mun)
{
	t_img	*number;
	char	*num;
	char	*file_id;
	int		i;
	int		x;

	x = 1420;
	num = ft_itoa(core->player->ammo[ammo_type]);
	if (!num)
		return (false);
	i = ft_strlen(num) - 1;
	while (i >= 0)
	{
		core->tmp[0] = num[i--];
		file_id = ft_strjoin(core->tmp, "_yellow");
		if (!file_id)
			return (free(num), false);
		number = hashmap_get(&core->hashmap, file_id);
		free(file_id);
		transparency(core->hud_img->hud, number, x, y);
		x -= 20;
	}
	if (!write_max_mun(core, x, y, max_mun))
		return (free(num), false);
	return (free(num), true);
}

bool	render_ammo(t_core *core)
{
	core->tmp[1] = '\0';
	write_ammo_type(core, 25, 0, "200");
	write_ammo_type(core, 55, 1, "50");
	write_ammo_type(core, 85, 2, "50");
	write_ammo_type(core, 115, 3, "300");
	return (true);
}
