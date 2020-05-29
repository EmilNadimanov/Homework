#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>

/*
• Create the function ft_list_push_front which adds a new element of type t_list
to the beginning of the list.
• It should assign data to the given argument.
• If necessary, it’ll update the pointer at the beginning of the list.
*/

t_list			*ft_create_elem(void *data);

void			ft_list_push_front(t_list **begin_list, void *data)
{
	t_list		*node;
	
	if (!begin_list)
		return;
	if (!*begin_list)
		*begin_list = ft_create_elem(data);
	else
	{
		node = *begin_list;
		*begin_list = ft_create_elem(data);
		(*begin_list)->next = node;
	}
}
