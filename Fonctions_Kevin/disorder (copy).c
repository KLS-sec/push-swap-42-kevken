/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder (copy).c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:59:11 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/11 16:00:56 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

float	disorder_calculator(t_stack *lst, float total)
{
	t_stack *searcher;
	float i;

	i = 0;
	if (!lst)
		exit(EXIT_FAILURE); // ATTENTION, COUPE LE PROGRAMME SANS RETOUR D'ERREUR, penser à ajouter ce retour
	searcher = lst;
	while (searcher -> next != NULL)
	{
		if (searcher -> content > searcher -> next -> content)
			i++;
		searcher = searcher -> next;
	}
	if (i == 0) //gere deja si il n y a pas assez d input
		exit(EXIT_FAILURE); // ATTENTION, COUPE LE PROGRAMME SANS RETOUR D'ERREUR, penser à ajouter ce retour
	return (i = i/total);
}
