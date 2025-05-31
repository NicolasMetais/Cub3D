/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:33:30 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/31 17:35:33 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <stdbool.h>

typedef struct s_sprite t_sprite;

typedef struct s_damage_range
{
	unsigned int	min;
	unsigned int	max;
}	t_damage_range;

typedef struct s_weapon
{
	char			*name;
	unsigned int	ammo_type;
	t_damage_range	damage;
	float			fire_rate;
	float			cooldown;
	bool			owned;
	t_img			*normal;
	t_sprite		*anim;
	t_sprite		*fire;
	bool			lock;
}	t_weapon;

void	weapons_init(t_weapon weapon[9], t_core *core);
bool	render_weapon(t_core *core);


#endif