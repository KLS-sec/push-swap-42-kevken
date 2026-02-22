/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_create_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:07:34 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/22 16:11:06 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Create a t_stack block for our stack (a or b)
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

// Measure the size of the library of our stack
int	stack_length(t_stack_library *li)
{
	if (li == NULL)
		return (0);
	return (li->length);
}

// Create the stack depending on argc and type of arguments
t_stack_library	*full_list(t_stack_library *li, int argc, int pos)
{
	if (li == NULL)
		return (NULL);
	while (pos <= argc)
	{
		li = push_front_dlst(li, 0);
	}
	return (li);
}
