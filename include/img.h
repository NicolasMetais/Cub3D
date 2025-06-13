/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 01:29:49 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/13 02:13:39 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

# include <stdbool.h>

typedef enum s_font_size	t_font_size;

typedef struct s_tmp_imgdata
{
	char	*img_data;
	int		bpp;
	int		size;
	int		endian;
	int		line_len;
	void	*img;
}	t_tmp_imgdata;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_node_img
{
	t_img				*image;
	int					offset_x;
	int					offset_y;
	bool				has_offset;
	struct s_node_img	*next;
}	t_node_img;

//fired only used for weapons
typedef struct s_sprite
{
	int				nb;
	int				timer;
	int				speed;
	struct timeval	update;
	bool			activ;
	bool			started;
	t_node_img		*head;
	t_node_img		*img_list;
}	t_sprite;

typedef struct s_word_loader
{
	t_img		**img;
	char		*word;
	t_font_size	state;
}	t_word_loader;

typedef struct s_img_loader
{
	t_img	**img;
	char	*path;
}	t_img_loader;

//------------------IMG HANDLE---------------------------------
//load an image and setup datas
bool			load_image(t_img **img, char *path, t_core *core, char *scale);
//load a word image from sprite sheed from a string in the given size
bool			load_word_image(t_img **img, t_core *core,
					char *word, char *state);
//fill an image with green for transparency purpose
void			fill_img_in_green(t_img *img);
//extract all datas from config.cfg launch the load and the hashmap stuff
bool			extract_img_data(t_core *core);
//load and construct linked list of images for animations purpose
bool			load_assets(t_core *core, char **data);

#endif