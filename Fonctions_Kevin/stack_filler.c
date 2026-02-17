/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_filler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:03:43 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/11 16:04:23 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int stack_filler (t_stack *starter, int i, int argc, char **argv)
{
	t_stack *writer;

	if (!starter || ! i || !argc || !argv)
		return (); //quel message d erreur si pb a l input?
	
	writer = starter;
	while(i < argc)
	{
	writer -> content = ft_atoi(argv [i]);
		writer = writer -> next;
	i++;
	}
	return (0);
}


//input i est le point depart de lecture