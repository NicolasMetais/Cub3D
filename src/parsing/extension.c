/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 02:41:22 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/22 17:29:21 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Checking de l'extension .cub du fichier 
//FAUT LA FULL TESTER C'EST UN COPIER COLLER DE MON SO_LONG
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
