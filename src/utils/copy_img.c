/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:25:03 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/29 03:53:30 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//NEVER USED
void	copy_img(t_img *dest, t_img *copy)
{
	int	i;
	int	pixels;

	pixels = copy->width * copy->height;
	i = 0;
	while (i < pixels)
	{
		dest->addr[i] = copy->addr[i];
		i++;
	}
}
