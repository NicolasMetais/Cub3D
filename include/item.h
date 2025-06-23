/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <tvacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 12:01:44 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/23 21:29:50 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITEM_H
# define ITEM_H

# include "cub3d.h"

typedef struct s_img		t_img;
typedef struct s_sprite		t_sprite;
typedef struct s_core		t_core;
typedef struct s_pos		t_pos;
typedef struct s_foes		t_foes;
typedef struct s_node_img	t_node_img;

typedef enum s_item_type
{
	ITEM,
	WEAPON
}	t_item_type;

typedef enum s_modifier_type
{
	LIFE_S,
	LIFE_M,
	LIFE_L,
	ARMO_S,
	ARMO_M,
	ARMO_L,
	BULL_S,
	BULL_L,
	SHEL_S,
	SHEL_L,
	ROCK_S,
	ROCK_L,
	CELL_S,
	CELL_L,
	W_SHOT,
	W_MINI,
	W_CHAI,
	W_ROCK,
	W_PLAS,
	W_BFG
}	t_modifier_type;

typedef enum s_item_state
{
	DROP,
	TAKEN,
}	t_item_state;

typedef struct s_item
{
	char				*notif;
	t_pos				*pos;
	double				item_x;
	double				item_y;
	double				dx;
	double				dy;
	double				dist;
	double				angle_to_item;
	double				rel_angle;
	t_sprite			*anim;
	t_node_img			*activ_img;
	t_img				*pic;
	unsigned int		id;
	t_item_type			type;
	t_modifier_type		mod_type;
	t_item_state		state;
}	t_item;

typedef struct s_items
{
	t_item			*item;
	int				screen_x;
	int				sprite_size;
	struct s_items	*next;
}	t_items;

//notifications from pickup init
bool	notif_init(t_core *core);
//render notifications
void	render_notifs(t_core *core);
//put a new notif in the game
bool	new_notifs(t_core *core, t_item item);
//init all items with imgs and sprites
bool	item_init(t_core *core);

//manage drop and render
void	drop_object(t_core *core, t_foes *enemy);
void	render_items(t_core *core);
void	update_items_player(t_core *core);
void	handle_items5(t_core *core, t_item *item);
void	drop_object(t_core *core, t_foes *enemy);
bool	create_item_chain(t_core *core, t_foes *enemy, int random);
void	sort_items_by_distance(t_items **head);
bool	is_animation(t_item *item);
void	anim_items(t_core *core);

#endif