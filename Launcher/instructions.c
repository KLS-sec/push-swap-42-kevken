/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:03:19 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/22 15:39:38 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Detect which strategy the user wrote in as arg 1 or 2
int	inst_detector(char **argv, int x)
{
	if (ft_strncmp("--simple", argv[x], 8) == 0)
		return (1);
	if (ft_strncmp("--medium", argv[x], 8) == 0)
		return (2);
	if (ft_strncmp("--complex", argv[x], 9) == 0)
		return (3);
	if (ft_strncmp("--adaptive\0", argv[x], 10) == 0)
		return (0);
	return (0);
}

// Detect if the bench will be used depending on what the user wrote
int	inst_detector_bench(char **argv, t_bench *bench, int *x)
{
	int	stock;

	stock = 0;
	*x = 1;
	if (ft_strncmp("--bench", argv[*x], 7) == 0)
	{
		*x = 2;
		bench->bench_true = 1;
		stock = inst_detector(argv, *x);
	}
	else
	{
		bench->bench_true = 0;
		stock = inst_detector(argv, *x);
	}
	return (stock);
}

// Launch all verifications, exit in error or send back the launch value
int	inst_verif(t_stack_library *lst, int argc, char **argv, t_bench *bench)
{
	int	i;
	int	*pos;

	pos = NULL;
	*pos = 0;
	bench->disorder = disorder_calculator(lst);
	i = inst_detector_bench(argv, bench, pos);
	if (character_detection(argc, argv, *pos) == 1)
	{
		ft_print_error("Error\n");
		exit(EXIT_FAILURE);
	}
	lst = full_list(lst, argc, *pos);
	lst = stack_filler(lst, *pos, argc, argv);
	if (duplicate_detector(lst->begin) == 1)
	{
		ft_print_error("Error\n");
		exit(EXIT_FAILURE);
	}
	stack_normalizer(lst->begin);
	return (i);
}

// Look the stack length or disorder to execute the best sorting algorithm
void	true_launcher(t_stack_library *stack_a, t_stack_library *stack_b,
						int i, t_bench *bench)
{
	if (stack_a->length == 3)
		sort_three(stack_a, bench);
	else if (stack_a->length == 5)
		sort_five_first(stack_a, stack_b, bench);
	else if (i == 0)
	{
		if (bench->disorder < 0.2)
			bubble_sort(stack_a, stack_b, bench);
		else if (bench->disorder >= 0.2 && bench->disorder <= 0.5)
			medium_algorithm(stack_a, stack_b, bench, 1);
		else if (bench->disorder > 0.5)
			radix(stack_a, stack_b, bench, 1);
	}
	else if (i == 1)
		bubble_sort(stack_a, stack_b, bench);
	else if (i == 2)
		medium_algorithm(stack_a, stack_b, bench, 1);
	else if (i == 3)
		radix(stack_a, stack_b, bench, 1);
}

// Launch true_launcher and verify if bench is needed as an output
void	inst_launcher(t_stack_library *stack_a, t_stack_library *stack_b,
							char **argv, t_bench *bench)
{
	int	i;

	bench = ft_calloc(1, sizeof(t_bench));
	if (!bench)
		exit(EXIT_FAILURE);
	i = inst_verif(stack_a, bench->argc, argv, bench);
	if (bench->bench_true == 1)
	{
		true_launcher(stack_a, stack_b, i, bench);
		bench_strategy(bench, argv);
		bench_calculator(bench);
	}
	else
		true_launcher(stack_a, stack_b, i, bench);
}
