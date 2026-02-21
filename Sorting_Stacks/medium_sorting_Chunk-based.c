/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sorting_Chunk-based.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-scor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:00:01 by kle-scor          #+#    #+#             */
/*   Updated: 2026/02/20 16:02:53 by kle-scor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//roller_a and roller_b in Medium_sorting_support.c
//Undefined behavior if any abnormal input passed the securities

//Square root (rounded down) of n
int	square_root(int n)
{
	int	i;

	i = 1;
	while (((i + 1) * (i + 1)) <= n)
		i++;
	return (i);
}

//Search for values under chunk return the count needed to reach it
int	medium_search(t_stack_library *lib_a, int chunk)
{
	t_stack	*head;
	t_stack	*tail;
	int		i;

	head = lib_a -> begin -> next;
	tail = lib_a -> end;
	i = 1;
	if (lib_a -> begin -> order <= chunk)
		return (0);
	while (head -> order > chunk && tail -> order > chunk)
	{
		head = head -> next;
		tail = tail -> back;
		i++;
	}
	if (tail -> order <= chunk)
		i *= -1;
	return (i);
}

//Search the value to sent back to a return the count needed to reach it
int	medium_return(t_stack_library *lib_b, int j)
{
	t_stack	*head;
	t_stack	*tail;
	int		i;

	head = lib_b -> begin -> next;
	tail = lib_b -> end;
	i = 1;
	if (lib_b -> begin -> order == j)
		return (0);
	while (head -> order < j && tail -> order < j && i <= lib_b -> length)
	{
		head = head -> next;
		tail = tail -> back;
		i++;
	}
	if (tail -> order == j)
		i *= -1;
	return (i);
}

//Small efficiency enhancer that reverse top 2 struct of b if advantageous
//int *j to spare a line in medium_algorithm
void	pre_organiser(t_stack_library *lib_b, int print_state,
	t_bench *bench, int *j)
{
	if (lib_b -> order < lib_b -> next -> order && lib_b -> length > 1)
		sb(lib_b, print_state, *bench);
	j++;
}

void	medium_algorithm(t_stack_library *lib_a, t_stack_library *lib_b,
	t_bench *bench, int print_state)
{
	int	chunk;
	int	i;
	int	j;

	chunk = square_root(lib_a -> length);
	i = 1;
	j = 0;
	while (lib_a -> begin != NULL)
	{
		while (j < (chunk / i) && lib_a -> begin != NULL)
		{
			roller_a(medium_search(lib_a, chunk), lib_a, bench);
			lib_b -> begin = pb(lib_a, lib_b, print_state, bench);
			pre_organiser (lib_b, print_state, bench, j);
		}
		chunk = ++i * chunk;
		j = 0;
	}
	j = lib_b -> length - 1;
	while (j >= 0 && lib_b -> begin != NULL)
	{
		roller_b(medium_return (lib_b, j--), lib_b, bench);
		lib_a -> begin = pa(lib_a, lib_b, print_state, bench);
	}
}
