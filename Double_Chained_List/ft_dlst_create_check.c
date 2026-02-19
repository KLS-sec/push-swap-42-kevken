/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_create_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:07:34 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/19 12:03:45 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_dlst_new(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = 0;
	new->order = -1;
	new->next = NULL;
	new->back = NULL;
	return (new);
}

int	stack_length(t_stack_library *li)
{
	if (li == NULL)
		return (0);
	return (li->length);
}

// Probablement inutile
int	first_stack(t_stack_library *li)
{
	if (li == NULL)
		return (0);
	return (li->begin->content);
}

// Probablement inutile
int	last_stack(t_stack_library *li)
{
	if (li == NULL)
		return (0);
	return (li->end->content);
}

t_stack_library	*full_list(t_stack_library *li, int argc, int pos)
{
	if (li == NULL)
		return (NULL);
	while (pos <= argc)
	{
		li = push_front_dlst(li);
	}
	return (li);
}
