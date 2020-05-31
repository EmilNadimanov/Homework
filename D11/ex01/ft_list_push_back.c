#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>

/*
• Create the function ft_list_push_back which adds a new element of t_list type
at the end of the list.
• It should assign data to the given argument.
• If necessary, it’ll update the pointer at the beginning of the list.
*/

t_list			*ft_create_elem(void *data);

void			ft_list_push_back(t_list **begin_list, void *data)
{
	t_list		*node;

	if (!begin_list)
		return;
	if (!(*begin_list))
		*begin_list = ft_create_elem(data);
	else
	{
		node = *begin_list;
		while(node->next)
			node = node->next;
		node->next = ft_create_elem(data);
	}
}
