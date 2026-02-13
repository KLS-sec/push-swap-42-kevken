#include <unistd.h>

int search_stack(t_stack_library *lib_a, int chunk)
{
	t_stack *start;
	t_stack *end;
	int i;

	start = lib_a -> begin;
	end = lib_a -> end;
	i = 1;
	if(start -> order <= chunk)
		return (0);
	start = start->next;

	while()
	{

		i++;
	}
if b then i * -1

	return(i);
}

void move_stack()
{

}

int square_root(int n)
{
	int i;

	i = 1;
	while(((i+1)*(i+1)) <= n)
		i++;
	return(i);
}

int medium_algorythm(t_stack_library *lib_a, t_stack_library *lib_b)
{
	int chunk;
	int i;
	int j;


	chunk = square_root(lib_a -> length);
	i = 1;
	j = 0;
	while(lib_a -> start != NULL)
	{
		while(j < (chunk/i) && lib_a -> start != NULL)
		{
		//double chercheur debut/fin pour trouver le plus proche (faire partir le fin du debut pour garder le compte des mouvements) parmis les < chunk
		//mouvement puis push b
		move_stack(search_stack(lib_a, chunk)); //searche_stack return le nombre de mouvement a faire pour move_stack
		pb;//voir tete de la fonction
		j++;
		}
		//recommence jusqu a avoir fait chunk fois l action pb
		//fin du while
		//change chunk et n--

		chunk = chunk * ++i;
		j = 0;
	}

		while(j < chunk && lib_b -> start != NULL) //le retour de B vers A
		{
		move_stack(search_stack(lib_b, j)); //vas chercher j, donner les instruction et le lancer vers A --->>> verifier les < et <= de partout
		pa;
		j++;
		}

	return();
}


//a-t-on qlqch qui prend la taille totale de la stack?
//je vais initialiser la valeur n pour representer la taille totale