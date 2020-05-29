#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>

/*
Create the function ft_list_size which returns the number of elements in the
list.
*/

int			ft_list_size(t_list *begin_list)
{
	int		count;

	if (!begin_list)
		return 0;	
	count = 1;
	while (begin_list->next)
	{
		begin_list = begin_list->next;
		count++;
	}
	return count;
}
