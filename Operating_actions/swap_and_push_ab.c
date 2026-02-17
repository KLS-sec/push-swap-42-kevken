/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push_ab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:05:32 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/13 11:16:47 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Ici on développe "sa", "sb", "ss", "pa" et "pb"
// Rajouter le booleen pour le checker, si assez de place (et qu'on fait le bonus)
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
	else if (print_state == 0 && bench->bench_true == 1)
		bench->nb_sa += 1;
	else
		return ;
}

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
	else if (print_state == 0 && bench->bench_true == 1)
		bench->nb_sb += 1;
	else
		return ;
}

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
	else if (print_state == 0 && bench->bench_true == 1)
		bench->nb_ss += 1;
	else
		return ;
}

// Voir si envoyer un pointeur de pointeur "**stack_a" pourrais retransformer la fonction en void
t_stack_library *pa(t_stack_library *stack_a, t_stack_library *stack_b,
					int print_state, t_bench *bench)
{	
	if (stack_length(stack_b) < 1)
		return (NULL);
	stack_a = push_front_dlst(stack_a, stack_b->begin->content);
	stack_b = pop_back_dlst(stack_b);
	if (print_state == 1)
	{
		ft_printf("pa\n");
		bench->nb_pa += 1;
		return (stack_a);
	}
	else if (print_state == 0 && bench->bench_true == 1)
	{
		bench->nb_pa += 1;
		return (stack_a);
	}
	else
		return (stack_a);
}

// Voir si envoyer un pointeur de pointeur "**stack_b" pourrais retransformer la fonction en void
t_stack_library *pb(t_stack_library *stack_a, t_stack_library *stack_b,
					int print_state, t_bench *bench)
{
	if (stack_length(stack_a) < 1)
		return (NULL);
	stack_b = push_front_dlst(stack_b, stack_a->begin->content);
	stack_a = pop_back_dlst(stack_a);
	if (print_state == 1)
	{
		ft_printf("pb\n");
		bench->nb_pb += 1;
		return (stack_b);
	}
	else if (print_state == 0 && bench->bench_true == 1)
	{
		bench->nb_pb += 1;
		return (stack_b);
	}
	else
		return (stack_b);
}
