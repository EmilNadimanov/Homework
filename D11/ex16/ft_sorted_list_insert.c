#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
/*
• Create the function ft_sorted_list_insert which creates a new element and
inserts it into a list sorted so that it remains sortend in ascending order.
*/

t_list			*ft_create_elem(void *data);

void			ft_sorted_list_insert(t_list **begin_list, void *data,
									  int (*cmp)())
{
	t_list		*insert;
	t_list		*node;

	if (!begin_list || !*begin_list)
		return;
	insert = ft_create_elem(data);
	insert->next = *begin_list;
	if (cmp((*begin_list)->data, data) > 0)
		*begin_list = insert;
	else
	{
		node = *begin_list;
		while(node->next)
		{
			if(cmp(node->next->data, data) > 0)
			{
				insert->next = node->next;
				node->next = insert;
				return;
			}
			node = node->next;
		}
		insert->next = NULL;
		node->next = insert;
	}
}
