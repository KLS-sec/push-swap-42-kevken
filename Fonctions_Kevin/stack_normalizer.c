/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_normalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:04:51 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/19 13:16:28 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// "int total" n'est pas utilisé ici, donc je le retire et on le rajoutera de nouveau si besoin
void stack_normalizer(t_stack *lst)
{
	t_stack *marker;
	t_stack *searcher;
	int i;

	marker = lst;
	searcher = marker -> next;
	i = 0;
	while(marker != NULL)
	{
		while(searcher != NULL)
		{
			if (searcher -> content < marker -> content)
				marker = searcher;
			searcher = searcher -> next;
		}
		marker -> order = i;
		i++;
		marker = marker -> next; // Remplacé "marker = lst" ?? Why ? La ligne suivante aussi je la comprends pas (Obviously message de Kenny s'il y avait un doute :P)
		while(marker -> next != NULL && marker -> order != -1)
			marker = marker -> next;
		searcher = marker -> next;
	}
}

t_stack_library *stack_filler(t_stack_library *stack, int pos, int argc, char **argv)
{
	t_stack *writer;

	writer = stack->begin;
	while(pos < argc)
	{
	writer -> content = ft_atoi(argv[pos]);
		writer = writer -> next;
	pos++;
	}
	return (stack);
}
//input i est le point depart de lecture