#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>
/*
• Create the function ft_list_foreach which applies a function given as argument
to the information within each of the list’s links.
• The function pointed by f will be used as follows :
(*f)(list_ptr->data);
*/

void			ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if (!begin_list)
		return;
	while (begin_list)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}
