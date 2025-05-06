/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 09:53:42 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/22 14:47:01 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
//COLLECTION DE TOUT LES MALLOC ET FREE SI BESOIN

t_gc	*new_gc(void *data, int type, char *tag)
{
	t_gc			*lst;
	t_int_array		*tab_int;
	t_float_array	*tab_float;

	lst = malloc(sizeof(t_gc));
	if (!lst)
		return (NULL);
	lst->type = type;
	lst->data = data;
	if (!tag)
		lst->tag = "empty";
	else
		lst->tag = tag;
	if (type == TAB_INT)
		tab_int = (t_int_array *)data;
	if (type == TAB_FLOAT)
		tab_float = (t_float_array *)data;
	lst->next = NULL;
	return (lst);
}

t_int_array	*alloc_tab_int(unsigned int size, t_int_array **tab_int)
{
	*tab_int = malloc(sizeof(t_int_array));
	if (!*tab_int)
		return (NULL);
	(*tab_int)->data = malloc(size);
	if (!(*tab_int)->data)
		return (free(*tab_int), NULL);
	(*tab_int)->size = size / sizeof(int);
	return (*tab_int);
}

//FAUT REFACTOR FORT
void	*choose_alloc(int type, unsigned int size)
{
	void			*data;
	t_int_array		*tab_int;
	t_float_array	*tab_float;

	if (type == TAB_INT)
		return (alloc_tab_int(size, &tab_int));
	else if (type == TAB_FLOAT)
	{
		tab_float = malloc(sizeof(t_float_array));
		if (!tab_float)
			return (NULL);
		tab_float->data = malloc(size);
		if (!tab_float->data)
			return (free(tab_float), NULL);
		tab_float->size = size / sizeof(float);
		return (tab_float);
	}
	data = malloc(size);
	if (!data)
		return (NULL);
	return (data);
}

void	*gc_malloc(t_gc_controller **gc_control, unsigned int size
			, int type, char *tag)
{
	void	*data;
	t_gc	*new;

	data = choose_alloc(type, size);
	if (!data)
		return (NULL);
	new = new_gc(data, type, tag);
	if (!new)
		return (free(data), NULL);
	if ((*gc_control)->start == NULL)
		(*gc_control)->start = new;
	else
	{
		new->next = (*gc_control)->start;
		(*gc_control)->start = new;
	}
	(*gc_control)->alloc_nb++;
	return (data);
}

bool	add_to_gc(t_gc_controller **gc, void *data, int type, char *tag)
{
	t_gc	*new;

	new = new_gc(data, type, tag);
	if (!new)
		return (free(data), false);
	if ((*gc)->start == NULL)
		(*gc)->start = new;
	else
	{
		new->next = (*gc)->start;
		(*gc)->start = new;
	}
	(*gc)->alloc_nb++;
	return (true);
}
