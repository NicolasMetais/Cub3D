/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 12:01:44 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/21 16:14:50 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITEM_H
# define ITEM_H

# include "cub3d.h"

typedef struct s_img	t_img;
typedef struct s_sprite	t_sprite;
typedef struct s_core	t_core;

typedef enum s_item_type
{
	ITEM,
	WEAPON
}	t_item_type;

typedef struct s_item
{
	char			*notif;
	t_sprite		*anim;
	t_img			*pic;
	unsigned int	id;
	t_item_type		type;
}	t_item;

//notifications from pickup init
bool	notif_init(t_core *core);
//render notifications
void	render_notifs(t_core *core);
//put a new notif in the game
bool	new_notifs(t_core *core, t_item item);
//init all items with imgs and sprites
bool	item_init(t_core *core);

#endif