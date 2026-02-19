/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_push_clear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:37:20 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/19 11:55:30 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_library	*push_back_dlst(t_stack_library *li)
{
	t_stack	*element;

	element = ft_dlst_new();
	if (stack_length(li) == 0)
	{
		li = malloc(sizeof(t_stack_library));
		if (!li)
			return (NULL);
		li->length = 0;
		li->begin = element;
		li->end = element;
	}
	else
	{
		li->end->next = element;
		element->back = li->end;
		li->end = element;
	}
	li->length++;
	return (li);
}

t_stack_library	*push_front_dlst(t_stack_library *li)
{
	t_stack	*element;

	element = ft_dlst_new();
	if (stack_length(li) == 0)
	{
		li = malloc(sizeof(t_stack_library));
		if (!li)
			return (NULL);
		li->length = 0;
		li->begin = element;
		li->end = element;
	}	
	else
	{
		li->begin->back = element;
		element->next = li->begin;
		li->begin = element;
	}
	li->length++;
	return (li);
}

t_stack_library	*pop_front_dlst(t_stack_library *li)
{
	t_stack	*del;
	
	if (li == NULL)
		return (NULL);
	if (li->begin == li->end)
	{
		del = li->begin;
		free(del);
		free(li);
		li = NULL;
		return (NULL);
	}
	del = li->end;
	li->end = li->end->back;
	li->end->next = NULL;
	del->back = NULL;
	del->next = NULL;
	free (del);
	del = NULL;
	li->length--;
	return (li);
}

t_stack_library	*pop_back_dlst(t_stack_library *li)
{
	t_stack	*del;
	
	if (li == NULL)
		return (NULL);
	if (li->begin == li->end)
	{
		del = li->begin;
		free(del);
		free(li);
		li = NULL;
		return (NULL);
	}
	del = li->begin;
	li->begin = li->begin->next;
	li->begin->back = NULL;
	del->back = NULL;
	del->next = NULL;
	free (del);
	del = NULL;
	li->length--;
	return (li);
}

t_stack_library	*clear_dlst(t_stack_library *li)
{
	if (li == NULL)
		return (NULL);
	while (li)
		li = pop_front_dlst(li);
	return (NULL);
}
