#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
• Create the function ft_list_reverse which reverses the order of a list’s elements.
You may only use pointers related stuff.
*/

void			ft_list_reverse(t_list **begin_list)
{
	t_list		*a;
	t_list		*b;

	if (!*begin_list || !begin_list)
		return;
	b = NULL;
	while(a)
	{
		a = (*begin_list)->next;
		(*begin_list)->next = b;
		b = *begin_list;
		*begin_list = a;
	}
	*begin_list = b;
}
