#include <unistd.h>

int search_stack()
{
	return()
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
    t_stack *p_start;
    t_stack *p_end;

    chunk = square_root(lib_a -> length);
    i = 1;
    while(lib_a -> start != NULL)
    {
		//double chercheur debut/fin pour trouver le plus proche (faire partir le fin du debut pour garder le compte des mouvements) parmis les < chunk
        //mouvement puis push b
		move_stack(search_stack()); //searche_stack return le nombre de mouvement a faire pour move_stack
        //recommence jusqu a avoir fait chunk pb
        //fin du while
        //change chunk et n--

        chunk = chunk * ++i;
    }






    return();
}


//a-t-on qlqch qui prend la taille totale de la stack?
//je vais initialiser la valeur n pour representer la taille totale