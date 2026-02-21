/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sorting_radix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-scor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:38:27 by kle-scor          #+#    #+#             */
/*   Updated: 2026/02/21 14:38:32 by kle-scor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Undefined behavior if any abnormal element pass the securities

//Check disorder level - if disorder check == 0 kill radix
int	disorder_check(t_stack_library *lib_a)
{
	t_stack	*base;
	t_stack	*nav;

	base = lib_a -> begin;
	nav = base -> next;
	while (base -> next != NULL)
	{
		if (base -> content > nav -> content)
			return (1);
		base = base -> next;
		nav = nav -> next;
	}
	return (0);
}

//Search the closest value to sent and return it's location in the stack
int	cplx_search(t_stack_library *lib_a, int n)
{
	t_stack	*head;
	t_stack	*tail;
	int		i;

	i = 1;
	if ((head -> content & (1 << n)) == 0)
		return (0);
	head = lib_a -> begin -> next;
	tail = lib_a -> end;
	while ((head -> content & (1 << n)) != 0
		&& (tail -> content & (1 << n)) != 0 && head != NULL)
	{
		head = head -> next;
		tail = tail -> back;
		i++;
	}
	if ((tail -> content & (1 << n)) == 0 && i < lib_a -> length)
		i *= -1;
	return (i);
}

//Radix main body
//Check the binary data to sort the stacks
//Roller_a is in Medium_sorting_support.c
int	radix(t_stack_library *lib_a, t_stack_library *lib_b, t_bench *bench,
	int print_state)
{
	int	n;
	int	i;

	n = 0;
	i = cplx_search(lib_a, n);
	while (disorder_check(lib_a) > 0 && n < 32)
	{
		while (i < lib_a -> length)
		{
			i = cplx_search(lib_a, n);
			if (i < lib_a -> length)
				roller_a(i, lib_a, bench);
			if (i < lib_a -> length)
				lib_b -> begin = pb(stack_a, stack_b, print_state, bench);
		}
		while (lib_b -> begin != NULL)
			lib_a -> begin = pa(stack_a, stack_b, print_state, bench);
		n++;
	}
	return (0);
}
