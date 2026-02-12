/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:03:19 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/11 17:20:40 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	inst_comp(const char *s, char *argv, int ender)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < ender)
	{
		if(s[j] != argv[j])
			return (1);
		i++;
	}
	return (0);
}

int	inst_detector (int argc, char **argv)
{// si detecte qlqch lance tous les detecteurs (avec le +1 pour commencer a chercher les ellements)
	char a[11];

	*a = "--bench\0";
	if (inst_comp(*a , argv[1], 8) == 0 || inst_comp(*a, argv[2], 8))
		return(4);
	if (inst_comp(*a , argv[1], 11) == 0)
		return(1);
	*a = "--simple\0";
	if (inst_comp(*a , argv[1], 9) == 0)
		return(2);
	*a = "--complex\0";
	if (inst_comp(*a , argv[1], 10) == 0)
		return(3);
	*a = "--adaptive\0";
	if (inst_comp(*a , argv[1], 11) == 0)
		return(0); //adaptive is already by default
	return(0);//return la valeur pour que la lecture commence au bon endroit
}

int inst_launcher (int argc, char **argv) //launch instructions from here or send back code
{
	int i;

	i = inst_detector(argc, argv);
	if (i == 1)
	if (i == 2)
	if (i == 3)
	if (i == 4)

	return();
}
