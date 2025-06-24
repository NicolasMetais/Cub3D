/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 02:08:56 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/24 15:00:17 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_ult(char **str)
{
	int	i;

	if (!str || !str[0])
		return ;
	i = 0;
	while (str[i])
		i++;
	while (i-- > 0)
		free(str[i]);
	free(str);
	str = NULL;
}

void	free_impact(t_core *core)
{
	t_impact_node	*temp;

	while (core->impact.impact_list)
	{
		temp = core->impact.impact_list;
		core->impact.impact_list = core->impact.impact_list->next;
		free(temp);
	}
}

void	free_proj(t_core *core)
{
	t_projectile_node	*head;
	t_projectile_node	*curr;
	t_projectile_node	*next;

	head = core->proj.proj_list;
	if (!head)
		return ;
	curr = head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	head = NULL;
}

void	cleanup_game(t_core *core)
{
	if (IsAudioDeviceReady())
	{
		unload_all_sound(core);
		CloseAudioDevice();
	}
	free_impact(core);
	free_proj(core);
	destroy_img(core);
	if (core->mlx && core->win)
		mlx_destroy_window(core->mlx, core->win);
	if (core->mlx)
		mlx_destroy_display(core->mlx);
	free_ult(core->textures->floor_colors);
	free_gc(core->gc, NULL);
	exit(0);
}
