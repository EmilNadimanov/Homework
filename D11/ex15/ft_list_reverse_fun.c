#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/*
• Create the function ft_list_reverse_fun which reverses the order of the elements
of the list. You may only use pointers related stuff.
*/

void	 		switch_flow(t_list *node)
{
	if (!node->next)
		return;
	switch_flow(node->next);
	node->next->next = node;
	
}

void			ft_list_reverse_fun(t_list *begin_list)
{
	void		*data;
	t_list		*last;
	
	if (!begin_list || !begin_list->next)
		return;
	last = begin_list;
	while (last->next)
		last = last->next;
	switch_flow(begin_list->next);
	begin_list->next->next = NULL;
	begin_list->next = last;
	while (begin_list->next)
	{
		data = begin_list->data;
		begin_list->data = begin_list->next->data;
		begin_list->next->data = data;
		begin_list = begin_list->next;
	}
}
