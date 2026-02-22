/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_of_bubulle_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:06:23 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/22 17:17:47 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Sort 3 numbers
void	sort_three(t_stack_library *stack_a, t_bench *bench)
{
	if (stack_a->begin->order > stack_a->begin->next->order
		&& stack_a->begin->next->order < stack_a->begin->next->next->order)
		rra(stack_a, 1, bench);
	if (stack_a->begin->order < stack_a->begin->next->order)
	{
		ra(stack_a, 1, bench);
		if (stack_a->begin->order > stack_a->begin->next->order)
			sa(stack_a, 1, bench);
	}
	if (stack_a->begin->order > stack_a->begin->next->order)
	{
		sa(stack_a, 1, bench);
		if (stack_a->begin->order < stack_a->begin->next->order)
			ra(stack_a, 1, bench);
	}
}

// First part of code sorting 5 numbers
void	sort_five_first(t_stack_library *stack_a, t_stack_library *stack_b,
						t_bench *bench)
{
	t_stack_library	*cursor;

	cursor = stack_a;
	while (cursor->begin->order != 0 || cursor->end->order != 0)
	{
		cursor->begin = cursor->begin->next;
		cursor->end = cursor->end->back;
	}
	while (cursor->begin != stack_a->begin || cursor->end != stack_a->end)
	{
		if (cursor->begin->order == 0)
			cursor->begin = cursor->begin->back;
		if (cursor->begin->order == 0)
			ra(stack_a, 1, bench);
		if (cursor->end->order == 0 && cursor->end != cursor->begin)
			cursor->end = cursor->end->next;
		if (cursor->end->order == 0 && cursor->end != cursor->begin)
			rra(stack_a, 1, bench);
	}
	pb(&stack_a, &stack_b, 1, bench);
	sort_five_second(stack_a, stack_b, bench);
}

/* Doute sur l'usage, dois-je envoyer un pointeur, un pointeur de pointeur,
ou "return" une variable à la fin ? À checker */

// Second part of code sorting 5 numbers
void	sort_five_second(t_stack_library *stack_a,
							t_stack_library *stack_b, t_bench *bench)
{
	t_stack_library	*cursor;

	cursor = stack_a;
	while (cursor->begin->order != 1 || cursor->end->order != 1)
	{
		cursor->begin = cursor->begin->next;
		cursor->end = cursor->end->back;
	}
	while (cursor->begin != stack_a->begin || cursor->end != stack_a->end)
	{
		if (cursor->begin->order == 1)
			cursor->begin = cursor->begin->back;
		if (cursor->begin->order == 1)
			ra(stack_a, 1, bench);
		if (cursor->end->order == 1 && cursor->end != cursor->begin)
			cursor->end = cursor->end->next;
		if (cursor->end->order == 1 && cursor->end != cursor->begin)
			rra(stack_a, 1, bench);
	}
	pb(&stack_a, &stack_b, 1, bench);
	sort_three(stack_a, bench);
	pa(&stack_a, &stack_b, 1, bench);
	pa(&stack_a, &stack_b, 1, bench);
}

// Simple algorithm of sorting, sort as many given
void	bubble_sort(t_stack_library *stack_a, t_stack_library *stack_b,
			t_bench *bench)
{
	int	i;

	i = 1;
	while (stack_a->begin != stack_a->end)
	{
		while (stack_a->begin->order != i)
		{
			if (stack_a->begin->content > stack_a->begin->next->content)
				sa(stack_a, 1, bench);
			ra(stack_a, 1, bench);
		}
		pb(&stack_a, &stack_b, 1, bench); // Mettre une condition pour ne pas le declencher inutilement
		i++;
	}
	while (stack_b != NULL)
		pa(&stack_a, &stack_b, 1, bench);
}
