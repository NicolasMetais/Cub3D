/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_random_music.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:34:41 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/18 01:53:36 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	play_random_music(t_core *core)
{
	int	i;

	srand(time(NULL));
	i = rand() % 28;
	printf("%d\n",i);
	core->bg_music = LoadMusicStream(core->music_list[i]);
	printf("%s\n",core->music_list[i]);
	if (!core->bg_music.stream.buffer)
		return (false);
	PlayMusicStream(core->bg_music);
	return (true);
}
