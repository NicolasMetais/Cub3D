/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foes.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:27:47 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/17 17:27:49 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOES_H
# define FOES_H

# include <stdbool.h>

typedef struct s_pos	t_pos;
typedef struct s_img	t_img;

typedef struct s_foes {
	int				id;
	int				type;
	int				life;
	int				death;
	float			foe_x;
	float			foe_y;
	float			angle;
	float			foedelt_x;
	float			foedelt_y;
	float			speed;
	double			dx;
	double			dy;
	double			dist;
	double			angle_to_foe;
	double			rel_angle;
	t_pos			*pos;
	t_img			*img_foe;
	t_sprite		*walking;
	t_sprite		*atack;
	t_sprite		*anim_death;
	t_node_img		*activ_img;
	struct s_foes	*next;
}	t_foes;

//init
bool	init_foes(t_core *core);
bool	create_foes(t_core *core, int i, int x, int y);

//randomizer
void	randomized_spawns(t_core *core);

void	render_foes(t_core *core);
void	update_foes(t_core *core);
bool	is_enemy(t_core *core, float x, float y);
void	bump_player_enemy(t_core *core);
void	handle_enemy_death(t_core *core, t_foes *enemy);
void	anim_death_foe(t_core *core);

#endif
