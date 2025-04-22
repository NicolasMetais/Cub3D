/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:16:42 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/22 16:13:34 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

//Checking de l'extension .cub du fichier 
//FAUT LA FULL TESTER C'EST UN COPIER COLLER DE MON SO_LONG
bool	parsing_cub(t_core *core, char *av)
{
	core->map_name = av;
	if (!valid_extension(".cub", core->map_name))
	{
		ft_putendl_fd("Error \n Wrong map extension (.cub)", 2);
		return (false);
	}
	if (!parsing_map(core))
		return (false);
	print_allocated_vars(core->gc, "map");
	return (true);
}
