#include <unistd.h>

int dup_detection (t_stack starter)
{
    t_stack *target;
    t_stack *searcher;

    if (!starter)
        return; //un code erreur?****

    target = starter;
    searcher = target -> next;
    
    while(searcher != NULL)
    {
        while(searcher != NULL)
        {
            if (searcher -> content == target -> content)
                return (1) //verifier le code erreur****
            searcher = searcher ->next;
        }
        target = target -> next;
        searcher = target ->next;
    }

    return(0);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*nav;

	if (!lst || !f)
		return ;
	nav = lst;
	while (nav != NULL)
	{
		f(nav -> content);
		nav = nav -> next;
	}
}