/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 02:35:31 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/05 06:26:47 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//MALLOC IMG AND SETUP THE T_IMG WITH GET_DATA_ADDR
bool	load_image(t_img **img, void *mlx, char *path, t_core *core)
{
	*img = gc_malloc(&core->gc, sizeof(t_img), STRUCT, "image du menu");
	if (!*img)
		return (false);
	(*img)->img = mlx_xpm_file_to_image(mlx, path, &(*img)->width,
			&(*img)->height);
	if (!(*img)->img)
		return (ft_putendl_fd("Error \n Menu images corrupted", 2), false);
	(*img)->addr = mlx_get_data_addr((*img)->img, &(*img)->bpp,
			&(*img)->line_len, &(*img)->endian);
	return (true);
}

//INIT A WORD IMAGE
bool	load_word_image(t_img **img, t_core *core, char *word, char *state)
{
	*img = gc_malloc(&core->gc, sizeof(t_img), STRUCT, "writing");
	if (!*img)
		return (false);
	if (!ft_strcmp(state, "small"))
		build_words(core, img, SMALL, word);
	else if (!ft_strcmp(state, "regular"))
		build_words(core, img, REGULAR, word);
	else if (!ft_strcmp(state, "big"))
		build_words(core, img, BIG, word);
	else
		return (ft_putendl_fd(
				"Error \n wrong word size in config.txt", 2), false);
	if (!(*img)->img)
		return (ft_putendl_fd("Error \n word images corrupted", 2), false);
	return (true);
}

bool	store_img(char **line, t_core *core)
{
	t_img	*img;

	img = NULL;
	if (line[2] && (!ft_strncmp(line[2], "word_creator:", 13)))
	{
		line[2] += 13;
		if (!load_word_image(&img, core,
				line[1], line[2]))
			return (line[2] -= 13, false);
		line[2] -= 13;
	}
	else
	{
		if (!load_image(&img, core->mlx, line[1], core))
			return (false);

	}
	if (!hashmap_insert(&core->hashmap, line[0], img, core))
	{
		ft_putendl_fd("Error: Failed to insert image into hashmap", 2);
		return (false);
	}
	return (true);
}

//LOAD HORRIBLE D'IMAGE POUR PASSER LA NORME JE VAIS FAIRE UNE HASHMAP
bool	extract_img_data(t_core *core)
{
	int		i;
	int		size;
	char	**data;
	char	**tmp;

	i = -1;
	size = 0;
	data = NULL;
	if (!file_extract("config.txt", &data))
		return (ft_free_tab(data), false);
	while (data[++i])
	{
		if (data[i][0] == '#' || !data[i][0])
			continue ;
		size++;
	}
	i = -1;
	if (!hashmap_init(core, size))
		return (false);
	while (data[++i])
	{
		if (data[i][0] == '#' || !data[i][0])
			continue ;
		tmp = ft_split(data[i], '\t');
		if (!tmp)
			return (false);
		if (!store_img(tmp, core))
			return (ft_free_tab(tmp), ft_free_tab(data), false);
		size++;
		ft_free_tab(tmp);
	}
	return (ft_free_tab(data), true);
}

/* bool	init_menu_img(t_core *core)
{
	int					i;
	const t_img_loader	images[] = {
	{&core->menu_img->bg, "menu/bg.xpm"},
	{&core->menu_img->option_win, "menu/submenu.xpm"},
	{&core->fonts->big_img, "sheets/big.xpm"},
	{&core->fonts->regular_img, "sheets/regular.xpm"},
	{&core->fonts->small_img, "sheets/small.xpm"},
	{NULL, NULL}};

	i = -1;
	while (images[++i].img)
	{
		if (!load_image(images[i].img, core->mlx, images[i].path, core))
			return (false);
	}
	return (true);
}

//LOAD HORRIBLE D'IMAGE POUR PASSER LA NORME JE VAIS FAIRE UNE HASHMAP
bool	init_words_img(t_core *core)
{
	int					i;
	const t_word_loader	images[] = {
	{&core->menu_img->play, "Kifdhfdfjkfdsuyll", REGULAR},
	{&core->menu_img->options, "Options", REGULAR},
	{&core->menu_img->maps, "Maps", REGULAR},
	{&core->menu_img->quit, "Death", REGULAR},
	{&core->menu_img->option1, "Options Random 1", REGULAR},
	{&core->menu_img->option2, "Options Random 2", REGULAR},
	{NULL, NULL, 0}};

	i = -1;
	while (images[++i].img)
	{
		if (!load_word_image(images[i].img, core,
				images[i].word, images[i].state))
			return (false);
	}
	return (true);
} */
