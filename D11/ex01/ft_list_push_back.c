#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>

/*
• Create the function ft_list_push_back which adds a new element of t_list type
at the end of the list.
• It should assign data to the given argument.
• If necessary, it’ll update the pointer at the beginning of the list.
*/

t_list *ft_create_elem(void *data)
{
	t_list *tail_node;
	tail_node = malloc(sizeof(t_list));
	if (tail_node)
	{
		tail_node->data = data;
		tail_node->next = NULL;
	}
	return tail_node;
}

void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *node;

	node = *begin_list;
	if (!node)
		node == ft_create_elem(data);
	else
	{
		while(node->next)
			node = node->next;
		node->next = ft_create_elem(data)
	}
}
