/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:46:40 by nmetais           #+#    #+#             */
/*   Updated: 2025/05/26 13:14:34 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	free_tabs(t_gc *temp)
{
	int				i;
	char			**tab_s;
	t_int_array		*tab_i;
	t_float_array	*tab_f;

	if (temp->type == TAB_INT)
	{
		tab_i = temp->data;
		free(tab_i->data);
	}
	if (temp->type == TAB_FLOAT)
	{
		tab_f = temp->data;
		free(tab_f->data);
	}
	if (temp->type == TAB_STRING)
	{
		tab_s = temp->data;
		i = -1;
		while (tab_s[++i])
		{
			if (tab_s[i])
				free(tab_s[i]);
		}
	}
}

void	free_nodes(t_gc *temp, char *tag)
{
	if (temp->data)
	{
		free(temp->data);
		temp->data = NULL;
		temp->tag = "NULL";
		temp->type = FREED;
	}
	if (!tag)
		free(temp);
}

void	free_gc(t_gc_controller *gc_control, char *tag)
{
	t_gc			*temp;
	t_gc			*gc;
	int				i;

	if (!gc_control)
		return ;
	gc = gc_control->start;
	i = -1;
	while (++i < gc_control->alloc_nb)
	{
		temp = gc;
		gc = gc->next;
		if (!tag || !(ft_strcmp(temp->tag, tag)))
		{
			free_tabs(temp);
			free_nodes(temp, tag);
		}
	}
	if (!tag)
		free(gc_control);
}
