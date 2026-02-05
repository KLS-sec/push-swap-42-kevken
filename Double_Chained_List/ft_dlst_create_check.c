/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_create_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:07:34 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/05 16:49:31 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_dlst_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
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

int	first_stack(t_stack_library *li)
{
	if (li == NULL)
		return (0);
	return (li->begin->content);
}

int	last_stack(t_stack_library *li)
{
	if (li == NULL)
		return (0);
	return (li->end->content);
}
