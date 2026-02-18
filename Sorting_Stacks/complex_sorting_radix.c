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

/////////////////////////////////////////////////////////////////////////////////////////////////////

while(order > 0 && n < 33)
{
	while(i < lib_a -> length)
	{
		i = fonc recherche le bit et return le nbr de mouvements a faire
		if (i < lib_a -> length)
			fonc roll avec i
		if (i < lib_a -> length)
			pb
	}
	while (lib_b -> begin != NULL)
		pa
	n++;//le traqueur
}

a coder:
-order (deja fait?)
-recherche de bit(reuse?)
-roll avec i (deja fait? / reuse?)

//utilisable
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

//a editer pour prendre n au lieu de chunk et chercher le bit
int medium_search(t_stack_library *lib_a, int chunk)
{
	t_stack *head;
	t_stack *tail;
	int i;

	head = lib_a -> begin;
	tail = lib_a -> end;
	i = 1;
	if(head -> order <= chunk)
		return (0);
	head = head->next;
	while(head -> order > chunk && tail -> order > chunk)
	{
		head = head -> next;
		tail = tail -> back;
		i++;
	}
	if(tail -> order <= chunk)
		i *= -1;
	return(i); //return le nb de roll a faire pour amener l element la ou il faut
}



//utilisable (call dans medium_sorting)
void roller_a(int i, t_stack_library *lib_a, t_bench *bench)
{
	while(i < 0)
	{
		rra(lib_a, 1, bench);
		i++;
	}
		while(i > 0)
	{
		ra(lib_a, 1, bench);
		i--;
	}
}