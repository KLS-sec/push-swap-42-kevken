/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Medium_sorting_support.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-scor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:14:20 by kle-scor          #+#    #+#             */
/*   Updated: 2026/02/20 16:14:26 by kle-scor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Take medium_search outputput as i
//Use it to move the target on the top of the stack
void	roller_a(int i, t_stack_library *lib_a, t_bench *bench)
{
	while (i < 0)
	{
		rra(lib_a, 1, bench);
		i++;
	}
	while (i > 0)
	{
		ra(lib_a, 1, bench);
		i--;
	}
}

//Take medium_return outputput as i
//Use it to move the target on top of the stack
void	roller_b(int i, t_stack_library *lib_b, t_bench *bench)
{
	while (i < 0)
	{
		rrb(lib_b, 1, bench);
		i++;
	}
	while (i > 0)
	{
		rb(lib_b, 1, bench);
		i--;
	}
}
