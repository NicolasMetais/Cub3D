/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 01:23:05 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/21 16:18:48 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_H
# define HUD_H

# include <stdbool.h>

typedef struct s_img	t_img;
typedef struct s_sprite	t_sprite;

typedef struct s_hud_img
{
	t_img		*clean_hud;
	t_img		*hud;
	t_img		*pause_buffer;
	t_img		*clean_pause_buffer;
	t_sprite	*neutral;
	t_sprite	*tired;
	t_sprite	*hurt;
	t_sprite	*bloody;
	t_sprite	*critical;
	t_img		*ammo1;
	t_img		*ammo2;
	t_img		*ammo3;
	t_img		*ammo4;
	t_img		*life;
	t_img		*armor;
	t_img		*ammo;
	bool		hud_render;
	bool		ammo1_render;
	bool		ammo2_render;
	bool		ammo3_render;
	bool		ammo4_render;
	bool		health_render;
	bool		armor_render;
	bool		new_weapon_render;
}	t_hud_img;

//---------------------HUD---------------------
//main rendering hud
bool	render_hud(t_core *core);
//render the head animation when needed
void	render_head(t_core *core);
//render the number and update then when needed
bool	render_numbers(t_core *core, t_img	*bg);
//light up numbers when the weapons is usable
bool	render_weapon_menu(t_core *core);
//render the ammo numbers and update then when needed
bool	render_ammo(t_core *core, t_img	*bg);
//init all head images
bool	head_init(t_core *core);
//render all red numbers with percents
bool	hud_render_percent(t_img *buffer, t_core *core,
			char *percent, int render);
bool	render_armor_red_num(t_core *core, t_img *bg, char *num);
bool	render_health_red_num(t_core *core, t_img *bg, char *num);
//render number without percents for ammos
void	hud_render_number(t_img *buffer, t_core *core,
			char *percent, int render);
bool	render_ammo_red_num(t_core *core, t_img *bg);

#endif