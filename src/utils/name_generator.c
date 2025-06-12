/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:30:15 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/11 15:30:25 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	name_generator(int count, char *prefix_name, t_img *image, t_core *core)
{
	char		name[64];
	char		*num;

	name[0] = '\0';
	ft_strlcat(name, prefix_name, sizeof(name));
	num = ft_itoa(count++);
	if (!num)
		return (false);
	ft_strlcat(name, num, sizeof(name));
	hashmap_insert(&core->hashmap, name, image, core);
	free(num);
	return (true);
}
