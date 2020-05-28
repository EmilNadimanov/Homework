#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>

/*
Create the function ft_list_last which returns the last element of the list.
*/

t_list			*ft_list_last(t_list *begin_list)
{
	t_list		*node;

	if (!begin_list)
		return NULL;
	node = begin_list;
	while (node->next)
	{
		node = node->next;
	}
	return node;
}
