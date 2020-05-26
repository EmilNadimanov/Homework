#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>

/*
• Create the function ft_create_elem which creates a new element of t_list type.
• It should assign data to the given argument and next to NULL.
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
