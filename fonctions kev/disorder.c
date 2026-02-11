# include <unistd.h>
#include <stdlib.h>

float	disorder_calculator(t_stack *lst, float total)
{
	t_stack	*top;
	t_stack *bottom;
	float i;

	i = 0;
	if (!lst)
		exit(EXIT_FAILURE);
	top = lst;
	top = top -> next;
	bottom = lst;
	while (top != NULL)
	{
		if (top -> content > bottom -> content)
			i++;
		top = top -> next;
		bottom = bottom -> next;
	}
	if (i == 0 || top == lst) //gere si il n y a pas assez d input
		exit(EXIT_FAILURE);
	return (i = i/total);
}
