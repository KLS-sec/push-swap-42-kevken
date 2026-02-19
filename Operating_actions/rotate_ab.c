/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:05:34 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/17 16:22:37 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Here we are implementing "ra", "rb" and "rr" (first become last)
// Vérifier s'il y a besoin de renvoyer quelque chose quand on exécute une des actions
void	ra(t_stack_library *stack_a, int print_state, t_bench *bench)
{
	if (stack_length(stack_a) <= 1)
		return ;
	stack_a = push_back_dlst(stack_a, stack_a->begin->content);
	stack_a = pop_back_dlst(stack_a);
	if (print_state == 1)
	{
		ft_printf("ra\n");
		bench->nb_ra += 1;
	}
	else if (print_state == 0 && bench->bench_true == 1)
		bench->nb_ra += 1;
	else
		return ;
}
void	rb(t_stack_library *stack_b, int print_state, t_bench *bench)
{
	if (stack_length(stack_b) <= 1)
		return ;
	stack_b = push_back_dlst(stack_b, stack_b->begin->content);
	stack_b = pop_back_dlst(stack_b);
	if (print_state == 1)
	{
		ft_printf("rb\n");
		bench->nb_rb += 1;
	}
	else if (print_state == 0 && bench->bench_true == 1)
		bench->nb_rb += 1;
	else
		return ;
}
void	rr(t_stack_library *stack_a, t_stack_library *stack_b,
			int print_state, t_bench *bench)
{
	ra(stack_a, 0, bench);
	rb(stack_b, 0, bench);
	if (print_state == 1)
	{
		ft_printf("rr\n");
		bench->nb_rr += 1;
	}
	else if (print_state == 0 && bench->bench_true == 1)
		bench->nb_rr += 1;
	else
		return ;
}
