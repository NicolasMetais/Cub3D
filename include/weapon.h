/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:33:30 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/08 19:18:39 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <stdbool.h>

typedef struct s_sprite		t_sprite;
typedef struct s_node_img	t_node_img;

typedef struct s_damage_range
{
	unsigned int	min;
	unsigned int	max;
}	t_damage_range;

typedef struct s_impact_node
{
	float					x;
	float					y;
	int						lifetime;
	int						frame;
	t_node_img				*activ_img;
	t_sprite				*sprite;
	struct timeval			timer;
	struct s_impact_node	*prev;
	struct s_impact_node	*next;
}	t_impact_node;

typedef struct s_impact
{
	float				x;
	float				y;
	int					screen_x;
	int					size;
	float				dist;
	float				angle;
	float				factor;
	double				fov_rad;
	t_impact_node		*impact_list;
}	t_impact;

typedef struct s_projectile_node
{
	float						x;
	float						y;
	float						dir_x;
	float						dir_y;
	float						speed;
	float						angle;
	t_sprite					*sprite;
	t_node_img					*activ_img;
	struct timeval				timer;
	struct s_projectile_node	*prev;
	struct s_projectile_node	*next;
}	t_projectile_node;

typedef struct s_projectiles
{
	float				dx;
	float				dy;
	float				speed;
	float				angle;
	double				fov_rad;
	t_projectile_node	*proj_list;
}	t_projectiles;

typedef struct s_weapon
{
	char			*name;
	unsigned int	ammo_type;
	t_damage_range	damage;
	bool			owned;
	t_img			*normal;
	t_node_img		*loop_loaded;
	t_sprite		*anim;
	t_sprite		*fire;
	bool			lock;
}	t_weapon;

bool	weapons_init(t_weapon weapon[9], t_core *core);
bool	weapons_init_five(t_weapon weapon[9], t_core *core);
bool	render_weapon(t_core *core);
void	weapon_fired(t_core *core);
void	setup_animation_exceptions(t_weapon weapon[9]);
bool	rebuild_fire_anim(t_node_img **anim_list,
			t_sprite *fire_list, t_pos offset, t_core *core);
void	impacts(t_core *core);
bool	shoot_shotgun(t_core *core);
bool	shoot_pistol(t_core *core, float angle);
bool	update_weapons_animation(t_sprite *sprite);
bool	update_loaded_animation(t_weapon *weapon, t_sprite *sprite,
			bool hold, t_core *core);
void	setup_animation_exceptions(t_weapon weapon[9]);
void	fire_charged_weapons(t_core *core);
bool	shoot_projectile(t_core *core, float angle);
bool	new_proj(t_core *core, float x, float y, float angle);
void	render_projectiles(t_core *core);
bool	update_projectiles(t_core *core);
bool	new_impact(t_core *core, float x, float y);
bool	iswall(t_pos pos, t_core *core);
int		is_colliding(t_pos pos, t_core *core);
bool	setup_proj_impacts(t_core *core, t_pos pos, t_projectile_node *proj);






















#endif