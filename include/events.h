/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 02:14:30 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/21 16:18:37 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

typedef enum e_move {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	S_RIGHT,
	S_LEFT
}	t_move;

typedef struct s_moves {
	double	straf_x;
	double	straf_y;
	double	next_x;
	double	next_y;
	double	margin_x;
	double	margin_y;
	int		map_x;
	int		map_y;
}	t_moves;

//----------------Keypress Events--------------
//handler menu maps up and down keyboard inputs
void			maps_menu_keypress(int key, t_core *core);
//main keypress handler with state conditioning
int				handle_keypress(int key, void *param);
//handler for the starting menu
void			pause_menu_keypress(int key, t_core *core);
//handler for the option menu
void			pause_option_keypress(int key, t_core *core);
//handler to detect key-realse for smooth movements in game
int				handle_keyrelease(int key, void *param);
//main keypress handler with state conditioning
int				handle_keypress(int key, void *param);
//manage all player movements
void			move_player(t_core *core, t_move move, double delta_time);
//Right movement handler
void			handle_right(t_core *core, double move_dist);
//left movement handler
void			handle_left(t_core *core, double move_dist);
//mouse handler for camera deplacements
void			mouse_scroll_game(t_core *core, int x, int y);
//struct movement init
bool			moves_init(t_core *core);
//colision detection
bool			is_map_colision(t_core *core, int x, int y);

//----------------Mouse Event------------------
//handler for starting menu to click with the mouse on the menu
int				mouse_menu_click(int button, int x, int y, t_core *core);
//handler for mouse over on sliders and ingame camera
int				mouse_menu_hover(int x, int y, void *param);
//handler for mouse release for loaded weapons like chainguns
int				mouse_menu_release(int button, int x, int y, t_core *core);
//handler for options menu to click with the mouse on the menu
void			options_menu_hover(int x, int y, t_core *core);
//main mouse click handle with state conditioning
void			mouse_click_game(t_core *core, int button);
//handler for mouse over on sliders in game options
void			pause_options_hover(int x, int y, t_core *core);
//handler on pause menu
void			pause_hover(int x, int y, t_core *core);
//mouse_click on pause_menu
void			mouse_click_pause_menu(t_core *core);
//Detect clic on the cross
int				cross_handler(void *param);

#endif