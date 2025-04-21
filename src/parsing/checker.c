/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 02:41:22 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/20 03:07:10 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	valid_extension(char *version, char *tocheck)
{
	size_t	sizeversion;
	size_t	sizecheck;

	sizeversion = ft_strlen(version);
	sizecheck = ft_strlen(tocheck);
	while (sizeversion > 0)
	{
		if (version[sizeversion - 1] != tocheck[sizecheck - 1])
			return (false);
		sizeversion--;
		sizecheck--;
	}
	return (true);
}
