/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:32:21 by nmetais           #+#    #+#             */
/*   Updated: 2025/06/24 16:32:22 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>

static bool	check_overflow(const char *str, int i, int sign, long *res)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		*res = (*res * 10) + (str[i] - '0');
		if ((sign == 1 && *res > INT_MAX)
			|| (sign == -1 && - *res < INT_MIN))
			return (false);
		i++;
	}
	if (str[i] != '\0')
		return (false);
	return (true);
}

bool	safe_atoi(const char *str, int *out)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (!str || !str[0])
		return (false);
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (false);
	if (!check_overflow(str, i, sign, &res))
		return (false);
	*out = (int)(res * sign);
	return (true);
}
