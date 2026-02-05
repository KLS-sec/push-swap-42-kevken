/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push_ab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:05:32 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/06 00:14:24 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Ici on développe "sa", "sb", "ss", "pa" et "pb"
// Vérifier s'il y a besoin de renvoyer quelque chose quand on exécute une des actions
// Rajouter le booleen pour le checker, si assez de place (et qu'on fait le bonus)
void	sa(t_stack_library *stack_a, int print_state)
{
	t_stack	*swap_first;
	t_stack	*swap_second;
	
	if (stack_length(stack_a) <= 1)
		return;
	swap_first->content = stack_a->begin->content; // = 1
	swap_second->content = stack_a->begin->next->content; // = 2
	stack_a->begin->content = swap_second->content; // = 2
	stack_a->begin->next->content = swap_first->content; // = 1
	
	if (print_state == 1)
		ft_printf("sa\n");
	else
		return; // Juste une base, on adaptera
}
void	sb(t_stack_library *stack_b, int print_state)
{
	t_stack	*swap_first;
	t_stack	*swap_second;
	
	if (stack_length(stack_b) <= 1)
		return;
	swap_first->content = stack_b->begin->content; // = 1
	swap_second->content = stack_b->begin->next->content; // = 2
	stack_b->begin->content = swap_second->content; // = 2
	stack_b->begin->next->content = swap_first->content; // = 1
	
	if (print_state == 1)
		ft_printf("sb\n");
	else
		return; // Juste une base, on adaptera
}
void	ss(t_stack_library *stack_a, t_stack_library *stack_b, int print_state)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print_state == 1)
		ft_printf("ss\n");
	else
		return; // Juste une base, on adaptera
}
void	pa(t_stack_library *stack_a, t_stack_library *stack_b, int print_state)
{	
	if (stack_length(stack_b) < 1)
		return;
	stack_a = push_front_dlst(stack_a, stack_b->begin->content);
	stack_b = pop_front_dlst(stack_b);
	if (print_state == 1)
		ft_printf("pa\n");
	else
		return; // Juste une base, on adaptera
}
void	pb(t_stack_library *stack_a, t_stack_library *stack_b, int print_state)
{
	if (stack_length(stack_a) < 1)
		return;
	stack_b = push_front_dlst(stack_b, stack_a->begin->content);
	stack_a = pop_front_dlst(stack_a);
	if (print_state == 1)
		ft_printf("pb\n");
	else
		return; // Juste une base, on adaptera
}
