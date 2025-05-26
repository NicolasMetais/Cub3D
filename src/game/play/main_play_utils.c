/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_play_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvacher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:33:47 by tvacher           #+#    #+#             */
/*   Updated: 2025/05/26 18:33:59 by tvacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    rays_updates(t_core *core)
{
    core->tmp_rc->r++;
    core->tmp_rc->ra += RAD;
    if (core->tmp_rc->ra < 0)
        core->tmp_rc->ra += 2 * PI;
    if (core->tmp_rc->ra > 2 * PI)
        core->tmp_rc->ra -= 2 * PI;
    core->tmp_rc->ca = core->tmp_rc->pl_angle - core->tmp_rc->ra;
    if (core->tmp_rc->ca < 0)
        core->tmp_rc->ca += 2 * PI;
    if (core->tmp_rc->ca > 2 * PI)
        core->tmp_rc->ca -= 2 * PI;
    core->tmp_rc->dist3[core->tmp_rc->r] = core->tmp_rc->dist3[core->tmp_rc->r] * cos(core->tmp_rc->ca);    
}
