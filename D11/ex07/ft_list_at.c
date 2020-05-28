#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>

/*
• Create the function ft_list_at which returns the Nth element of the list.
• In case of error, it should return a null pointer.
*/

t_list			*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	if (!begin_list || !*begin_list || nbr == 0)
		return NULL;
	while(--nbr)
		begin_list = begin_list->next;
	return begin_list;
}
