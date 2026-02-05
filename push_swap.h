/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:39:17 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/04 17:28:08 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct		s_stack
{
	int				content;
	struct s_stack	*back;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stack_library
{
	int				length;
	struct s_stack	*begin;
	struct s_stack	*end;
}					t_stack_library;

// Vérifier s'il y a besoin de renvoyer quelque chose quand on exécute une des actions

t_stack	*ft_dlst_new(int content);
t_stack_library	*push_back_dlst(t_stack_library *li, int x);
t_stack_library	*push_front_dlst(t_stack_library *li, int x);
t_stack_library	*pop_front_dlst(t_stack_library *li);
t_stack_library	*pop_back_dlst(t_stack_library *li);
t_stack_library	*clear_dlst(t_stack_library *li);
int		stack_length(t_stack_library *li);
int		first_stack(t_stack_library *li);
int		last_stack(t_stack_library *li);
void	rrr(t_stack_library *stack_a, t_stack_library *stack_b, int print_state);
void	rrb(t_stack_library *stack_b, int print_state);
void	rra(t_stack_library *stack_a, int print_state);
void	rr(t_stack_library *stack_a, t_stack_library *stack_b, int print_state);
void	rb(t_stack_library *stack_b, int print_state);
void	ra(t_stack_library *stack_a, int print_state);
void	pb(t_stack_library *stack_a, t_stack_library *stack_b, int print_state);
void	pa(t_stack_library *stack_a, t_stack_library *stack_b, int print_state);
void	ss(t_stack_library *stack_a, t_stack_library *stack_b, int print_state);
void	sb(t_stack_library *stack_b, int print_state);
void	sa(t_stack_library *stack_a, int print_state);

#endif