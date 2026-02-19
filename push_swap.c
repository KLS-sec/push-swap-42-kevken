/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:27:40 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/19 11:02:52 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Ici contiendra le main et probablement la gestion des cas d'erreur ainsi que la fonction principale
// Les GUILLEMETS "" sont auto-interprétés dans bash, pas besoin de traiter le cas 'ARG="1 0 2"; ./push_swap 1 5 45 $ARG'
// car c'est l'équivalent de './push_swap 1 5 45 1 0 2' --> Ici "Error" car "1" y est 2 fois

/*ac = 2 --> argv[1] -> "135 201 4653"
ac = 3 --> argv -> 5 "135 201 4653" || argv -> 5 3 || bench + "534 5 53468 354";
ac = 4&+ --> argv -> 2 6 4 || bench + mod + 135 684;
bench->flag = 0;//count off
bench->flag = 1;//count on
pabench (a, b, bench)
{
	bench->booleen
}*/

// Afficher sa liste, si jamais une couille dans le potage arrive, à retirer sur le long terme
void print_list(t_stack_library *li)
{
	t_stack	*temp;
	
	if (li == NULL)
	{
		ft_printf("Liste vide.\n");
		return;
	}
	temp = li->begin;
	while(temp)
	{
		ft_printf("[%d] ", temp->content);
		temp = temp->next;
	}
	ft_printf("\n");
}
int	main(int argc)
{
	t_stack_library	*mylist;
	t_stack_library	*mylist_b;
	t_bench			*bench;
	int				a = 1, b = 2, c = 0;
	float			test = 0.4933584;

//	if (argc <= 2) À rajouter ici ou dans la fonction d'exec si pas assez de place
//		return (0);
	mylist = NULL;
	mylist_b = NULL;
	bench = NULL;
	c = test * 10000;
	ft_printf("\nTest float to int : %d\n", c);
	ft_printf("\nTest float to int : %d.%d\n", c / 100, c % 100);
	ft_print_error("Valeur de a : %d\nValeur de b : %d\n\n",
	a, b); // Vérification si passage à la ligne problématique (non) + fonction réalise ce que je souhaite (oui)
	mylist = push_back_dlst(mylist, 14);
	print_list(mylist);
	mylist = push_back_dlst(mylist, 5);
	print_list(mylist);
	mylist = push_back_dlst(mylist, -6);
	print_list(mylist);
	ft_printf("\n-------------------------------------\n");
	print_list(mylist);
	mylist = push_front_dlst(mylist, 12);
	print_list(mylist);
	mylist = push_front_dlst(mylist, 578);
	print_list(mylist);
	mylist = push_front_dlst(mylist, -4546);
	print_list(mylist);
	sa(mylist, 1, bench);
	ft_printf("\n-------------------------------------\n");
	mylist_b = pb(mylist, mylist_b, 1, bench);
	ft_printf("Liste B =\n");
	print_list(mylist_b);
	mylist_b = pb(mylist, mylist_b, 1, bench);
	ft_printf("Liste A =\n");
	print_list(mylist);
	ft_printf("Liste B =\n");
	print_list(mylist_b);
	ft_printf("\n-------------------------------------\n");
	ft_printf("Taille de la liste : %d\n", stack_length(mylist));
	ft_printf("\n-------------------------------------\n");
	rr(mylist, mylist_b, 1, bench);
	ft_printf("Liste A =\n");
	print_list(mylist);
	ft_printf("Liste B =\n");
	print_list(mylist_b);
	ft_printf("\n-------------------------------------\n");
	mylist = pop_front_dlst(mylist);
	print_list(mylist);
	ft_printf("\n-------------------------------------\n");
	rrr(mylist, mylist_b, 1, bench);
	ft_printf("Liste A =\n");
	print_list(mylist);
	ft_printf("Liste B =\n");
	print_list(mylist_b);
	ft_printf("\n-------------------------------------\n");
	mylist = pop_back_dlst(mylist);
	print_list(mylist);
	ft_printf("Taille de la liste : %d\n", stack_length(mylist));
	ft_printf("\n-------------------------------------\n");
	mylist = clear_dlst(mylist);
	mylist_b = clear_dlst(mylist_b);
	print_list(mylist);
	print_list(mylist_b);
	ft_printf("Taille de la liste A : %d\n", stack_length(mylist));
	ft_printf("Taille de la liste B : %d\n", stack_length(mylist_b));
	return (0);
}

//./push_swap --bench 5 7 2 8 "6 9 34 2" a 7
