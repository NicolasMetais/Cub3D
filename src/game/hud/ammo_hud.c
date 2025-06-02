/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ammo_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:51:54 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/02 21:09:11 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img	*get_ammo_img(t_core *core, int type)
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
		number = (t_img *)hashmap_get(&core->hashmap, file_id);
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

	x = 40;
	num = ft_itoa(core->player->ammo[ammo_type]);
	if (!num)
		return (false);
	i = ft_strlen(num);
	while (--i >= 0)
	{
		core->tmp[0] = num[i];
		file_id = ft_strjoin(core->tmp, "_yellow");
		if (!file_id)
			return (free(num), false);
		number = (t_img *)hashmap_get(&core->hashmap, file_id);
		free(file_id);
		transparency(get_ammo_img(core, ammo_type), number, x, 0);
		x -= number->width;
	}
	if (!write_max_mun(core, x, y, max_mun))
		return (free(num), false);
	return (free(num), true);
}

void	render_ammo_init(t_core *core, t_img *img_ammo[4])
{
	img_ammo[0] = core->hud_img->ammo1;
	img_ammo[1] = core->hud_img->ammo2;
	img_ammo[2] = core->hud_img->ammo3;
	img_ammo[3] = core->hud_img->ammo4;
	core->tmp[1] = '\0';
}

bool	render_ammo(t_core *core)
{
	unsigned int		i;
	int					y;
	t_img				*img_ammo[4];

	i = -1;
	y = 25;
	render_ammo_init(core, img_ammo);
	while (++i < 4)
	{
		partial_copy_img(img_ammo[i], core->hud_img->hud, 1380, y);
		y += 30;
	}
	write_ammo_type(core, 25, 0, "200");
	write_ammo_type(core, 55, 1, "50");
	write_ammo_type(core, 85, 2, "50");
	write_ammo_type(core, 115, 3, "300");
	mlx_put_image_to_window(core->mlx, core->win, img_ammo[0]->img, 1380, 860);
	mlx_put_image_to_window(core->mlx, core->win, img_ammo[1]->img, 1380, 890);
	mlx_put_image_to_window(core->mlx, core->win, img_ammo[2]->img, 1380, 920);
	mlx_put_image_to_window(core->mlx, core->win, img_ammo[3]->img, 1380, 950);
	return (true);
}
