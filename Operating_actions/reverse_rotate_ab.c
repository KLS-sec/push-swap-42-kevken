/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:05:36 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/04 17:40:37 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Ici on développe "rra", "rrb" et "rrr"
// Vérifier s'il y a besoin de renvoyer quelque chose quand on exécute une des actions
void	rra(t_stack_library *stack_a, int print_state)
{
	if (stack_length(stack_a) <= 1)
		return;
	if (print_state == 1)
		ft_printf("rra\n");
	else
		return ; // Juste une base, on adaptera
}
void	rrb(t_stack_library *stack_b, int print_state)
{
	if (stack_length(stack_b) <= 1)
		return;
	if (print_state == 1)
		ft_printf("rrb\n");
	else
		return; // Juste une base, on adaptera
}
void	rrr(t_stack_library *stack_a, t_stack_library *stack_b, int print_state)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print_state == 1)
		ft_printf("rrr\n");
	else
		return; // Juste une base, on adaptera
}
