/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:30:02 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/19 16:45:50 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

float	disorder_calculator(t_stack_library *lst)
{
	t_stack	*searcher;
	float	i;

	i = 0;
	searcher = lst -> begin;
	while (searcher -> next != NULL)
	{
		if (searcher -> content > searcher -> next -> content)
			i++;
		searcher = searcher -> next;
	}
	if (i == 0)
		exit(EXIT_SUCCESS);
	return (i / (float)lst -> length);
}

void	bench_strategy(t_stack_library *stack_a, t_bench *bench, char **argv)
{
	int	x;

	x = 0;
	if (inst_detector_bench(argv, bench, x) == 0 && bench->bench_true == 1)
	{
		if (bench->disorder < 0.2)
			ft_print_error("Strategy : Adaptive / O(n2)");
		else if (bench->disorder >= 0.2 && bench->disorder <= 0.5)
			ft_print_error("Strategy : Adaptive / O(n√n)");
		else if (bench->disorder > 0.5)
			ft_print_error("Strategy : Adaptive / O(n log n)");
	}
	else if (inst_detector_bench(argv, bench, x) == 1
		&& bench->bench_true == 1)
		ft_print_error("Strategy : Simple / O(n2)");
	else if (inst_detector_bench(argv, bench, x) == 2
		&& bench->bench_true == 1)
		ft_print_error("Strategy : Medium / O(n√n)");
	else if (inst_detector_bench(argv, bench, x) == 3
		&& bench->bench_true == 1)
		ft_print_error("Strategy : Complex / O(n log n)");
	bench = bench_calculator_error(stack_a, bench);
}

t_bench	*bench_calculator(t_stack_library *stack_a, t_bench *bench)
{
	bench->total_ops = bench->nb_sa + bench->nb_sb + bench->nb_ss
		+ bench->nb_ra + bench->nb_rb + bench->nb_rr + bench->nb_rra
		+ bench->nb_rrb + bench->nb_rrr;
	bench->dis_percent = bench->disorder * 10000;
	ft_print_error("Disorder level : %d.%d\n", bench->dis_percent / 100,
		bench->dis_percent % 100);
	ft_print_error("Total number of operations : %d\n", bench->total_ops);
	ft_print_error("sa : %d\tsb : %d\tss : %d\tpa : %d\tpb : %d\n",
		bench->nb_sa, bench->nb_sb, bench->nb_ss, bench->nb_pa, bench->nb_pb);
	ft_print_error("ra : %d\trb : %d\trr : %d\t",
		bench->nb_ra, bench->nb_rb, bench->nb_rr);
	ft_print_error("ra : %d\trb : %d\trr : %d\t",
		bench->nb_rra, bench->nb_rrb, bench->nb_rrr);
	return (bench);
}
