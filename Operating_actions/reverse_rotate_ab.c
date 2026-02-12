/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:05:36 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/11 17:41:02 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Here we are implementing "rra", "rrb" and "rrr" (last become first)
// Vérifier s'il y a besoin de renvoyer quelque chose quand on exécute une des actions
void	rra(t_stack_library *stack_a, int print_state, t_bench *bench)
{
	if (stack_length(stack_a) <= 1)
		return ;
	stack_a = push_front_dlst(stack_a, stack_a->end->content);
	stack_a = pop_front_dlst(stack_a);
	if (print_state == 1)
		ft_printf("rra\n");
	else
		return ;
}

void	rrb(t_stack_library *stack_b, int print_state, t_bench *bench)
{
	if (stack_length(stack_b) <= 1)
		return ;
	stack_b = push_front_dlst(stack_b, stack_b->end->content);
	stack_b = pop_front_dlst(stack_b);
	if (print_state == 1)
		ft_printf("rrb\n");
	else
		return ;
}

void	rrr(t_stack_library *stack_a, t_stack_library *stack_b,
			int print_state, t_bench *bench)
{
	rra(stack_a, 0, bench);
	rrb(stack_b, 0, bench);
	if (print_state == 1)
		ft_printf("rrr\n");
	else
		return ;
}
