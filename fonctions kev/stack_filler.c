#include <stdlib.h>

int stack_filler (t_stack *starter; int i; int argc; char **argv)
{
	t_stack *writer;

	if (!starter || ! i || !argc || !argv)
		return(); //quel message d erreur si pb a l input?
	
	writer = starter;
	while(i < argc)
	{
	writer -> content = ft_atoi(argv [i]);
		writer = writer -> next;
	i++;
	}
	return(0);
}


//input i est le point depart de lecture