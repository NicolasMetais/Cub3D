/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foes.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:27:47 by tvacher           #+#    #+#             */
/*   Updated: 2025/06/24 17:42:45 by nmetais          ###   ########.fr       */
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
	int				atk;
	int				range;
	int				damage;
	int				walk_speed;
	int				atk_speed;
	int				init_frame;
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
	int				screen_x;
	int				sprite_size;
	Sound			*death_sound;
	t_pos			*pos;
	t_img			*img_body;
	t_sprite		*walking;
	t_sprite		*attack;
	t_sprite		*anim_death;
	t_node_img		*activ_img;
	struct s_foes	*next;
}	t_foes;

//init
bool		init_foes(t_core *core);
bool		create_foes(t_core *core, int i, int x, int y);

//randomizer
void		randomized_spawns(t_core *core);

void		render_foes(t_core *core);
void		update_foes(t_core *core);
bool		is_enemy(t_core *core, float x, float y);
void		sort_enemies_by_distance(t_foes **head);
bool		seen_colision(t_core *core, int x, int y);
bool		all_dead(t_foes *foes);
void		revive_all(t_foes *foes);
void		handle_enemy_death(t_core *core, t_foes *enemy);
void		bump_enemy_enemy(t_core *core, t_foes *current);
void		bump_player_enemy(t_core *core);
int			foes_to_create(t_core *core);
void		sort_enemies_by_distance(t_foes **head);
t_sprite	*copy_sprite(t_core *core, t_sprite *src, int i);
bool		can_see_player(t_core *core, float ex, float ey);

//damage
void		damage_deal(t_core *core, t_foes *enemy);

//animations
void		anim_attack_foe(t_core *core);
void		anim_walk_foe(t_core *core);
void		anim_death_foe(t_core *core);

//init anim
void		init_foe_img(t_core *core, t_foes *node);
void		init_play_list(t_core *core, t_foes *node);
void		init_head_list(t_core *core, t_foes *node);
void		init_cybr_death_list(t_core *core, t_foes *node);
void		init_cybr_walking_list(t_core *core, t_foes *node);
void		init_cybr_attack_list(t_core *core, t_foes *node);
void		init_skul_death_list(t_core *core, t_foes *node);
void		init_skul_walking_list(t_core *core, t_foes *node);
void		init_skul_attack_list(t_core *core, t_foes *node);
void		init_sarg_death_list(t_core *core, t_foes *node);
void		init_sarg_walking_list(t_core *core, t_foes *node);
void		init_sarg_attack_list(t_core *core, t_foes *node);
void		init_poss_death_list(t_core *core, t_foes *node);
void		init_poss_walking_list(t_core *core, t_foes *node);
void		init_poss_attack_list(t_core *core, t_foes *node);
void		init_play_death_list(t_core *core, t_foes *node);
void		init_play_walking_list(t_core *core, t_foes *node);
void		init_play_attack_list(t_core *core, t_foes *node);
void		init_head_death_list(t_core *core, t_foes *node);
void		init_head_walking_list(t_core *core, t_foes *node);
void		init_head_attack_list(t_core *core, t_foes *node);

#endif
