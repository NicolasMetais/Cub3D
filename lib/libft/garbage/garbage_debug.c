/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 05:18:05 by nmetais           #+#    #+#             */
/*   Updated: 2025/04/24 21:36:55 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	print_char(t_gc *head)
{
	char	**tab_str;
	int		i;

	i = -1;
	if (head->type == CHAR)
		printf("%c\n", *(char *)head->data);
	else if (head->type == STRING)
		printf("%s\n", (char *)head->data);
	else if (head->type == TAB_STRING)
	{
		tab_str = (char **)head->data;
		while (tab_str[++i])
			printf("%s\n", tab_str[i]);
	}
}

void	print_int(t_gc *head)
{
	t_int_array	*tab_int;
	size_t		i;

	i = -1;
	if (head->type == INT)
		printf("%d\n", *(int *)head->data);
	else if (head->type == TAB_INT)
	{
		tab_int = (t_int_array *)head->data;
		if (tab_int->data)
			printf("[Array]\n");
		while (++i < tab_int->size)
			printf("i : %zu | data : %d\n", i, tab_int->data[i]);
	}
}

void	print_float(t_gc *head)
{
	t_float_array	*tab_float;
	size_t			i;

	i = -1;
	if (head->type == FLOAT)
		printf("%f\n", *(float *)head->data);
	else if (head->type == TAB_FLOAT)
	{
		tab_float = (t_float_array *)head->data;
		if (tab_float->data)
			printf("[Array]\n");
		while (++i < tab_float->size)
			printf("i : %zu | data : %f\n", i, tab_float->data[i]);
	}
}

void	print_allocated_vars(t_gc_controller *gc_control, char *tag)
{
	t_gc	*tmp;
	int		i;

	i = -1;
	if (!gc_control->start)
	{
		printf("Garbage empty\n");
		return ;
	}
	tmp = gc_control->start;
	while (++i < gc_control->alloc_nb)
	{
		if (tmp != NULL && (!tag || ft_strcmp(tag, tmp->tag) == 0))
		{
			printf("-------- ALLOC [%s] --------\n\n", tmp->tag);
			print_char(tmp);
			print_int(tmp);
			print_float(tmp);
			if (tmp->type == STRUCT)
				printf("STRUCT %s\n", tmp->tag);
			printf("\n---------------------------------\n");
		}
		tmp = tmp->next;
	}
}
