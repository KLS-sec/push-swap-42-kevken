/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push_ab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:05:32 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/22 17:12:20 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Here we implemented "sa", "sb", "ss", "pa" et "pb"

// Switch the first and second block from stack_a
void	sa(t_stack_library *stack_a, int print_state, t_bench *bench)
{
	t_stack	*swap_first;
	int		temp;

	if (stack_length(stack_a) <= 1)
		return ;
	swap_first = stack_a->begin;
	temp = stack_a->begin->next->content;
	stack_a->begin->next->content = stack_a->begin->content;
	stack_a->begin->content = temp;
	if (print_state == 1)
	{
		ft_printf("sa\n");
		bench->nb_sa += 1;
	}
	else if (print_state == 0)
		bench->nb_sa += 1;
	return ;
}

// Switch the first and second block from stack_b
void	sb(t_stack_library *stack_b, int print_state, t_bench *bench)
{
	t_stack	*swap_first;
	int		temp;

	if (stack_length(stack_b) <= 1)
		return ;
	swap_first = stack_b->begin;
	temp = stack_b->begin->next->content;
	stack_b->begin->next->content = stack_b->begin->content;
	stack_b->begin->content = temp;
	if (print_state == 1)
	{
		ft_printf("sb\n");
		bench->nb_sb += 1;
	}
	else if (print_state == 0)
		bench->nb_sb += 1;
	return ;
}

// Switch the first and second block from both stacks
void	ss(t_stack_library *stack_a, t_stack_library *stack_b,
			int print_state, t_bench *bench)
{
	sa(stack_a, 0, bench);
	sb(stack_b, 0, bench);
	if (print_state == 1)
	{
		ft_printf("ss\n");
		bench->nb_ss += 1;
	}
	else if (print_state == 0)
		bench->nb_ss += 1;
	return ;
}

// Transfer a block from stack_b to stack_a
void	pa(t_stack_library **stack_a, t_stack_library **stack_b,
		int print_state, t_bench *bench)
{
	if (stack_length(*stack_b) < 1)
		return ;
	*stack_a = push_front_dlst(*stack_a, (*stack_b)->begin->content);
	*stack_b = pop_back_dlst(*stack_b);
	if (print_state == 1)
	{
		ft_printf("pa\n");
		bench->nb_pa += 1;
	}
	else if (print_state == 0)
	{
		bench->nb_pa += 1;
	}
	return ;
}// Transfer a block from stack_a to stack_b
void	pb(t_stack_library **stack_a,
		t_stack_library **stack_b, int print_state, t_bench *bench)
{
	if (stack_length(*stack_a) < 1)
		return ;
	*stack_b = push_front_dlst(*stack_b, (*stack_a)->begin->content);
	*stack_a = pop_back_dlst(*stack_a);
	if (print_state == 1)
	{
		ft_printf("pb\n");
		bench->nb_pb += 1;
	}
	else if (print_state == 0)
	{
		bench->nb_pb += 1;
	}
	return ;
}
