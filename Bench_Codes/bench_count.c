/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:30:02 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/12 15:51:11 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench bench_calculator (t_stack_library *stack_a, t_bench bench)
{
	bench.total_ops = bench.nb_sa + bench.nb_sb + bench.nb_ss + bench.nb_ra +
	bench.nb_rb + bench.nb_rr + bench.nb_rra + bench.nb_rrb + bench.nb_rrr;
	bench.disorder = disorder_calculator(stack_a, stack_a->length) * 100;
	write(2, "Disordel level (%%) : ", 23);
	write(2, "%.2f", 64); // Ne marche pas non plus, voir comment gérer les float
	write(2, "Total number of operations : ", 30);
	ft_printf("%d", bench.total_ops); // Ne fonctionne pas, ça va l'afficher sur la sortie standard et non erreur, à corriger
	return (bench);
}

int	bench_strategy ()
{
	
}
