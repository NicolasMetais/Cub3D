/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 02:35:31 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/03 04:12:45 by nmetais          ###   ########.fr       */
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
bool	load_word_image(t_img **img, t_core *core, char *word, t_font_size size)
{
	*img = gc_malloc(&core->gc, sizeof(t_img), STRUCT, "writing");
	if (!*img)
		return (false);
	build_words(core, img, size, word);
	if (!(*img)->img)
		return (ft_putendl_fd("Error \n word images corrupted", 2), false);
	return (true);
}

bool	store_img(char **line, t_core *core)
{
	(void)core;
	if (line[1] && (!ft_strncmp(line[1], "word_creator:", 13)))
	{
		printf("word : %s\n", line[0]);
	}
	else
		printf("texture %s\n", line[0]);
	return (true);
}

//LOAD HORRIBLE D'IMAGE POUR PASSER LA NORME JE VAIS FAIRE UNE HASHMAP
bool	extract_img_data(t_core *core)
{
	int		i;
	char	**data;
	char	**tmp;

	i = -1;
	data = NULL;
	if (!file_extract("config.txt", &data))
		return (false);
	while (data[++i])
	{
		if (data[i][0] == '#' || !data[i][0])
			continue ;
		tmp = ft_split(data[i], '\t');
		if (!tmp)
			return (false); //FAUT FREE MAIS G LA FLEMME DE FOU
		store_img(tmp, core);
		ft_free_tab(tmp);
	}
	ft_free_tab(data);
	return (true);
}

bool	init_menu_img(t_core *core)
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
	{&core->menu_img->play, "Kill", REGULAR},
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
}
