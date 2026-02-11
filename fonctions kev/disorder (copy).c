# include <unistd.h>
#include <stdlib.h>

float	disorder_calculator(t_stack *lst, float total)
{
	t_stack searcher;
	float i;

	i = 0;
	if (!lst)
		exit(EXIT_FAILURE);
	searcher = lst;
	while (searcher -> next != NULL)
	{
		if (searcher -> content > searcher -> next -> content)
			i++;
		top = top -> next;
	}
	if (i == 0) //gere deja si il n y a pas assez d input
		exit(EXIT_FAILURE);
	return (i = i/total);
}
