#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/*
• Create the function ft_list_remove_if which erases off the list all elements, whose
data is "equal" to the reference data.
*/
//TEST TEST TEST TEST TEST
void			ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list		*after;
	t_list		*current;

	if (!*begin_list || !begin_list)
		return;
	while (!cmp((*begin_list)->data, data_ref))
	{	
		after = (*begin_list)->next;
		free(*begin_list);
		*begin_list = after;
		if (!*begin_list)
			return;
	}
	current = *begin_list;
	while (current && current->next)
	{
		after = current->next;
		if (!cmp(after->data, data_ref))
		{
			current->next = after->next;
			free(after);
		}
		else
			current = current->next;
	}
}