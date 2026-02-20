/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:11:32 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/20 14:17:57 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	true_launcher()
{
	if (i == 0)
	{
		if (bench->disorder < 0.2 || stack_a->length <= 5)
			bubble_sort(stack_a, stack_b, bench);
		else if (bench->disorder >= 0.2 && bench->disorder <= 0.5)
			medium_algorithm();
		else if (bench->disorder > 0.5)
			radix();
	}
	else if (i == 1)
		bubble_sort(stack_a, stack_b, bench);
	else if (i == 2)
		medium_algorithm;
	else if (i == 3)
		radix();
}


void	inst_launcher_bench(t_stack_library *stack_a, t_stack_library *stack_b,
							char **argv, t_bench *bench)
{
	int	i;

	i = inst_verif(stack_a, bench->argc, argv, bench);
	if (bench->bench_true == 1)
	{
		true_launcher();
	}
	else
		inst_launcher();
	bench_strategy();
	bench_calculator();
}

void	inst_launcher(t_stack_library *stack_a, t_stack_library *stack_b,
						char **argv, t_bench *bench)
{
	int	i;

	i = inst_verif(stack_a, bench->argc, argv, bench);
	if (bench->bench_true == 0)
	{
				if (i == 0)
		{
			if (bench->disorder < 0.2 || stack_a->length <= 5)
				bubble_sort(stack_a, stack_b, bench);
			else if (bench->disorder >= 0.2 && bench->disorder <= 0.5)
				medium;
			else if (bench->disorder > 0.5)
				complex;
		}
		else if (i == 1)
			bubble_sort(stack_a, stack_b, bench);
		else if (i == 2)
			medium;
		else if (i == 3)
			complex;
	}
}
