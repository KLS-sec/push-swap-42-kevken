#include "push_swap.h"

// if disorder check == 0 kill radix
int disorder_check(t_stack_library *lib_a) //check disorder level
{
	t_stack base;
	t_stack nav;

	base = lib_a -> begin;
	nav = base -> next;
	while(base -> next != NULL)
	{
		if(base -> content > nav -> content)
			return (1);
		base = base -> next;
		nav = nav -> next;
	}
	return(0);
}
//search the closest value to sent
int cplx_search(t_stack_library *lib_a, int n)
{
	t_stack *head;
	t_stack *tail;
	int i;

	head = lib_a -> begin;
	tail = lib_a -> end;
	i = 1;
	if ((head -> content & (1 << n)) == 0)
		return (0);
	head = head->next;
	while((head -> content & (1 << n)) != 0 &&
	(tail -> content & (1 << n)) != 0 && head != NULL)
	{
		head = head -> next;
		tail = tail -> back;
		i++;
	}
	if((tail -> content & (1 << n)) == 0)
		i *= -1;
	return(i); //return le nb de roll a faire pour amener l element la ou il faut
}

int radix(t_stack_library *lib_a, t_stack_library *lib_b, t_bench *bench,
	int print_state)
{
	int i;
	int n;//bit tracer

	i = cplx_search(lib_a, n)
	n = 1;
	while(disorder_check(lib_a) > 0 && n < 32) //n doit commencer a 0
	{
		while(i < lib_a -> length)
		{
			i = cplx_search(lib_a, n); //cherche le bit
			if (i < lib_a -> length)
				roller_a(i, lib_a, bench); //call depuis medium search
			if (i < lib_a -> length)
				lib_b -> begin = pb(stack_a, stack_b, print_state, bench);
		}
		while (lib_b -> begin != NULL)
			lib_a -> begin = pa(stack_a, stack_b, print_state, bench);
		n++;
	}
	return(0); //return qlqch?
}
