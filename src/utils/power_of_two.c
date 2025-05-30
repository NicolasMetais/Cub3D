/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_of_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:50:25 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/05 17:50:50 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	power_of_two(int n)
{
	int	p;

	p = 1;
	while (p < n)
		p *= 2;
	return (p);
}
