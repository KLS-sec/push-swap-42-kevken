//if ( (valeur & (1 << n)) != 0 )
//verifie si valeur du bit en partant de la droite est = 1
//valeur |= (1 << n);
//change en 1 le n bit en partant de la droite

#include "push_swap.h"

// if disorder check == 0 end the function;
int disorder_check(t_stack_library *lib_a) //check disorder level
{
	t_stack base;
	t_stack nav;
	int i;

	base = lib_a -> begin;
	nav = base -> next;
	i = 0;//0 ok, 1 error

	while(i == 0 && base -> next != NULL)
	{
		if(base -> content > nav -> content)
			return (1);
		base = base -> next;
		nav = nav -> next;
	}

	return(0)
}


int finder(t_stack_library *lib_a, int n)	//trouve un ellement a push
{																	//puis push back, recommencer et recall avec n++ jusqu a finir - faire un monolith puis separer?
	int i;

	i = 0;
	while(a != NULL)
	{
		if ((a -> order & (1 << n)) != 0)	//cherche bit a 0
			return(i);						//return le nombre de move a faire
		i++;
	}
	return(-1)								//securite si il n y a aucun bit correspondant
}



pusher		//roule puis pousse
come back	//renvois tt sur a
//mettre le tout dans une boucle qui check regulierrement le desordre
//n s incremente entre chaque boucle




int radix(t_stack_library *lib_a, t_stack_library *lib_b, t_bench *bench,
	int print_state)
{
	t_stack *nav;
	int bin;
	int n;

	nav = lib_a -> begin;
	bin = 0;
	n = 1;

	while(nav -> next != NULL && n < 33)
	{
		if ((valeur & (1 << n)) != 0 )
			lib_b = pb;
		nav = nav -> next;
	}






	return();
}


123
321
111
006