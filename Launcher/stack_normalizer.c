/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_normalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:04:51 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/22 17:23:31 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Normalize and order the stack
void	stack_normalizer(t_stack *lst)
{
	t_stack	*marker;
	t_stack	*searcher;
	int	i;

	marker = lst;
	searcher = marker -> next;
	i = 0;
	while (marker != NULL)
	{
		while (searcher != NULL)
		{
			if (searcher -> content < marker -> content
			&& searcher -> order == -1) //modif la ****
				marker = searcher;
			searcher = searcher -> next;
		}
		marker -> order = i;
		i++;
		marker = lst;
		while (marker != NULL && marker -> order != -1) //modif la
			marker = marker -> next;
		if (marker) //modif la
			searcher = marker -> next;
	}
}

// Fill the allocated blocks with the argv given by the user
t_stack_library	*stack_filler(t_stack_library *stack,
	int pos, int argc, char **argv)
{
	t_stack	*writer;

	writer = stack->begin;
	while (pos < argc)
	{
		writer -> content = ft_atoi(argv[pos]);
		writer = writer -> next;
		pos++;
	}
	return (stack);
}
