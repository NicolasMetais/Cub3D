/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:48:56 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/22 20:00:52 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_free_tab(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
	{
		if (str[i])
			free(str[i]);
	}
	if (str)
		free(str);
}
