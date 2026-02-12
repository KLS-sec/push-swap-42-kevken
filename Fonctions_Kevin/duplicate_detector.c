/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_detector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:01:41 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/11 16:01:48 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int duplicate_detector(t_stack *start)
{
	t_stack *marker;
	t_stack *searcher;
	
	marker = start;
	searcher = marker -> next;
	while(marker != NULL)
	{
		while(searcher != NULL)
		{
			if (searcher -> content == marker -> content)
				return(1);
			searcher = searcher -> next;
		}
		marker = marker -> next;
		searcher = marker -> next;
	}
	return(0);
}
