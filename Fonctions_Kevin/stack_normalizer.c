/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_normalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:04:51 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/11 16:05:01 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int stack_normalizer (t_stack *lst, int total)
{//total = argc - starting value and lst = first in the stack
	t_stack *marker;
	t_stack *searcher;
	int i;
	
	marker = lst;
	searcher = marker -> next;
	i = 0;
	while(marker != NULL)
	{
		while(searcher != NULL)
		{
			if (searcher -> content < marker -> content)
				marker = searcher;
			searcher = searcher -> next;
		}
		marker -> order = i;
		i++;
		marker = lst;
		while(marker -> next != NULL && marker -> order != -1)
			marker = marker -> next;
		searcher = marker -> next;
	}
	return (0); //il a besoins de return qlqch?
}
