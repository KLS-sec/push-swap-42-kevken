/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:30:02 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/13 18:06:10 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void	bench_strategy(t_stack_library *stack_a, t_bench *bench, char **argv)
{
	if (inst_detector(argv, bench) == 0 && bench->bench_true == 1)
		if (bench->disorder < 0.2)
			ft_printf("Strategy : Adaptive / O(n2)");
		else if (bench->disorder >= 0.2 && bench->disorder <= 0.5)
			ft_printf("Strategy : Adaptive / O(n√n)");
		else if (bench->disorder > 0.5)
			ft_printf("Strategy : Adaptive / O(n log n)");
	else if (inst_detector(argv, bench) == 1 && bench->bench_true == 1)
		ft_printf("Strategy : Simple / O(n2)");
	else if (inst_detector(argv, bench) == 2 && bench->bench_true == 1)
		ft_printf("Strategy : Medium / O(n√n)");
	else if (inst_detector(argv, bench) == 3 && bench->bench_true == 1)
		ft_printf("Strategy : Complex / O(n log n)");
	bench = bench_calculator(stack_a, bench);
}

t_bench	*bench_calculator(t_stack_library *stack_a, t_bench *bench)
{
	bench->total_ops = bench->nb_sa + bench->nb_sb + bench->nb_ss + bench->nb_ra +
	bench->nb_rb + bench->nb_rr + bench->nb_rra + bench->nb_rrb + bench->nb_rrr;
	/* Potentiellement séparer ou stocker la valeur du calcul du disorder plus tôt par ailleurs,
	car si le disorder est calculé APRÈS le tri, il affichera toujours "0%"*/
	bench->disorder = disorder_calculator(stack_a);
	ft_printf("Disorder level : %f\n", bench->disorder * 100); // --> %f Ne marche pas encore, à implémenter
	ft_printf("Total number of operations : %d\n", bench->total_ops);
	ft_printf("sa : %d\tsb : %d\tss : %d\tpa : %d\tpb : %d\n",
		bench->nb_sa, bench->nb_sb, bench->nb_ss, bench->nb_pa, bench->nb_pb);
	ft_printf("ra : %d\trb : %d\trr : %d\t",
		bench->nb_ra,  bench->nb_rb,  bench->nb_rr);
	ft_printf("ra : %d\trb : %d\trr : %d\t",
		bench->nb_rra,  bench->nb_rrb,  bench->nb_rrr);
	return (bench);
}


void	bench_strategy_error(t_stack_library *stack_a,
			t_bench *bench, char **argv)
{
	if (inst_detector(argv, bench) == 0 && bench->bench_true == 0)
		if (bench->disorder < 0.2)
			ft_print_error("Strategy : Adaptive / O(n2)");
		else if (bench->disorder >= 0.2 && bench->disorder <= 0.5)
			ft_print_error("Strategy : Adaptive / O(n√n)");
		else if (bench->disorder > 0.5)
			ft_print_error("Strategy : Adaptive / O(n log n)");
	else if (inst_detector(argv, bench) == 1 && bench->bench_true == 0)
		ft_print_error("Strategy : Simple / O(n2)");
	else if (inst_detector(argv, bench) == 2 && bench->bench_true == 0)
		ft_print_error("Strategy : Medium / O(n√n)");
	else if (inst_detector(argv, bench) == 3 && bench->bench_true == 0)
		ft_print_error("Strategy : Complex / O(n log n)");
	bench = bench_calculator_error(stack_a, bench);
}

t_bench	*bench_calculator_error(t_stack_library *stack_a, t_bench *bench)
{
	bench->total_ops = bench->nb_sa + bench->nb_sb + bench->nb_ss + bench->nb_ra +
	bench->nb_rb + bench->nb_rr + bench->nb_rra + bench->nb_rrb + bench->nb_rrr;
	/* Potentiellement séparer ou stocker la valeur du calcul du disorder plus tôt par ailleurs,
	car si le disorder est calculé APRÈS le tri, il affichera toujours "0%"*/
	bench->disorder = disorder_calculator(stack_a);
	ft_print_error("Disorder level : %f\n", bench->disorder * 100); // --> %f Ne marche pas encore, à implémenter
	ft_print_error("Total number of operations : %d\n", bench->total_ops);
	ft_print_error("sa : %d\tsb : %d\tss : %d\tpa : %d\tpb : %d\n",
		bench->nb_sa, bench->nb_sb, bench->nb_ss, bench->nb_pa, bench->nb_pb);
	ft_print_error("ra : %d\trb : %d\trr : %d\t",
		bench->nb_ra,  bench->nb_rb,  bench->nb_rr);
	ft_print_error("ra : %d\trb : %d\trr : %d\t",
		bench->nb_rra,  bench->nb_rrb,  bench->nb_rrr);
	return (bench);
}