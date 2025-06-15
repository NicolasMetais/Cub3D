/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:23:22 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/14 16:29:54 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <stdbool.h>

# define PLAYER_SPEED 30


typedef struct s_pos		t_pos;
typedef struct s_weapon		t_weapon;

typedef struct s_player
{
	t_pos			*position;
	unsigned int	health;
	unsigned int	armor;
	unsigned int	ammo[4];
	int				curr_wpn;
	t_weapon		weapon[9];
	bool			key_up;
	bool			key_down;
	bool			key_left;
	bool			key_right;
	bool			firing;
	bool			straf_right;
	bool			straf_left;
	int				speed;
	double			bobbing_speed;
	double			delta_time;
	double			last_time;
	double			bobbing_time;
	double			bob_x;
	double			bob_y;
}	t_player;

bool	game_init(t_core *core);

//player_move
void	game_keypress(t_core *core, double delta_time);
void	on_keyrelease_game(int key, t_core *core);
void	on_keypress_game(int key, t_core *core);




#endif