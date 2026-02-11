#include <stdlib.h>

int duplicate_detector(t_stack *start)
{
	t_stack *marker;
	t_stack *searcher;
	
	marker = start;
	searcher = marker -> next;
	while(marker != NULL)
	{
		while(searcher != NULL)
		{
			if (searcher -> content == marker -> content)
				return(1);
			searcher = searcher -> next;
		}
		marker = marker -> next;
		searcher = marker -> next;
	}
	return(0);
}
