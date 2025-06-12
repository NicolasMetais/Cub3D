/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ammo_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:51:54 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/12 15:36:30 by nmetais          ###   ########.fr       */
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
		number = (t_img *)hashmap_get(&core->hashmap, file_id);
		if (!number)
			return (false);
		free(file_id);
		transparency(core->hud_img->hud, number, x, y);
		x -= 20;
	}
	return (true);
}

bool	display_ammo_number(t_core *core, char *num, int ammo_type, int *x)
{
	t_img	*number;
	char	*file_id;
	int		i;

	i = ft_strlen(num);
	while (--i >= 0)
	{
		core->tmp[0] = num[i];
		file_id = ft_strjoin(core->tmp, "_yellow");
		if (!file_id)
			return (false);
		number = (t_img *)hashmap_get(&core->hashmap, file_id);
		if (!number)
			return (free(file_id), false);
		free(file_id);
		transparency(get_ammo_img(core, ammo_type), number, *x, 0);
		*x -= number->width;
	}
	return (true);
}

bool	write_ammo_type(t_core *core, int y, int ammo_type, char *max_mun)
{
	char	*num;
	int		x;

	x = 40;
	num = ft_itoa(core->player->ammo[ammo_type]);
	if (!num)
		return (false);
	if (!display_ammo_number(core, num, ammo_type, &x))
		return (free(num), false);
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

bool	render_ammo(t_core *core, t_img *bg)
{
	unsigned int		i;
	int					y;
	t_img				*img_ammo[4];

	i = -1;
	y = 25;
	render_ammo_init(core, img_ammo);
	while (++i < 4)
	{
		partial_copy_img(img_ammo[i], bg, 1380, y);
		y += 30;
	}
	if (!write_ammo_type(core, 25, 0, "200"))
		return (false);
	if (!write_ammo_type(core, 55, 1, "50"))
		return (false);
	if (!write_ammo_type(core, 85, 2, "50"))
		return (false);
	if (!write_ammo_type(core, 115, 3, "300"))
		return (false);
	mlx_put_image_to_window(core->mlx, core->win, img_ammo[0]->img, 1380, 865);
	mlx_put_image_to_window(core->mlx, core->win, img_ammo[1]->img, 1380, 895);
	mlx_put_image_to_window(core->mlx, core->win, img_ammo[2]->img, 1380, 925);
	mlx_put_image_to_window(core->mlx, core->win, img_ammo[3]->img, 1380, 955);
	return (true);
}
