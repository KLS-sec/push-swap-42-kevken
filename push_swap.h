/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:39:17 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/19 12:14:50 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "ft_print_error/ft_print_error.h"

typedef struct s_stack
{
	int				content;
	int				order;
	struct s_stack	*back;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stack_library
{
	int				length;
	struct s_stack	*begin;
	struct s_stack	*end;
}					t_stack_library;

typedef struct s_bench
{
	float			disorder;
	int				dis_percent;
	int				total_ops;
	int				bench_true;
	int				nb_pa;
	int				nb_pb;
	int				nb_sa;
	int				nb_sb;
	int				nb_ss;
	int				nb_ra;
	int				nb_rb;
	int				nb_rr;
	int				nb_rra;
	int				nb_rrb;
	int				nb_rrr;
}					t_bench;

t_stack			*ft_dlst_new(void);
t_stack_library	*full_list(t_stack_library *li, int argc, int pos);
t_stack_library	*push_back_dlst(t_stack_library *li);
t_stack_library	*push_front_dlst(t_stack_library *li);
t_stack_library	*pop_front_dlst(t_stack_library *li);
t_stack_library	*pop_back_dlst(t_stack_library *li);
t_stack_library	*clear_dlst(t_stack_library *li);
t_stack_library	*pb(t_stack_library *stack_a, t_stack_library *stack_b,
					int print_state, t_bench *bench);
t_stack_library	*pa(t_stack_library *stack_a, t_stack_library *stack_b,
					int print_state, t_bench *bench);
t_bench			*bench_calculator(t_stack_library *stack_a, t_bench *bench);
int 			duplicate_detector(t_stack *start);
int				stack_length(t_stack_library *li);
int				first_stack(t_stack_library *li);
int				last_stack(t_stack_library *li);
int				inst_detector (char **argv, t_bench *bench, int x);
int				inst_detector_bench (char **argv, t_bench *bench, int *x);
int				inst_verif (t_stack_library *lst, int argc,
					char **argv, t_bench *bench);
int				character_detection(int argc, char **argv, int pos);
int				max_min(int argc, char **argv, int j);
void			bench_strategy(t_stack_library *stack_a,
					t_bench *bench, char **argv);
void			rrr(t_stack_library *stack_a, t_stack_library *stack_b,
					int print_state, t_bench *bench);
void			rrb(t_stack_library *stack_b, int print_state, t_bench *bench);
void			rra(t_stack_library *stack_a, int print_state, t_bench *bench);
void			rr(t_stack_library *stack_a, t_stack_library *stack_b,
					int print_state, t_bench *bench);
void			rb(t_stack_library *stack_b, int print_state, t_bench *bench);
void			ra(t_stack_library *stack_a, int print_state, t_bench *bench);
void			ss(t_stack_library *stack_a, t_stack_library *stack_b,
					int print_state, t_bench *bench);
void			sb(t_stack_library *stack_b, int print_state, t_bench *bench);
void			sa(t_stack_library *stack_a, int print_state, t_bench *bench);
void			sort_three(t_stack_library *stack_a, t_bench *bench); // Vérifier s'il est nécessaire
void			sort_five_first(t_stack_library *stack_a,
					t_stack_library *stack_b, t_bench *bench); // Vérifier s'il est nécessaire
void			sort_five_second(t_stack_library *stack_a,
					t_stack_library *stack_b, t_bench *bench); // Vérifier s'il est nécessaire
void			bubble_sort(t_stack_library *stack_a,
					t_stack_library *stack_b, t_bench *bench);
void			bench_launcher (char **argv, t_bench *bench);
float			disorder_calculator(t_stack_library *lst);

#endif