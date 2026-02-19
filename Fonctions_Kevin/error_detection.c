/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_detection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:02:00 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/19 13:05:55 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*i = error_detection
if i = 1 return ("error")
if i = 2 return
ne reagit pas a 0*/


int character_detection(int argc, char **argv, int pos)
{
	int k;
	int j;

	k = 0;
	j = pos;
	while (j < argc)
	{
		while(argv[j][k] != '\0')
		{
			if (k == 0 && (argv[j][k] == '-' || argv[j][k] == '+'))
				k++;
			if ((argv[j][k] < '0' || argv[1][k] > '9')
			&& argv[j][k+1] != '\0')
				return (1);
			if (argv[j][k+1] != '\0')
				k++;
		}
		j++;
		k = 0;
	}
	k = max_min(argc, argv, pos);
	return (k);
}

unsigned int	ft_atoi_minmax(const char *nptr)
{
	int	i;
	unsigned int	value;

	i = 0;
	value = 0;
	if (!((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32 || nptr[i] == 45
			|| nptr[i] == 43 || (nptr[i] >= '0' && nptr[i] <= '9')))
		return (0);
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		value = value * 10 + (nptr[i] - '0');
		i++;
	}
	return (value);
}

//int max 2147483647
//int min -2147483648
//unsigned intmax 4294967295
int max_min(int argc, char **argv, int j)
{
	int i;
	unsigned int comp;

	i = 0;
	while (j < argc)
	{
		while(argv[j][i] != '\0') //fin
			i++;
		if ((argv[j][0] == '-' && i > 11) || (argv[j][0] != '-' && i > 10))	//kill if too big
			return(1);
		if ((argv[j][0] == '-' && argv[j][1] > '2' && i == 11)
			|| (argv[j][0] > '2' && i == 10))	//kill if too big, avoid overloading int
			return(1);
		if ((argv[j][0] == '-' && i == 11) || (argv[j][0] != '-' && i == 10))
			{
				comp = ft_atoi_minmax(argv[j]);
				if (argv[j][0] == '-' && comp > 2147483648)
					return (1);
				if (argv[j][0] != '-' && comp > 2147483647)
					return (1);
			}
		i = 0;
		j++;
	}
	return (0);
}

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
			if ((*searcher) . content == marker -> content)
				return(1);
			searcher = searcher -> next;
		}
		marker = marker -> next;
		searcher = marker -> next;
	}
	return(0);
}

//trillean = 0 tout vas bien
//trillean = 1 doit retourner erreur
//trillean = 2 interuption, ne retourne rien -->> remplacer par exit(EXIT_FAILURE)
