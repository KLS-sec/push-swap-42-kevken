#include <unistd.h>

//Square root (rounded down) of n
int square_root(int n) //calcul racine de n ou va la valeur la valeur en dessou la plus proche
{
	int i;

	i = 1;
	while(((i+1)*(i+1)) <= n)
		i++;
	return(i);
}

//search for values under chunk and count the moves needed to reach it
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
		tail = tail -> next;
		i++;
	}
	if(tail -> order <= chunk)
		i *= -1;
	return(i); //return le nb de roll a faire pour amener l element la ou il faut
}

//take medium_search input as i and use it to move the targeted on the top of the stack
void medium_move(int i, t_stack_library *lib_a, t_stack_library *lib_b, t_bench *bench) //pr regler le pb creer une struc mettre des val dedans? je met 1 en attendant, on vas creer une fonction pr ca
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

//small efficiency enhancer that reverse top 2 struct of b if needed
void pre_organiser (t_stack_library *lib_b, int print_state, t_bench *bench, int *j)
{
	if(lib_b -> order < lib_b -> next -> order && lib_b -> length > 1)
		sb(lib_b, print_state, *bench);
	j++; //to gain a line in the main fonc
}



/* 
take as argunent
	lib_a :
	lib_b :
	bench :
	print_state :
return ..., or -1 in case of error
fail if
side effect : lib_a and lib_be will be modified
undefined behaviour if argument are not properly validated before calling
*/
int medium_algorythm(t_stack_library *lib_a, t_stack_library *lib_b,
	t_bench *bench, int print_state)
{
	int chunk;
	int i;
	int j;

	chunk = square_root(lib_a -> length);
	i = 1;
	j = 0;
	while(lib_a -> begin != NULL)
	{
		while(j < (chunk/i) && lib_a -> begin != NULL)
		{
		//double chercheur debut/fin pour trouver le plus proche (faire partir le fin du debut pour garder le compte des mouvements) parmis les < chunk
		//mouvement puis push b
		medium_move(medium_search(lib_a, chunk), lib_a, lib_b, bench); //searche_stack return le nombre de mouvement a faire pour medium_move
		lib_b = pb(lib_a, lib_b, print_state, bench);//voir tete de la fonction
		pre_organiser (lib_b, print_state, bench, j);
		}
		//recommence jusqu a avoir fait chunk fois l action pb
		//fin du while
		//change chunk et n--
		chunk = chunk * ++i;
		j = 0;
	}
		while(j < chunk && lib_b -> begin != NULL) //le retour de B vers A
		{
		medium_move(medium_search(lib_b, j), lib_a, lib_b); //vas chercher j, donner les instruction et le lancer vers A --->>> verifier les < et <= de partout
		lib_a = pa(lib_a, lib_b, print_state, bench);
		j++;
		}
	return();
}


printf("disorder is : %d.%d", disorder, (disorder * 100) % 100)