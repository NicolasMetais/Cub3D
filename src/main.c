/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 02:02:15 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/27 14:04:41 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Initialisation du Garbage collector
bool	garbage_init(t_gc_controller **gc)
{
	*gc = malloc(sizeof(t_gc_controller));
	if (!*gc)
		return (false);
	ft_memset(*gc, 0, sizeof(t_gc_controller));
	return (true);
}

//Fonction corps du programme
int	cube3d(char *av)
{
	t_core			core;

	ft_memset(&core, 0, sizeof(core));
	garbage_init(&core.gc);
	parsing_cub(&core, av);
	//Launch Game here;
	//print_allocated_vars(&*core.gc, NULL);
	free_gc(core.gc, NULL);
	return (true);
}

//Main
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
