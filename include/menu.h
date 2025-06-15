/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 02:10:48 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/15 18:27:40 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
# define MENU_H

# include <stdbool.h>


typedef struct s_img	t_img;
typedef struct s_sprite	t_sprite;

typedef struct s_menu_maps
{
	char	*name;
	bool	parsed;
}	t_menu_maps;

typedef struct s_slider {
	int		slider_min;
	int		slider_max;
	int		*x_var;
	int		*int_var;
	int		min_val;
	int		max_val;
	char	*label;
}	t_slider;

typedef struct s_menu_img
{
	t_img		*bg;
	t_img		*bg_clean;
	t_img		*slider_bar;
	t_img		*slider_small;
	t_img		*cursor;
	t_img		*loaded_map;
	t_img		*minimap;
	t_sprite	*skulls;
	t_slider	sliders[5];
}	t_menu_img;

//-----------------Menu-----------------
//setup the first menu
bool	start_menu(t_core *core);
//render the first menu
bool	render_menu(t_core *core);
//render the maps menu
bool	render_maps_menu(t_core *core);
//extract the names of the maps inside maps/ folder
bool	extract_maps_names(t_core *core);
//render options menu
bool	render_options_menu(t_core *core);
//skull animation rendering
void	skulls_render(t_core *core, const int *y);
//construct the slider image from 3 different ones
bool	slider_constructor(t_core *core, int width);
//handle the loaded map images next to starting menu
bool	loaded_map(t_img *bg, t_core *core);
//render the menu pause inside the game
bool	render_pause_menu(t_core *core);
//skull from pause menu
void	skulls_render_pause(t_core *core, const int *y);
//init pause bg with dark bg and freeze actual game img
bool	create_pause_bg(t_core *core);
//options menu in game
bool	render_pause_options(t_core *core);
//select a map and load everything acordingly
bool	map_selector(t_core *core);
//update the slider cursor img
void	update_slider_cursor(t_core *core, t_slider *slider, int y, t_img *bg);
//slider inits
bool	sliders_init(t_core *core, int width);
//update var on sliders
void	slider_updater(t_pos pos, int x, t_slider *slider);
//modular percent rendering with numbers for hud and options
bool	render_percent(t_core *core, char *percent,
			int render, t_img *bg);
//percent render for sliders %
bool	percent_option_rendering(t_core *core, t_slider	*slider, t_img *bg);
//percent render for slider in pause menu
bool	percent_pause_option_rendering(t_core *core,
			t_slider	*slider, t_img *bg);
//pixel image copy for sliders (prob a copy img duplicate tho)
void	slider_copy_pxl(t_img *slider_bar, t_img *tocopy, int px_start);
//ON/OFF cheat sliders
bool	small_slider_constructor(t_core *core);




#endif