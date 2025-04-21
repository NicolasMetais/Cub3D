/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 02:02:15 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/21 15:47:38 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	cube3d(char *av)
{
	t_core			core;
	//int				*test;

	//core.gc = malloc(sizeof(t_gc_controller));
	//if (!core.gc)
	//	return (false);
	// core.gc->alloc_nb = 0;
	// core.gc->debug = false;
	// core.gc->start = NULL;
	ft_memset(&core, 0, sizeof(core));
	core.map_name = av;
	//ft_memset(&core.gc, 0, sizeof(t_gc_controller));
	printf("%s\n", core.map_name);
	if (!valid_extension(".cub", core.map_name))
	{
		ft_putendl_fd("Error \n Wrong map extension (.cub)", 2);
		return (false);
	}
	if (!parsing_map(&core))
		return (false);
	//test = gc_malloc(&core.gc, sizeof(int) * 2, TAB_INT);
	//Launch Game here;
	return (true);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!cube3d(av[1]))
			return (false);
	}
	else
		ft_putendl_fd("Error \n Don't be silly", 2);
	return (true);
}
