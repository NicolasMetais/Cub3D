/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 02:02:15 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/27 17:03:09 by nmetais          ###   ########.fr       */
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

bool	window_init(t_core *core)
{
	core->mlx = mlx_init();
	if (!core->mlx)
		return (false);
	if (!add_to_gc(&core->gc, core->mlx, STRUCT, "mlx"))
		return (false);
	core->win = mlx_new_window(core->mlx, 1920, 1080, "Cub3D");
	if (!core->win)
		return (false);
	return (true);
}

//Fonction corps du programme
int	cube3d(char *av)
{
	t_core			core;

	ft_memset(&core, 0, sizeof(core));
	if (!garbage_init(&core.gc))
		return (false);
	if (!parsing_cub(&core, av))
		return (false);
	if (!window_init(&core))
		return (false);
	if (!launch_game(&core))
		return (false);
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
