/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:03:19 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/19 18:20:17 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	inst_detector(char **argv, t_bench *bench, int x)
{
	if (ft_strncmp("--simple", argv[x], 9))
		return (1);
	if (ft_strncmp("--medium", argv[x], 9))
		return (2);
	if (ft_strncmp("--complex", argv[x], 10))
		return (3);
	if (ft_strncmp("--adaptive\0", argv[x], 11))
		return (0);
	return (0);
}
// Faire attention à ne pas executer le bench ici, il faut faire le tri d'abord
int	inst_detector_bench(char **argv, t_bench *bench, int *x)
{
	int	stock;

	stock = 0;
	*x = 1;
	if (ft_strncmp("--bench", argv[*x], 8) == 0)
	{
		*x = 2;
		bench->bench_true = 1;
		stock = inst_detector(argv, bench, *x);
	}
	else
	{
		bench->bench_true = 0;
		stock = inst_detector(argv, bench, *x);
	}
	return (stock);
}
// Launch instructions from here or send back code
int inst_verif(t_stack_library *lst, int argc, char **argv, t_bench *bench)
{
	int i;
	int *pos;

	*pos = 0;
	bench->disorder = disorder_calculator(lst);
	i = inst_detector_bench(argv, bench, pos);
	lst = full_list(lst, argc, *pos);
	lst = stack_filler(lst, pos, argc, argv);
	if (character_detection(argc, argv, *pos) == 1
		|| duplicate_detector(lst->begin) == 1)
	{
		ft_print_error("Error\n");
		exit(EXIT_FAILURE);
	}
	stack_normalizer(lst->begin);
	return (i);
}
// Voir comment rassembler certaines variables
void	inst_launcher_bench(t_stack_library *stack_a, t_stack_library *stack_b, int argc, char **argv, t_bench *bench)
{
	int	i;

	i = inst_verif(stack_a, argc, argv, bench);
	if (bench->bench_true == 1)
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
	else
		inst_launcher();
	bench_strategy();
	bench_calculator();
}
// If bench->true == 1, utiliser le bench après chaque tri, sinon faire sans