/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:38:17 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/28 15:44:09 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	render_head(t_core *core)
{
	t_img	*head;

	head = hashmap_get(&core->hashmap, "head");
	transparency(core->hud_img->hud, head, 740, 7);
	return (true);
}
