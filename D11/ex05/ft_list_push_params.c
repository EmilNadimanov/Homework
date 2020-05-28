#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>

/*
• Create the function ft_list_push_params which creates a new list that includes
command-line arguments.
• The first argument should be at the end of the list.
• The first link’s address in the list is returned.
*/

t_list			*ft_create_elem(void *data)
{
	t_list		*tail_node;
	tail_node = malloc(sizeof(t_list));
	if (tail_node)
	{
		tail_node->data = data;
		tail_node->next = NULL;
	}
	return tail_node;
}

t_list *ft_list_push_params(int ac, char **av)
{
	t_list *node;
	t_list *tmp;
	int i;

	i = 0;
	node = ft_create_elem(av[i]);
	while (++i < ac)
	{
		tmp = node;
		node = ft_create_elem(av[i]);
		node->next = tmp;
	}
	return node;
}
