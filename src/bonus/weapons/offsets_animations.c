/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offsets_animations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:51:38 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/05 14:00:47 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_animation_exceptions_bis(t_weapon weapon[9])
{
	weapon[6].fire->img_list->has_offset = true;
	weapon[6].fire->img_list->offset_x = 0;
	weapon[6].fire->img_list->offset_y = 140;
	weapon[6].fire->img_list->next->has_offset = true;
	weapon[6].fire->img_list->next->offset_x = 0;
	weapon[6].fire->img_list->next->offset_y = 140;
	weapon[7].fire->img_list->has_offset = true;
	weapon[7].fire->img_list->offset_x = 135;
	weapon[7].fire->img_list->offset_y = 145;
	weapon[7].fire->img_list->next->has_offset = true;
	weapon[7].fire->img_list->next->offset_x = 48;
	weapon[7].fire->img_list->next->offset_y = 82;
}

void	setup_animation_exceptions(t_weapon weapon[9])
{
	weapon[3].fire->img_list->next->has_offset = true;
	weapon[3].fire->img_list->next->offset_x = 60;
	weapon[3].fire->img_list->next->offset_y = 115;
	weapon[4].fire->img_list->next->has_offset = true;
	weapon[4].fire->img_list->next->offset_x = 42;
	weapon[4].fire->img_list->next->offset_y = 140;
	weapon[4].fire->img_list->next->next->has_offset = true;
	weapon[4].fire->img_list->next->next->offset_x = 42;
	weapon[4].fire->img_list->next->next->offset_y = 140;
	weapon[5].fire->img_list->has_offset = true;
	weapon[5].fire->img_list->offset_x = 45;
	weapon[5].fire->img_list->offset_y = 150;
	weapon[5].fire->img_list->next->has_offset = true;
	weapon[5].fire->img_list->next->offset_x = 41;
	weapon[5].fire->img_list->next->offset_y = 125;
	weapon[5].fire->img_list->next->next->has_offset = true;
	weapon[5].fire->img_list->next->next->offset_x = 14;
	weapon[5].fire->img_list->next->next->offset_y = 105;
	weapon[5].fire->img_list->next->next->next->has_offset = true;
	weapon[5].fire->img_list->next->next->next->offset_x = 0;
	weapon[5].fire->img_list->next->next->next->offset_y = 68;
	setup_animation_exceptions_bis(weapon);
}
