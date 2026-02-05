/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:05:34 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/04 17:40:13 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Ici on développe "ra", "rb" et "rr"
// Vérifier s'il y a besoin de renvoyer quelque chose quand on exécute une des actions
void	ra(t_stack_library *stack_a, int print_state)
{
	if (stack_length(stack_a) <= 1)
		return;
	if (print_state == 1)
		ft_printf("ra\n");
	else
		return; // Juste une base, on adaptera
}
void	rb(t_stack_library *stack_b, int print_state)
{
	if (stack_length(stack_b) <= 1)
		return;
	if (print_state == 1)
		ft_printf("rb\n");
	else
		return; // Juste une base, on adaptera
}
void	rr(t_stack_library *stack_a, t_stack_library *stack_b, int print_state)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print_state == 1)
		ft_printf("rr\n");
	else
		return; // Juste une base, on adaptera
}
