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


int cplx_search(t_stack_library *lib_a, int n)		//trouve un ellement a push
{													//puis push back, recommencer et recall avec n++ jusqu a finir - faire un monolith puis separer?
	int i;
	t_stack *a;

	i = 0;
	a = t_stack_library -> begin
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
	int f;
	int n;

	nav = lib_a -> begin;
	n = 1;

	while(n < 33 && disorder_check != 0)
	{
		f = cplx_search;
		if(f == -1)
			while(lib_b -> length != 0)
				nav = pa;
		if (f != -1)
			roller_a(f, *lib_a, *lib_b, *bench)
		lib_b -> begin = pb;

	}

	return();
}
//rien ne vas
//le refaire de 0
//regler le pb d atteindre la fin de a
//peut etre faire un bete navigateur qui roll jusque la ou il etait?

while(desordre > 0)
{
cherche le bit a viser i
si i > au total dans A a ce moment alors renvois tt b dedans
roll jusqu a lui et envois vers b
n++
}
while(order > 0)
	while(i < lib_a -> length)
	i = recherche le bit et return le nbr de mouvements a faire
	if (i >= 0)
		roll avec i
	pb