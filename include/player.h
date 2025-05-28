/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:23:22 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/27 21:35:04 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <stdbool.h>

typedef struct s_pos		t_pos;
typedef struct s_weapon		t_weapon;

typedef struct s_player
{
	t_pos			*position;
	unsigned int	health;
	unsigned int	armor;
	unsigned int	ammo[4];
	int				current_weapon;
	t_weapon		weapon[9];

}	t_player;

bool	game_init(t_core *core);

#endif