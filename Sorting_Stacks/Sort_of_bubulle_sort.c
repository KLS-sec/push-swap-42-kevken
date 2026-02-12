/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_of_bubulle_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:06:23 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/11 11:46:28 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// Première idée : Inverser la position du "stop" et de départ, le 1er élément sera le début du comparateur et le dernier élément le stop
// IMPORTANT : Implémenter le print_state partout au lieu de mettre "1" ou "0" manuellement pour les opérations utilisées ici

void	sort_three(t_stack_library *stack_a)
{
	if (stack_a->begin->order > stack_a->begin->next->order
		&& stack_a->begin->next->order < stack_a->begin->next->next->order)
		rra(stack_a, 1);
	if (stack_a->begin->order < stack_a->begin->next->order)
	{
		ra(stack_a, 1);
		if (stack_a->begin->order > stack_a->begin->next->order)
			sa(stack_a, 1);
	}
	if (stack_a->begin->order > stack_a->begin->next->order)
	{
		sa(stack_a, 1);
		if (stack_a->begin->order < stack_a->begin->next->order)
			ra(stack_a, 1);
	}
}

void	sort_five_first(t_stack_library *stack_a, t_stack_library *stack_b)
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
			ra(stack_a, 1);
		if (cursor->end->order == 0 && cursor->end != cursor->begin)
			cursor->end = cursor->end->next;
		if (cursor->end->order == 0 && cursor->end != cursor->begin)
			rra(stack_a, 1);
	}
	stack_b = pb(stack_a, stack_b, 1);
	sort_five_second (stack_a, stack_b);
}
// Doute sur l'usage, dois-je envoyer un pointeur, un pointeur de pointeur,
// ou "return" une variable à la fin ? À checker
void	sort_five_second(t_stack_library *stack_a, t_stack_library *stack_b)
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
			ra(stack_a, 1);
		if (cursor->end->order == 1 && cursor->end != cursor->begin)
			cursor->end = cursor->end->next;
		if (cursor->end->order == 1 && cursor->end != cursor->begin)
			rra(stack_a, 1);
	}
	stack_b = pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
}
/* Here as reference, not usable like this
void	normal_bubble_sort(int *tab, int taille)
{
	int temp;
	int i;
	int j;

	i = 0;
	while (i < taille - 1)
	{
		j = taille - 1;
		while (j > i)
		{
			if (tab[j] < tab[j - 1])
			{
				temp = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = temp;
			}
			j--;
		}
		i++;
	}
}
 */
void	sort_of_bubbule_sort(t_stack_library *stack_a, t_stack_library *stack_b)
{
	int	i;

	i = 0;
	while (stack_a->begin != stack_a->end)
	{
		while (stack_a->begin->order != i)
		{
			if (stack_a->begin->content > stack_a->begin->next->content)
				sa(stack_a, 1);
			ra(stack_a, 1);
		}
		stack_b = pb(stack_a, stack_b, 1);
		i++;
	}
	while (stack_b != NULL)
		stack_a = pa(stack_a, stack_b, 1);
}
